//-----------------------------------------------------------------------
//  File: spy.cc
//  Description: Spy Escape Route
//  Author: Dave Mount (mount@cs.umd.edu)
//
//  This program finds a path in a grid, from the lower-left to
//  upper-right corners, subject to the constraint that the path not
//  pass through certain given obstacles, and that it not travel
//  straight through any intersection.
//
//  This is implemented by creating a directed graph, in which the
//  each vertex is identified with an intersection point on the grid
//  and an entry direction (N, S, E, W).  Based on the entry
//  direction, we create edges to the appropriate adjacent grid
//  points.  Then we compute a path using breadth-first search.
//  (This way we actually get the shortest path.)
//-----------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <assert.h>
using namespace std;

//-----------------------------------------------------------------------
//  Globals
//-----------------------------------------------------------------------

enum COORD {X = 0, Y = 1};
enum DIREC {NORTH = 0, SOUTH, EAST, WEST, N_DIREC};

typedef int Point[2];                           // point is (x,y) pair

char direcName[N_DIREC] = {'v', '^', '<', '>'};	// entry symbols
                                                // (for debug output)

//-----------------------------------------------------------------------
// Vertex
//     A vertex is a grid intersection point (x,y) and an entry
//     direction (entry).  We also maintain some values used in
//     path computation.
//
//     Beware: The next pointer is used by both findPath and outputPath
//     for different purposes.
//-----------------------------------------------------------------------
struct Vertex {                                 // vertex in the graph
    int x, y;                                   // coordinates
    DIREC entry;                                // entry direction
    Vertex *pred;                               // path predecessor
    Vertex *next;                               // next (in queue)
    bool mark;                                  // marked

    void init(int xx, int yy, DIREC e)          // initialize
    {
    	x = xx;  y = yy;  entry = e;
	pred = next = NULL;
	mark = false;
    }

    Vertex(int xx = 0, int yy = 0, DIREC e = N_DIREC) { init(xx, yy, e); }

    bool coordEqual(Vertex &v)                  // same coordinates?
    {  return (v.x == x && v.y == y); }
};

typedef Vertex	*VPtr;                          // vertex pointers

ostream &operator<<(ostream &o, Vertex *v)      // output vertex
{
     if (v == NULL) o << "NULL";
     else {o << "[" << v->x << ", " << v->y << "]" << direcName[v->entry]; }
     return o;
}

//-----------------------------------------------------------------------
//  Vertex Queue (for BFS)
//      This is a FIFO queue threaded through the set of vertices.
//      This is implemented as a linked list.
//-----------------------------------------------------------------------
struct VQueue {					// vertex queue
    VPtr	head;				// head of queue
    VPtr	tail;				// tail of queue

    VQueue()					// construct empty
    {  head = tail = NULL;  }

    bool isEmpty()				// is it empty?
    {  return head == NULL;  }

    void enqueue(Vertex &v)			// enqueue
    {	
    	v.next = NULL;
    	if (tail == NULL) { head = tail = &v; }
	else { tail->next = &v;  tail = &v;  }
    }

    VPtr dequeue()				// dequeue
    {
    	assert(!isEmpty());
	Vertex *v = head;
	head = head->next;
	if (head == NULL) tail = NULL;
	return v;
    }
};

//-----------------------------------------------------------------------
//  GridGraph
//      A grid graph consists of a grid of the given dimensions
//      (wid,hgt), a set of obstacles (implemented as a 2-dimensional
//      array of booleans), and a set of vertices (implemented as a
//      3-dimensional array of vertices).
//
//      The procedure index maps a 2 or 3 element tuple (x,y,direc) into
//      a index into these arrays.  When two arguments are given, it is
//      assumed that the third argument (direc) is zero.
//
//      We do not explicitly store edges.  These are determined in the
//      findPath procedure.
//-----------------------------------------------------------------------
struct GridGraph {				// grid graph
    int		wid, hgt;			// width and height
    bool	*obstArray;			// array of obstacles
    Vertex	*vertArray;			// the vertices
//
    void init();				// clear obstacles

    GridGraph(int w, int h) {			// constructor
    	wid = w;  hgt = h;
	obstArray = new bool[(wid+1)*(hgt+1)];
	vertArray = new Vertex[(wid+1)*(hgt+1)*N_DIREC];
	init();
    }

    int index(int x, int y, int direc = 0)	// return an index
    {
    	assert(x >= 0 && x <= wid);
	assert(y >= 0 && y <= hgt);
	assert(direc >= 0 && direc < N_DIREC);
    	return (direc*(wid+1) + x)*(hgt+1) + y;
    }

    void readObst(istream &in);			// read obstacles

    VPtr findPath(VPtr start, VPtr end);	// find path
    void outputPath(VPtr end, ostream &out);	// output path

    void dump(ostream &out);			// dump graph (debugging)
};

void GridGraph::init()				// initialize everything
{
    for (int x = 0; x <= wid; x++) {
        for (int y = 0; y <= hgt; y++) {
	    obstArray[index(x, y)] = false;
            for (int entry = NORTH; entry < N_DIREC; entry++) {
                vertArray[index(x, y, entry)].init(x, y, (DIREC) entry);
            }
        }
    }
}

void GridGraph::readObst(istream &in)		// read obstacles
{
    while (true) {
        int x, y;
        in >> x;
        if (x == -1) break;
        in >> y;
        obstArray[index(x, y)] = true;
    }
    // cout << "Initial graph" << endl;
    // dump(cout);
}

