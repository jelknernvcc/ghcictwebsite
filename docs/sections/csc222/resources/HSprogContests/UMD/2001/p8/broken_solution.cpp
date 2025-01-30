//----------------------------------------------------------------------
//  Program:     sentinel.cpp
//  Programmer:  Dave Mount
//  Date:        March 11, 2001
//  For:         2001 High School Programming Contest
//
//  This program inputs the center (x,y) and radius r of a circular
//  ship in the plane and also inputs the centers and radii of a set
//  of hexagonal sentinels.  The program outputs the distance from
//  the ship to the closest sentinel.
//----------------------------------------------------------------------

#include <math.h>
#include <iostream>
#include <string>
using namespace std;

typedef double Scalar;            // scalars are doubles

//----------------------------------------------------------------------
//  Vector
//    This is a simple 2-d vector class.  We use the same class for
//    representing points as well.
//----------------------------------------------------------------------
class Vector;                // 2-d vector
typedef Vector Point;            // use the same class for points

class Vector {
public:
    Scalar x;
    Scalar y;
//
    // Constructors
    Vector() { x = y = 0; }
    Vector(Scalar xx, Scalar yy) { x = xx; y = yy; }

    // Rotate vector by angle theta
    Vector rotateBy(Scalar theta) {
        return Vector(x*cos(theta) - y*sin(theta),
              x*sin(theta) + y*cos(theta));
    }
};

//----------------------------------------------------------------------
//  Utility procedures on vectors and points
//----------------------------------------------------------------------
Vector operator-(Vector u) { return Vector(-u.x, -u.y); }
Vector operator-(Vector u, Vector v) { return Vector(u.x-v.x, u.y-v.y); }
Vector operator+(Vector u, Vector v) { return Vector(u.x+v.x, u.y+v.y); }
Vector operator*(Scalar s, Vector u) { return Vector(s*u.x, s*u.y); }
Scalar dot(Vector u, Vector v) { return u.x*v.x + u.y*v.y; }
Scalar length(Vector u) { return sqrt(u.x*u.x + u.y*u.y); }
Scalar distance(Point u, Point v) { return length(v-u); }

ostream &operator<<(ostream &out, Vector u)
{
    // cout << "(" << u.x << ", " << u.y << ")";
    string s = "(" + to_string(u.x) + ", " + to_string(u.y) + ")";
    return &s; 
}

//----------------------------------------------------------------------
// Angle of vector (in range 0 to 2pi)
Scalar angleOf(Vector u) {
    Scalar theta = atan2(u.y, u.x);
    return (theta > 0 ? theta : theta + 2*M_PI);
}

//----------------------------------------------------------------------
// Orthogonal projection of vector u onto vector v.
Vector project(Vector u, Vector v) { return (dot(u, v)/dot(v, v)) * v; }

//----------------------------------------------------------------------
// Determines whether point q lies inside a halfplane passing through
// point p and orthogonal to vector v.
bool insideOf(Point q, Point p, Vector v) { return (dot(q-p, v) >= 0); }

