//-----------------------------------------------------------------------
//  File:         secret.cc
//  Description:  Encode text using one-time pad
//  Author:       Chau-Wen Tseng (tseng@cs.umd.edu)
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
    int pad[100];                                 // max pad is 100 chars
    char code[100];                               // store encrypted string
    int i,len,padsize,padindex;
    unsigned int c;

    cin >> padsize;
    padindex = 0;

    for (i = 0; i<padsize; i++) {                 // read in pad
        cin >> pad[i];
        assert((pad[i] >= 0) && (pad[i] <= 25));
    }

    cin >> buf;
    while (buf != "-1") {                        // look at each string

        len = buf.length();
        for (i = 0; i < len; i++) {
                assert((buf[i] >= 'a') && (buf[i] <= 'z'));
            c = (unsigned int) (buf[i] + pad[padindex++]);
            if (c > (unsigned int) 'z')
                c -= 26;                         // 26 letters
            code[i] = (char) c;
        }

        assert(i < 100);
        code[i] = '\0';
        cout << code << endl;                    // print output
        cin >> buf;                              // get next string
    }

    return 0;
}
