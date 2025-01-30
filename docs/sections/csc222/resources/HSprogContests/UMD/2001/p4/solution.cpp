//-----------------------------------------------------------------------
//  File:         crash.cc
//  Description:  Calculate Helicopter Crash
//  Author:       Chau-Wen Tseng (tseng@cs.umd.edu)
//-----------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <assert.h>
using namespace std;

//-----------------------------------------------------------------------
//  main
//-----------------------------------------------------------------------

const int HEIGHT = 7;
const int WIDTH = 5;

int main()
{
    int i,j,t;
    double pos[HEIGHT][WIDTH];
    double newpos[HEIGHT][WIDTH];

    for (i = 0; i<HEIGHT; i++)
    for (j = 0; j<WIDTH; j++)
        pos[i][j] = 0.0;

    int x_pos, y_pos, impact, time;
    double avg_pos;

    cin >> y_pos;
    cin >> x_pos;
    cin >> impact;
    cin >> time;

    pos[y_pos][x_pos] = impact;

    for (t = 0; t<time; t++) {
        cout << "Time " << t << endl;

        // print state of building surface
        for (i = 0; i<HEIGHT; i++) {
            for (j = 0; j<WIDTH; j++) {
                cout << (int) pos[i][j] << "\t";
            }
            cout << endl;
        }

        // calculate new position using finite-differencing
        for (i = 1; i<HEIGHT-1; i++) {
            for (j = 1; j<WIDTH-1; j++)  {
                newpos[i][j] = ((pos[i-1][j-1]+pos[i-1][j]+ 
                        pos[i-1][j+1]+pos[i][j-1]+ 
                        pos[i][j+1]+ pos[i+1][j+1]+
                        pos[i+1][j]+ pos[i+1][j-1]) /8.0 + 
                        pos[i][j]) /2.0 ;
            }
        }

        // update position
        for (i = 1; i<HEIGHT-1; i++)
            for (j = 1; j<WIDTH-1; j++)
                pos[i][j] = newpos[i][j]; 
    }

    return 0;
}
