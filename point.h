#ifndef _POINT_H
#define _POINT_H

#include<iostream>

using namespace std;

class Point {
	public:
    
        // Constructor & destructor
        Point(int p1=0, int p2=0);
        ~Point(void);
    
        // Operator to calculate distance between two points
        int operator*(Point p2);
    
        // Comparison operators to compare two points
        bool operator!=(Point point2);
        bool operator==(Point point2);
    
		// Prototypes for I/O functions
		friend istream &operator>>(istream &,Point &);
		friend ostream &operator<<(ostream &,Point &);
	private:
		// X & Y coordinate integers
		int
            xcoordinate,
            ycoordinate;
};

#endif
