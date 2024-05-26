/*
  File: stdiff.cc
  Author: Sudarshan S. Chawathe <chaw@cs.umd.edu>
  Date: 10th March, 1999
  Compile using: gcc -Wall -o stdiff stdiff.cc -lm
  Terms: GPL

  For the Maryland Programming Contest, 1999.
  For algorithmic details, see Info. Proc. Lett. 6(6):184-186, 1977.

  stdiff: An implementation of Selkow's tree differencing algorithm
  Copyright (C) 1999 Sudarshan S. Chawathe

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.
     
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
     
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <cstring>
using namespace std;

int max_depth = 64;
int depth_incr = 64;
int debug = 0;
int nid = 0;

class Node {
public:
  Node(double il, Node * ilmc, Node * irs, double ici) :
    l(il), lmc(ilmc), rs(irs), cid(ici), stsize(0) { id = ++nid;}    
  double l; /* label */
  Node * lmc; /* leftmost child */
  Node * rs; /* right sibling */
  double cid; /* cost of insertion or deletion */
  double ccid; /* cumulative cost of insertion or deletion */
  int stsize; /* size of subtree rooted at this node */
  int id;
};

Node * 
read_tree()
  /* returns a tree in the depth-label-cost line format read from stdin */
{
  Node * * p = (Node **) malloc(sizeof(Node*)*(max_depth+1)); 
  /* p[i] is the "current parent" at depth i */
  p[0] = 0;
  int depth;
  double lab, cid;
  scanf("%d %lf %lf", &depth, &lab, &cid);
  while(depth >= 0) {
    Node * n = new Node(lab,0,0,cid);
    if(depth > max_depth) {
      max_depth += depth_incr;
      realloc(p, (max_depth+1)*sizeof(Node *));
    }
    if(depth == 0) p[0] = n;
    else {
      p[depth] = n;
      Node * parent = p[depth-1]; 
      Node * lsib = parent->lmc; 
      if(lsib == 0) parent->lmc = n;
      else {
	while(lsib->rs != 0) lsib = lsib->rs; 
	lsib->rs = n;
      }
    }
    scanf("%d %lf %lf", &depth, &lab, &cid);
  }
  Node * ans = p[0];
  delete p;
  return ans;
}

void
write_tree_aux(Node * t, int depth)
  /* helper for write_tree */
{
  if(debug) printf("%3d %3d", t->id, depth);
  for(int i = 0; i < depth; i++) printf("    ");
  printf("%5.2f %5.2f\n", t->l, t->cid);
  for(Node * c = t->lmc; c != 0; c = c->rs) 
    write_tree_aux(c, depth+1);
}

void
write_tree(Node * t)
  /* writes the subtree rooted at t to stdout */
{
  write_tree_aux(t, 0);
}

double
ccid(Node * t)
  /* computes and returns the ccid member for subtree(t) */
{
  t->ccid = t->cid;
  for(Node * c = t->lmc; c; c = c->rs)
    t->ccid += ccid(c);
  return t->ccid;
}

double
upd(Node * a, Node * b)
  /* returns cost of updating a's label to b's label */
{
  return fabs(a->l - b->l);
}

double
min(double x, double y, double z)
  /* returns minimum of x, y, and z */
{
  if(x <= y) if(x <= z) return x; else return z;
  else if(y <= z) return y; else return z;
}

int
num_children(Node * n)
  /* returns the number of children of n */
{
  int ans = 0;
  for(Node * c = n->lmc; c; c = c->rs) ans++;
  return ans;
}

double
dist(Node * a, Node * b)
  /* returns the edit distance between trees rooted at a and b */ 
{
  if(debug) printf("dist(%d,%d)=?\n", a->id, b->id);
  (void)ccid(a);
  (void)ccid(b);
  int m = num_children(a), n = num_children(b);
  double * d = (double *) malloc(sizeof(double)*(m+1)*(n+1));
#define D(x,y) d[(n+1)*(x)+(y)]
  D(0,0) = upd(a,b);
  Node * cx, * cy;
  int i,j;
  for(cy = b->lmc, j=1; cy; cy = cy->rs, j++)
    D(0,j) = D(0,j-1) + cy->ccid;
  for(cx = a->lmc, i=1; cx; cx = cx->rs, i++)
    D(i,0) = D(i-1,0) + cx->ccid;
  for(cx = a->lmc, i=1; cx; cx = cx->rs, i++) 
    for(cy = b->lmc, j=1; cy; cy = cy->rs, j++) 
      D(i,j) = min(D(i-1,j-1) + dist(cx,cy), 
		   D(i,j-1) + cy->ccid, D(i-1,j) + cx->ccid);
  double ans = D(m,n);
  delete d;
  if(debug) printf("dist(%d,%d)=%5.2f\n", a->id, b->id, ans);
  return ans;
}

int main(int argc, char * argv[])
{
  if(argc > 1 && strncmp(argv[1], "-d", 2) == 0) debug = 1;
  Node * a = read_tree();
  write_tree(a); printf("\n");
  Node * b = read_tree();
  write_tree(b); printf("\n");
  printf("Distance: %5.2f\n", dist(a,b));
  return 0;
}
