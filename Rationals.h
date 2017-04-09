#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
using namespace std;

class Rational{
public:
	Rational();
	Rational(int n);
	Rational(int, int);
	int getNumerator() const;
	int getDenominator() const ;
	Rational add(const Rational & other) const;
	Rational subtract(const Rational & other) const;
	Rational multiply(const Rational & other) const;
	Rational divide (const Rational & other) const;
	int compareTo(const Rational & other) const;
	bool equals(const Rational & other) const;
	int intValue() const;
	double doubleValue() const;
	string toString() const;

	Rational &operator += (const Rational & other);
	Rational &operator -= (const Rational & other);
	Rational &operator *= (const Rational & other);
	Rational &operator /= (const Rational & other);

	int &operator [] (int index);

	friend ostream &operator << (ostream & , const Rational &);
	friend istream &operator >> (istream & , Rational &);
private:
	int denominator;
	int numerator;
	static int gcd(int n, int d);
};

bool operator < (const Rational & r1, const Rational &r2);
bool operator <= (const Rational & r1, const Rational &r2);
bool operator > (const Rational & r1, const Rational &r2);
bool operator >= (const Rational & r1, const Rational &r2);
bool operator == (const Rational & r1, const Rational &r2);
bool operator != (const Rational & r1, const Rational &r2);

Rational operator + (const Rational & r1, const Rational &r2);
Rational operator - (const Rational & r1, const Rational &r2);
Rational operator * (const Rational & r1, const Rational &r2);
Rational operator / (const Rational & r1, const Rational &r2);


#endif