#ifndef _POINT_H
#define _POINT_H

#include<iostream>
#include"fraction.h"

using namespace std;

class Point {
	public:

        // Constructor & destructor
        Point(Fraction a, Fraction b);
        Point();
        ~Point(void);

		    void setFraction1(Fraction);
		    void setFraction2(Fraction);

        Fraction getFraction1();
        Fraction getFraction2();

        //Operator to calculate distance between two points
       	Fraction operator%(Point p);
       	Point operator*(Fraction f);
				Point operator+(Point p);
				Point operator-(Point p);

        // Comparison operators to compare two points
        bool operator!=(Point point2);
        bool operator==(Point point2);

		// Prototypes for I/O functions
        friend istream &operator>>(istream &,Point &);
        friend ostream &operator<<(ostream &,Point &);
	private:
		// X & Y coordinate integers
		Fraction
        fraction1,
        fraction2;
};

#endif
