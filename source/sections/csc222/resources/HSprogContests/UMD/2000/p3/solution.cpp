//-----------------------------------------------------------------------
//  File:         cache.cc
//  Description:  Implement LRU cache
//  Author:       Chau-Wen Tseng (tseng@cs.umd.edu)
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
    int cache[4];
    int hits, refs, page;

    cache[0] = 0;
    cache[1] = 0;
    cache[2] = 0;
    cache[3] = 0;

    hits = 0;
    refs = 0;
    page = 0; 

    cin >> page;
    while (page != -1) {  
        refs++;
        assert( (page > 0) && (page <= 100) );

        if (page == cache[0]) {
            hits++;
        }
        else if (page == cache[1]) {
            hits++;
            cache[1] = cache[0];
            cache[0] = page;
        }
        else if (page == cache[2]) {
            hits++;
            cache[2] = cache[1];
            cache[1] = cache[0];
            cache[0] = page;
        }
        else {
            if (page == cache[3]) 
                hits++;
            cache[3] = cache[2];
            cache[2] = cache[1];
            cache[1] = cache[0];
            cache[0] = page;
        }

        cout << cache[0] << " ";
        cout << cache[1] << " ";
        cout << cache[2] << " ";
        cout << cache[3] << "\n";
        cin >> page;
    }
    cout << hits << " of " << refs << " requests found in cache\n";
}