//-----------------------------------------------------------------------
//  findPath - computes the (shortest) path from start to end
//      This is an implementation of breadth-first search.  Starting
//      with the start vertex, it puts each vertex it sees on a FIFO
//      queue, indicates the vertex's predecessor, and marks it (so that
//      we do not revisit vertices).  When we first come to an end
//      vertex we terminate.
//
//      This routine determines neighbors in the grid graph.  For
//      example, to test for a neighbor to the north, we first check
//      that we did not enter from the south (v->entry != SOUTH), that
//      we are not at the top of the grid (v->y < hgt), and that the
//      entry immediately north is not an obstacle (!obst[v->x,
//      v->y+1]).  If so, the vertex at (v->x, v->y+1, SOUTH) is the
//      desired vertex.
//-----------------------------------------------------------------------
VPtr GridGraph::findPath(VPtr start, VPtr end)
{
                                                // starting vertex illegal?
    if (obstArray[index(start->x, start->y)]) return NULL;

    start->pred = NULL;	                        // start path at start
    start->mark = true;

    VQueue Q;                                   // queue
    Q.enqueue(*start);                          // enqueue start
    // cout << "Initial graph" << endl;
    // dump(cout);				// dump graph (debugging)
    while (!Q.isEmpty()) {
    	VPtr v = Q.dequeue();                   // dequeue next vertex
	if (v->coordEqual(*end)) return v;      // if end vertex then done

                                                // adjacent to NORTH
	if (v->entry != SOUTH && v->y < hgt && !obstArray[index(v->x,v->y+1)]) {
	    Vertex &u = vertArray[index(v->x, v->y+1, SOUTH)];
	    if (!u.mark) { u.mark = true; u.pred = v; Q.enqueue(u); }
	}
                                                // adjacent to SOUTH
	if (v->entry != NORTH && v->y > 0 && !obstArray[index(v->x,v->y-1)]) {
	    Vertex &u = vertArray[index(v->x, v->y-1, NORTH)];
	    if (!u.mark) { u.mark = true; u.pred = v; Q.enqueue(u); }
	}
                                                // adjacent to EAST
	if (v->entry != WEST && v->x < wid && !obstArray[index(v->x+1,v->y)]) {
	    Vertex &u = vertArray[index(v->x+1, v->y, WEST)];
	    if (!u.mark) { u.mark = true; u.pred = v; Q.enqueue(u); }
	}
                                                // adjacent to WEST
	if (v->entry != EAST && v->x > 0 && !obstArray[index(v->x-1, v->y)]) {
	    Vertex &u = vertArray[index(v->x-1, v->y, EAST)];
	    if (!u.mark) { u.mark = true; u.pred = v; Q.enqueue(u); }
	}
	// cout << "After processing " << v << endl;
	// dump(cout);				// dump graph (debugging)
    }
    return NULL;				// no path
}

//-----------------------------------------------------------------------
//  outputPath - output path
//      This procedure follows the pred points back from a given vertex
//      until arriving at a vertex with no predecessor.  It then prints
//      the vertices out in reverse order.  We kludge this by threading
//      the path using the next pointers inside the vertices.
//-----------------------------------------------------------------------
void GridGraph::outputPath(VPtr end, ostream &out)
{
    VPtr pathHead = end;
    end->next = NULL;
    int pathLength = 1;
    while (pathHead->pred != NULL) {
        VPtr v = pathHead->pred;
        v->next = pathHead;
        pathHead = v;
        pathLength++;
    }
    out << "path" << endl;
    while (pathHead != NULL) {
        out << pathHead->x << " " << pathHead->y << endl;
        pathHead = pathHead->next;
    }
}

void GridGraph::dump(ostream &out)		// dump graph (debugging)
{
    for (int x = 0; x <= wid; x++) {
        for (int y = 0; y <= hgt; y++) {
	    out << "[" << x << "," << y << "]";
            if (obstArray[index(x,y)]) {
                out << ": obstacle" << endl;
            }
	    else {
                out << endl;
		for (int entry = NORTH; entry < N_DIREC; entry++) {
                    Vertex &v = vertArray[index(x, y, (DIREC) entry)];
                    assert(v.x == x);
                    assert(v.y == y);
                    assert(v.entry == entry);
                    out << "    " << direcName[entry] << ": ";
                    if (v.mark) out << "*"; 
                    else out << " ";
                    out << " P=" << v.pred;
                    out << " N=" << v.next;
                    out << endl;
                }
            }
        }
    }
}

//-----------------------------------------------------------------------
//  main
//      The main procedure initializes the graph, reads the obstacles,
//      initializes the starting vertex, finds the path, and outputs the
//      path.  The entry direction to the start vertex is set to NORTH.
//      This ONLY works because this is the lower-left vertex (and hence
//      it is impossible to got south).  The direction of the end
//      vertex is entirely arbitrary, because the path termination is
//      based on coordinates only.
//-----------------------------------------------------------------------
int main()
{
    int w, h;
    cin >> w >> h;                              // input width and height
    GridGraph *graph = new GridGraph(w, h);     // allocate graph
    graph->readObst(cin);                       // read obstacles
                                                // starting vertex
    VPtr start = &graph->vertArray[graph->index(0, 0, NORTH)];
                                                // end (direction ignored)
    VPtr end = &graph->vertArray[graph->index(w, h, NORTH)];
    VPtr e = graph->findPath(start, end);       // get shortest path
    if (e == NULL) {                            // no path?
        cout << "no-path\n";
    }
    else {
        graph->outputPath(e, cout);             // else output path
    }
    return 0;
}
