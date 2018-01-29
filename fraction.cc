#include "fraction.h"

using namespace std;

static int gcd(int a, int b) {
	int
		r;

	while(b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

Fraction::Fraction(int n, int d) {
	int
		g;

	if (n < 0) {
		n = -n;
		d = -d;
	}

	g = gcd(n,d);
	n /= g;
	d /= g;

	num = n;
	den = d;
}

Fraction::~Fraction(void) { }

int Fraction::Fraction::getNumerator() {
    return num;
}

int Fraction::Fraction::getDenominator() {
    return den;
}

Fraction Fraction::operator+(Fraction rhs) {
	int
		s,
		t;

	s = num * rhs.den + den * rhs.num;
	t = den * rhs.den;

	return Fraction(s,t);
}

Fraction Fraction::operator-(Fraction rhs) {
	int
		s,
		t;

	s = num * rhs.den - den * rhs.num;
	t = den * rhs.den;

	return Fraction(s,t);
}

Fraction Fraction::operator*(Fraction rhs) {
	int
		s,
		t;

	s = num * rhs.num;
	t = den * rhs.den;

	return Fraction(s,t);
}

Fraction Fraction::operator/(Fraction rhs) {
	int
		s,
		t;

	s = num * rhs.den;
	t = den * rhs.num;

	return Fraction(s,t);
}

Fraction Fraction::operator=(Fraction rhs) {
	num = rhs.num;
	den = rhs.den;

	return rhs;
}

bool Fraction::operator==(Fraction rhs) {
    return num == rhs.num && den == rhs.den;
}

bool Fraction::operator!=(Fraction rhs) {
    return num != rhs.num || den != rhs.den;
}

bool Fraction::operator<(Fraction rhs) {
	if (den * rhs.den >= 0)
		return num * rhs.den < den * rhs.num;
	else
		return num * rhs.den > den * rhs.num;
}

bool Fraction::operator>(Fraction rhs) {
	if (den * rhs.den >= 0)
		return num * rhs.den > den * rhs.num;
	else
		return num * rhs.den < den * rhs.num;
}

bool Fraction::operator<=(Fraction rhs) {
	if (den * rhs.den >= 0)
		return num * rhs.den <= den * rhs.num;
	else
		return num * rhs.den >= den * rhs.num;
}

bool Fraction::operator>=(Fraction rhs) {
	if (den * rhs.den >= 0)
		return num * rhs.den >= den * rhs.num;
	else
		return num * rhs.den <= den * rhs.num;
}

istream &operator>>(istream &is,Fraction &f) {
	int
		n,
		d;

   is >> n;
   is.ignore(16,'/');
   is >> d;

	f = Fraction(n,d);

	return is;
}
ostream &operator<<(ostream &os,Fraction &f) {
	os << f.num << " / " << f.den;

	return os;
}
