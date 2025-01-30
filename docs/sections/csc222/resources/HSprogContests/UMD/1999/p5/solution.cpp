#include <iostream>
#include <stdio>
using namespace std;

// Uncomment the following lines if using APCS classes
#include "apvector.h"
#include "apmatrix.h"
#include "apstack.h"
// #include "apqueue.h"
// #include "apstring.cpp"


bool Ham(int num, 
         apmatrix<bool> &adj, 
         apstack<int> &seats, 
         apvector<bool> &marked)
{
    int i, j = seats.top();

    if (num == seats.length() && adj[j][0]) {
        return true;
    }

    for (i=1; i<num; i++) {
        if (!marked[i] && adj[j][i]) {
            marked[i] = true;
            seats.push(i);
            if (Ham(num, adj, seats, marked))
                return true;
            else {
                seats.pop();
                marked[i] = false;
            }
        }
    }
    return false;
}

int main()
{
    int num;            // number of diplomats to be seated
    int i,x,y;

    // read in problem description

    cin >> num;
    apmatrix<bool> adj(num,num,true); // who's allowed to be adjacent

 
    for (i=0; i<num; i++)  // can't sit next to oneself
        adj[i][i] = false;

    while (true) {
        cin >> x;
        if (x == -1)
            break;
        cin >> y;
        adj[x-1][y-1] = false; // can't sit next to each other
        adj[y-1][x-1] = false;
    }

    // find seating

    apstack<int> seats;               // seats for diplomats
    apvector<bool> marked(num,false); // which nodes visited

    seats.push(0);
    if (Ham(num, adj, seats, marked)) {
        while (!seats.isEmpty()) {
            seats.pop(x);
            cout << x+1 << " ";
        }
        cout << "\n";
    }
    else {
        cout << "0" << "\n";
    }

    return 0;
}