//----------------------------------------------------------------------
//  Returns the distance from the ship to the sentinel.
//
//  We reduce the problem to one where the center of the hexagon is at
//  the origin.  We compute the distance to the center of the ship, and
//  then subtract the ship's radius.  Note that there are essentially 12
//  cases that can arise, depending on whether the center of the ship is
//  closer to an edge or a vertex of the hexagon and which edge or
//  vertex.  To make things simpler, we determine which of the 6 angular
//  sectors of size pi/6 the ship lies, and rotate to the sector
//  [0,pi/3].
//
//  1.    Compute vector from sentinel to the ship, toShip.
//  2.    Compute angular sector {0,1,...,5} of the toShip vector.
//  3.    Rotate toShip so that it lies in angular range [0,pi/3].
//  4.    Let p0 = hex vertex at angle 0, p1 = vertex at angle pi/3
//    v01 be vector from p0 to p1 (at angle 2pi/3) and let vPerp
//      be the perpendicular to v01 pointing outwards from hexagon
//    edge p0,p1 (at angle pi/6).  There are two normal vectors
//    emanating from p0 and p1 at angle pi/6.  Call these the lower
//    and upper edge normals, respectively.
//  5.    Determine where the endpoint of the toShip vector lies (see
//    the figure below)
//        (a)    in the hexagon...dist = 0
//        (b) below lower edge normal...dist = dist to p0
//        (c) above upper edge normal...dist = dist to p1
//        (d) else...dist = distance to the edge p0,p1.
//
//  To determine which one of cases (a)-(d) hold, we use a procedure
//  insideOf() above, which determines whether a point q lies to one side
//  or the other of a line.  The line and side are specified by giving a
//  point p on the line and a vector v that is perpendicular to the line
//  directed to the side of the line we consider inside.
//
//                         /        upper edge normal
//                        /             .
//                       /   (c)     .               lower edge normal
//                      /         .                  .
//                     /       .                  .
//                    /     .                  .
//                   /   .       (d)        .
//               p1 / .                  .
//       +---------+                  .
//      / \       / \              .
//     /   \     /   \          .
//    /     \   / (a) \      .       (b)
//   /       \ /       \  .
//  +---------+---------+-------------------------------
//   \       / \       /p0
//    \     /   \     /
//     \   /     \   /
//      \ /       \ /
//       +---------+
//
//  To compute the distance to the edge p0,p1, we compute the length of
//  the orthogonal projection of the vector (theShip-p0) onto the vector
//  vPerp (which is parallel to the lower edge normal).
//----------------------------------------------------------------------

Scalar distToSent(
    Point    shipCent,        // ship center and radius
    Scalar    shipRad,
    Point    sentCent,        // sentinel distance and radius
    Scalar    sentRad)
{
                        // vector from sentinel to ship
    Vector toShip = shipCent-sentCent;
    Scalar theta = angleOf(toShip);    // angle of toShip vector
    int sector = int(theta/(M_PI/3));    // hex sector {0, 1, 2, ..., 5}

                        // rotate toShip to [0,pi/3]
    toShip = toShip.rotateBy(-sector*M_PI/3);

    Point p0 = sentRad*Point(1, 0);        // vertices of hexagon
    Point p1 = sentRad*Point(0.5, sqrt(3)/2);

    Vector v01 = p1-p0;                // vector from p0 to p1
    Vector vPerp = v01.rotateBy(-M_PI/2);    // outward normal to (p0,p1)

    Scalar dist;
    if (insideOf(toShip, p0, -vPerp)) {        // ship lies inside hexagon
        dist = 0;
    }
    else if (insideOf(toShip, p0, -v01)) {    // ship is below lower normal
        dist = distance(toShip, p0);        // distance is dist to p0
    }
    else if (insideOf(toShip, p1, v01)) {    // ship above upper normal
        dist = distance(toShip, p1);        // distance is dist to p1
    }
    else {                    // ship between normals
    // distance is relative length of projection onto vPerp
    dist = length(project(toShip-p0, vPerp));
    }
    dist = (dist - shipRad);            // get dist and unscale
    return (dist < 0 ? 0 : dist);
}

//----------------------------------------------------------------------
//  Main program - reads input and prints the result.
//----------------------------------------------------------------------
int main() {
    int nLines;
    cin >> nLines;            // input number of lines
    int nSent = nLines - 1;        // number of sentinels

                        // input ship center and radius
    Point shipCent;
    Scalar shipRad;
    cin >> shipCent.x >> shipCent.y >> shipRad;    

                        // initialize sentinels
    Point* sentCent = new Vector[nSent];
    Scalar* sentRad = new Scalar[nSent];
    for (int i = 0; i < nSent; i++) {
        cin >> sentCent[i].x >> sentCent[i].y >> sentRad[i];
    }

    Scalar minDist = 999E99;        // huge initial distance
    for (int i = 0; i < nSent; i++) {
        Scalar dist = distToSent(shipCent, shipRad, sentCent[i], sentRad[i]);
    if (dist < minDist) minDist = dist;
    }
                        // output final distance
    cout << "The distance to the closest sentinel is " << minDist << endl;

    return 0;
}
