#include "point.h"

using namespace std;

// Constructor uses x and y variables as inputs
Point::Point(int x, int y) {
	xcoordinate = x;
	ycoordinate = y;
}

// Destructor
Point::~Point(void) { }

// Defines operation to calculate distance between points
// Follow format x1y2 - x2y1 and returns the distance
int Point::operator*(Point p2) {
    double
        a,
        b;
    
	a = xcoordinate * p2.ycoordinate;
	b = ycoordinate * p2.xcoordinate;

	return a - b;
}

// Used to compare two different points !=
bool Point::operator!=(Point point2) {
    return xcoordinate != point2.xcoordinate || ycoordinate != point2.ycoordinate;
}

// Used to compare two different points ==
bool Point::operator==(Point point2) {
    return xcoordinate == point2.xcoordinate && ycoordinate == point2.ycoordinate;
}

// Modified to contain data validation on integer inputs
istream &operator>>(istream &is,Point &p) {
	int
		x,
		y;

    cin >> x;
    while(!(cin)) {
        cout << "Please enter an integer x-coordinate: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> x;
    }
    
    cin.ignore(16, ',');
    
    cin >> y;
    while(!(cin)) {
        cout << "Please enter an integer y-coordinate: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> y;
    }
    
	p = Point(x,y);

	return is;
}

ostream &operator<<(ostream &os,Point &p) {
    os << "( " << p.xcoordinate << " , " << p.ycoordinate << " )";
	
	return os;
}
