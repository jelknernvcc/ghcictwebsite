//-----------------------------------------------------------------------
//  File:        jump.cc
//  Description: Calculate Neo's Leap
//  Author:      Chau-Wen Tseng (tseng@cs.umd.edu)
//-----------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <assert.h>
using namespace std;

//-----------------------------------------------------------------------
//  main
//-----------------------------------------------------------------------

int main()
{
    int x_speed, y_speed, distance;
    int time, x_pos, y_pos;

    cin >> x_speed;
    cin >> y_speed;
    cin >> distance;

    time = 0;
    x_pos = 0;
    y_pos = 0;

    while ((y_speed >= 0) || (y_pos > 0)) {
        x_pos += x_speed;
        y_pos += y_speed;
        y_speed -= 5;                             // decrease vertical speed
        cout << x_pos << " " << y_pos << endl; 
    } 

    if ((x_pos >= distance-3) && (x_pos <= distance+3))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
