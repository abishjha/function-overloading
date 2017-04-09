#include <iostream>
#include <string>
#include "Rationals.h"
using namespace std;

int main() {
	Rational r1(5, 6);
	Rational r2(10, 12);

	if ( r1 == r2 ) {
		cout << "Equal" << endl;
	}

	Rational r3 = r1 + r2;
	cout << r3 << endl;

	return 0;
}