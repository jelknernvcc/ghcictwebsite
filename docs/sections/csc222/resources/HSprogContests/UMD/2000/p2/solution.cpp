//-----------------------------------------------------------------------
//    File:        cipher.cc
//    Description:    Encode text using modified caesar cipher
//    Author:        Chau-Wen Tseng (tseng@cs.umd.edu)
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
    char code[100];  // max string is 100 chars
    int i,len,klen;
    unsigned int c;

    cin >> key;
    klen = key.length();

    cin >> buf;
    while (buf != "-1") {  // look at each string

        len = buf.length();
        for (i = 0; i < len; i++) {
            c = (unsigned int) (buf[i] + key[i%klen] - 'a');
            if (c > (unsigned int) 'z')
                c -= 26;  // 26 letters
            code[i] = (char) c;
        }
        assert(i < 100);
        code[i] = '\0';
        cout << code << "\n";
        cin >> buf;
    }
}
