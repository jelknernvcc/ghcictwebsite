//-----------------------------------------------------------------------
//  File:         zone.cc
//  Description:  Compute the zone containing a point
//  Author:       Dave Mount (mount@cs.umd.edu)
//
//  This program inputs a set of lines, called walls, each given by
//  a pair of coefficients, a,b, representing the line y = ax + b.
//  These walls partition the plane into regions, called zones.
//  Next the program inputs the x and y coordinates of a point (the
//  user) q, and outputs the sequence of line indices that define
//  the zone surrounding this point.
//
//  It may be assumed that the user q does not lie on any of the
//  walls, no two walls are parallel or collinear, and no three
//  walls intersect in the same point.
//-----------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <assert.h>
using namespace std;

//-----------------------------------------------------------------------
//  Wall and Point
//    A Wall is a line in the plane, y = ax + b, given by its line
//    coefficients a and b.  An Point is a point in the plane.  We
//    support the following operations:
//
//  p = intersect(w1, w2)            intersection point of w1 and w2
//  i = sideOf(p, w)                 on which side is p from w?
//                                   +1 above, 0 on, -1 below.
//-----------------------------------------------------------------------

class Wall;                                        // defined below

class Point {                                      // point in the plane
  double x, y;                                     // coordinates
public:
  Point(double xx = 0, double yy = 0) { x = xx;  y = yy; }
  // which side is point on 
  friend int sideOf(const Point &p, const Wall &w);
  friend ostream &operator<<(ostream &out, const Point &p);
};

class Wall {                                       // a line in the plane
  double a, b;                                     // line coefficients
public:
  Wall(double aa = 0, double bb = 0) { a = aa;  b = bb; }
                                                   // intersect walls
  friend Point intersect(const Wall &w1, const Wall &w2);
                                                   // which side is point on 
  friend int sideOf(const Point &p, const Wall &w);
  friend ostream &operator<<(ostream &out, const Wall &w);
};

//-----------------------------------------------------------------------
//  Functions for points and walls
//-----------------------------------------------------------------------

ostream &operator<<(ostream &out, const Point &p)  // output point
{
  return out << "(" << p.x << ", " << p.y << ")";
}

Point intersect(const Wall &w1, const Wall &w2)
{
  assert(w1.a != w2.a);                            // can't be parallel
  double x = (w2.b - w1.b)/(w1.a - w2.a);
  double y = w1.a * x + w1.b;
  return Point(x, y);
}

int sideOf(const Point &p, const Wall &w)
{
  double diff = p.y - (w.a * p.x + w.b);
                                                   // return sign
  return (diff < 0 ? -1 : (diff > 0 ? +1 : 0));
}

//-----------------------------------------------------------------------
//  main
//    The main procedure inputs the walls and the user.  The main
//    stages of the algorithm are as follows:
//
//  1. It initializes an array zone, where zone[i] is true if the
//     ith wall is part of the user's zone.  Initially all entries are
//     false.
//
//  2. For each wall it determines which side the user lies, and
//     stores the results in an array userSide.  A value +1 means
//     that the user is above the wall, and -1 means below.  (No
//     zeroes are possible by the assumption that the user is not lie
//     on any wall).
//
//  3. We generate all pairs of distinct wall indices j1 and j2, and
//     for each one we compute the intersection point of these two
//     walls.  A unique intersection point exists because of our
//     assumptions that no two lines are parallel or collinear.
//
//  4. For each such intersection point, we scan through all the
//     walls (other than j1 and j2) and determine whether the
//     intersection point lies on the same side of the wall as the
//     user does. If this it true, then both j1 and j2 are bounding
//     walls. (This relies on our assumption that no three walls pass
//     through a common point.)  We indicate this by setting zone[j1] =
//     zone[j2] = true.
//
//  5. Finally we ouput all the walls such that zone[i] is true.
//-----------------------------------------------------------------------

int main() {
  int i;
  int nWall;                                       // number of walls
  cin >> nWall;                                    // input number of walls
  Wall *wall = new Wall[nWall];                    // allocate wall array
  int *userSide = new int[nWall];                  // allocate sides array
  bool *zone = new bool[nWall];                    // allocate zones

  for (i = 0; i < nWall; i++) {                    // initialization
    double a, b;                                   // wall coefficients
    cin >> a >> b;                                 // input coefficients
    wall[i] = Wall(a, b);
  }

  double x, y;
  cin >> x >> y;                                   // input user coordiantes
  while (x != 999 && y != 999) {
    Point user = Point(x, y);                      // the user
    for (i = 0; i < nWall; i++) {
       zone[i] = false;                            // initialize zone
                                                   // which side is user?
       userSide[i] = sideOf(user, wall[i]);
    }
    if (nWall == 1) {                              // only one wall?
      zone[0] = true;                              // wall is always bounding
    }
    for (int j1 = 0; j1 < nWall; j1++) {           // test intersection points
      for (int j2 = j1+1; j2 < nWall; j2++) {
        Point joint = intersect(wall[j1], wall[j2]);
        bool bounding = true;                      // is intersection...
                                                   // ...on the zone?
        for (i = 0; i < nWall; i++) {
          if (i != j1 && i != j2 &&
          sideOf(joint, wall[i]) != userSide[i]) {
            bounding = false;
            break;
          }
        }
                                                   // yes, record this fact
        if (bounding) zone[j1] = zone[j2] = true;
      }
    }

    cout << "The zone for " << user << " is bounded by walls" << endl;
    for (i = 0; i < nWall; i++) {                  // output final zone walls
      if (zone[i]) cout << "  " << i << endl;
    }
    cin >> x >> y;                                 // input next user
  }

  delete [] wall;                                  // deallocate everything
  delete [] userSide;
  delete [] zone;

  return 0;
}
