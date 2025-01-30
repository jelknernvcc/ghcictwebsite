//-----------------------------------------------------------------------
// computer networks
//-----------------------------------------------------------------------

#include <iostream>
#include <assert.h>
using namespace std;

//-----------------------------------------------------------------------
//  main
//      The main procedure inputs each command, and outputs the results.
//-----------------------------------------------------------------------
 
int main()
{
    int p1, p2, p3, p4, checksum;

    while (true) {

        cin >> p1;
        if (p1 == -1) 
           break;
        cin >> p2;
        cin >> p3;
        cin >> p4;

        assert( p1 >= 0 );
        assert( p1 < 256 );
        assert( p2 >= 0 );
        assert( p2 < 256 );
        assert( p3 >= 0 );
        assert( p3 < 256 );
        assert( p4 >= 0 );
        assert( p4 < 256 );

        checksum = p1 + p2 + p3;
        while (checksum >= 256)
            checksum -= 256;
        checksum = 255 - checksum;

        if (checksum == p4)
            cout << "valid" << endl;
        else
            cout << "invalid" << endl;
    }

    return 0;
}
