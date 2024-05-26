//-----------------------------------------------------------------------
//    File:         search.cc
//    Description:  Find the number of occurrences of a keyword in line
//    Author:       Chau-Wen Tseng (tseng@cs.umd.edu)
//-----------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

//-----------------------------------------------------------------------
//  main
//-----------------------------------------------------------------------

int main()
{
    string key;
    string buf;
    int idx,match;

    cin >> key;
    match = 0;

    cin >> buf;
    while (buf != "-1") {  // look at each string
        idx = buf.find(key);
        while (idx != -1) {
            match++;
            buf = buf.substr(idx+1, buf.length()-(idx+1));
            idx = buf.find(key);
        }
        cin >> buf;
    }
    cout << "Found " << match << " " << key << "\n";
}
