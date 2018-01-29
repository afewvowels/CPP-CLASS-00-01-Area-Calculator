#ifndef _FRACTION_H
#define _FRACTION_H

#include<iostream>

using namespace std;

class Fraction {
	public:
		// Constructor
		Fraction(int n=0, int d=1);
		// Destructor
		~Fraction(void);

    int getNumerator();
    int getDenominator();

		// rhs == right hand side
		Fraction operator+(Fraction rhs);
		Fraction operator-(Fraction rhs);
		Fraction operator*(Fraction rhs);
		Fraction operator/(Fraction rhs);
		Fraction operator=(Fraction rhs);

		// Test comparison operations return true/false
    bool operator==(Fraction rhs);
    bool operator!=(Fraction rhs);
		bool operator<(Fraction rhs);
		bool operator>(Fraction rhs);
		bool operator<=(Fraction rhs);
		bool operator>=(Fraction rhs);

		// Prototypes for I/O functions
		friend istream &operator>>(istream &,Fraction &);
		friend ostream &operator<<(ostream &,Fraction &);
	private:
		// Numerator & Denominator integer names
		int
			num,
			den;
};

#endif
