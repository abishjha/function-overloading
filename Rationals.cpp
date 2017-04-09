#include "Rationals.h"
#include <sstream>
#include <iostream>
using namespace std;

Rational :: Rational() {
	this->numerator = 0;
	this->denominator = 1;
}

Rational :: Rational(int numerator) {
	this->numerator = numerator;
	this->denominator = 1;
}

Rational :: Rational(int numerator, int denominator){
	int factor = gcd (numerator, denominator);
	if ( denominator > 0 ) {
		this->numerator = numerator/factor;
	}
	else {
		this->numerator = -numerator/factor;
	}
	this->denominator = abs(denominator)/factor;
}

int Rational :: gcd(int n, int d) {
	int n1 = abs(n);
	int n2 = abs(d);
	int retval = 1;
	for ( int k = 1; k <= n1 && k <= n2; k++ ) {
		if ( n1%k == 0 && n2%k == 0 ) 
			retval =k;
	}
	return retval;
}

int Rational :: getNumerator() const {
	return this->numerator;
}

int Rational :: getDenominator() const  {
	return this->denominator;
}

Rational Rational :: add(const Rational & other) const {
	int n = numerator * other.getDenominator() + 
		denominator * other.getNumerator();
	int d = denominator * other.getDenominator();
	return Rational(n, d); // reduces
}

Rational Rational :: subtract(const Rational & other) const
{
	int n = numerator * other.getDenominator() - 
		denominator * other.getNumerator();
	int d = denominator * other.getDenominator();
	return Rational(n, d); // reduces
}

Rational Rational :: multiply(const Rational & other) const {
	int n = numerator * other.getNumerator();
	int d = denominator * other.getDenominator();
	return Rational(n, d);
}



Rational Rational :: divide (const Rational & other) const {
	int n = numerator * other.getDenominator();
	int d = denominator * other.getNumerator();
	return Rational(n, d);
}

int Rational :: compareTo(const Rational & other) const {

	Rational tmp = subtract(other);
	if (tmp.getNumerator() < 0 ) 
		return -1;
	else if ( tmp.getNumerator() > 0 ) 
		return 1;
	else 
		return 0;
}

bool Rational :: equals(const Rational & other) const {
	return compareTo(other) == 0;
}

int Rational :: intValue() const {
	return this->getNumerator() / this->getDenominator();
}

double Rational :: doubleValue() const {
	return 1.0 * this->getNumerator() / this->getDenominator();
}

string Rational :: toString() const {
	stringstream ss1, ss2;
	ss1 << this->getNumerator();
	ss2 << this->getDenominator();
	if ( this->getDenominator() == 1 ) {
		return ss1.str();
	}
	else {
		return ss1.str() + "/" + ss2.str();
	}
}

Rational &Rational :: operator += (const Rational & other) {
	*this = this->add(other);
	return *this;
}
Rational &Rational :: operator -= (const Rational & other) {
	*this = this->subtract(other);
	return *this;
}

Rational &Rational :: operator *= (const Rational & other) {
	*this = this->multiply(other);
	return *this;
}

Rational &Rational :: operator /= (const Rational & other){
	*this = this->divide(other);
	return *this;
}

int & Rational :: operator [] (int index) {
	if ( index == 0 ) return this->numerator;
	else return this->denominator;
}

ostream & operator << (ostream & out, const Rational & r) {
	out << r.toString();
	return out;
}

istream &operator >> (istream & in, Rational & r) {
	cout << "Enter numerator:  ";
	in  >> r.numerator;
	cout << "Enter denominator:  ";
	in  >> r.denominator;
	return in;
}



bool operator < (const Rational & r1, const Rational &r2) {
	return r1.compareTo(r2) < 0;
}
bool operator <= (const Rational & r1, const Rational &r2){
	return r1.compareTo(r2) <= 0;
}
bool operator > (const Rational & r1, const Rational &r2){
	return r1.compareTo(r2)  > 0;
}
bool operator >= (const Rational & r1, const Rational &r2){
	return r1.compareTo(r2) >= 0;
}
bool operator == (const Rational & r1, const Rational &r2){
	return r1.compareTo(r2) == 0;
}
bool operator != (const Rational & r1, const Rational &r2){
	return r1.compareTo(r2) != 0;
}

Rational operator + (const Rational & r1, const Rational &r2) {
	return r1.add(r2);
}

Rational operator - (const Rational & r1, const Rational &r2) {
	return r1.subtract(r2);
}

Rational operator * (const Rational & r1, const Rational &r2) {
	return r1.multiply(r2);
}

Rational operator / (const Rational & r1, const Rational &r2) {
	return r1.divide(r2);
}
