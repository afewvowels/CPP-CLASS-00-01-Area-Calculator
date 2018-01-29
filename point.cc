#include "point.h"
#include "fraction.h"

using namespace std;

Point::Point(Fraction a, Fraction b) {
	fraction1 = a;
	fraction2 = b;
}

Point::Point() {
	fraction1 = (-999/-999);
	fraction2 = (-999/-999);
}

// Destructor
Point::~Point(void) { }

void Point::setFraction1(Fraction frac) {
    fraction1 = frac;
}

void Point::setFraction2(Fraction frac) {
    fraction2 = frac;
}

Fraction Point::getFraction1() {
    return fraction1;
}

Fraction Point::getFraction2() {
    return fraction2;
}

// Defines cross multiplication operation to calculate
// distance between points
// Follow format x1y2 - x2y1 and returns the distance
// as a fraction
Fraction Point::operator%(Point p) {
   Fraction
       a,
       b;

   a = fraction1 * p.fraction2;
   b = fraction2 * p.fraction1;

   return a - b;
}

// Multiplies the fractions in a point with the fractions
// in another point and returns the resulting point
Point Point::operator*(Fraction f) {
		Fraction
				a,
				b;

		a = fraction1 * f;
		b = fraction2 * f;

		return Point(a,b);
}

// Calculates the midpoint between two points
// and returns the result as a point
Point Point::operator+(Point p) {
   Fraction
       a,
       b,
			 half(1,2);

   a = (fraction1 + p.fraction1) * half;
   b = (fraction2 + p.fraction2) * half;

   return Point(a,b);
}

// Calculates the midpoint between two points
// and returns the result as a point
Point Point::operator-(Point p) {
   Fraction
       a,
       b,
			 half(1,2);

   a = (fraction1 - p.fraction1) * half;
   b = (fraction2 - p.fraction2) * half;

   return Point(a,b);
}

// Used to compare two different points !=
bool Point::operator!=(Point point2) {
    return fraction1 != point2.fraction1 || fraction2 != point2.fraction2;
}

// Used to compare two different points ==
bool Point::operator==(Point point2) {
    return fraction1 == point2.fraction1 && fraction2 == point2.fraction2;
}

istream &operator>>(istream &is,Point &p) {
    Fraction
        x,
        y;

    is.ignore(16,'(');
    is >> x;
    is.ignore(16,',');
    is >> y;
    is.ignore(16,')');

		p = Point(x,y);

    return is;
}

ostream &operator<<(ostream &os,Point &p) {
    os << "( " << p.fraction1 << " , " << p.fraction2 << " )";

    return os;
}
