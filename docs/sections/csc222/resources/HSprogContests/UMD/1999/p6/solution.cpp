//-----------------------------------------------------------------------
//    File: quatern.cc
//    Description: Quaternion Calculator
//    Author: Dave Mount (mount@cs.umd.edu)
//
//    This program implements a calculator for quaternions.  It
//    supports the operations of adding, multiplying, negating,
//    and inverting quaterions.  The quaternions are stored in 10
//    registers, numbered 0 through 9.
//-----------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <assert.h>
using namespace std;

//-----------------------------------------------------------------------
//  Quaternion
//-----------------------------------------------------------------------
struct Quaternion {            // a quaternion
    double    q[4];            // the coordinates

    Quaternion() {              // default (zero)
        q[0] = q[1] = q[2] = q[3] = 0;
    } 
    // constructor
    Quaternion(double q0, double q1, double q2, double q3) {
        q[0] = q0;  q[1] = q1;  q[2] = q2;  q[3] = q3;
    } 

    double operator[](int i) const {
        return q[i];
    }
};

Quaternion operator+(const Quaternion &q, const Quaternion &p) {
    return Quaternion(q[0]+p[0], q[1]+p[1], q[2]+p[2], q[3]+p[3]);
}

Quaternion operator-(const Quaternion &q) {
    return Quaternion(-q[0], -q[1], -q[2], -q[3]);
}

Quaternion operator*(const Quaternion &q, const Quaternion &p) {
    return Quaternion(
        q[0]*p[0] - q[1]*p[1] - q[2]*p[2] - q[3]*p[3],
        q[0]*p[1] + q[1]*p[0] + q[2]*p[3] - q[3]*p[2],
        q[0]*p[2] - q[1]*p[3] + q[2]*p[0] + q[3]*p[1],
        q[0]*p[3] + q[1]*p[2] - q[2]*p[1] + q[3]*p[0]
    );
}

ostream &operator<<(ostream &o, const Quaternion &q) {
    return o << "( " << q[0] << " " << q[1] << " " << q[2]
             << " " << q[3] << " )";
}

//-----------------------------------------------------------------------
//  main
//    The main procedure inputs each command, and outputs the results.
//-----------------------------------------------------------------------

int main()
{
    char opCode;                // operation code
    Quaternion Q[10];           // registers
    int i, j, k;                // register indices
    double q0, q1, q2, q3;      // operands

    // initialize to zero
    for (int i = 0; i < 10; i++)
        Q[i] = Quaternion(0, 0, 0, 0);

    do {
        cin >> opCode;           // get opcode
	switch (opCode) {
	    case '=':
		cin >> q0 >> q1 >> q2 >> q3 >> i;
		Q[i] = Quaternion(q0, q1, q2, q3);
		cout << "[" << i << "] " << Q[i] << endl;
		break;
	    case '+':
		cin >> i >> j >> k;
		Q[k] = Q[i] + Q[j];
		cout << "[" << k << "] " << Q[k] << endl;
		break;
	    case '*':
		cin >> i >> j >> k;
		Q[k] = Q[i] * Q[j];
		cout << "[" << k << "] " << Q[k] << endl;
		break;
	    case '-':
		cin >> i >> j;
		Q[j] = -Q[i];
		cout << "[" << j << "] " << Q[j] << endl;
		break;
	    case 'Q':
		exit(0);
	    default:
		cout << "Illegal opcode" << endl;
		break;
        }
    } while (true);
}
