#include <iostream>
#include <vector>
#include "point.h"
#include "project1.h"
#include "fraction.h"

using namespace std;

// main contains the single calculate area function
// (no loops)
int main() {
    operatorDemo();

    calculateArea();

    return 0;
}


// This function gets a point from the user, then
// stores it as the origin then loops to get additional
// points, store them, calculate distance, and listens
// for the pointOrigin to be entered again.
// Then the loop breaks and the area is calculated from
// the final distance fraction.
void calculateArea() {

    Fraction distance(0,1);
    Fraction oneHalf(1,2);

    Point pointOrigin;
    Point pointA;
    Point pointB;

    cout << "\nEnter the origin:\n";
    cin >> pointA;
    cout << "That point is: " << pointA << endl;

    pointOrigin = pointA;

    do {
        cout << "\nEnter another point or re-enter\n";
        cout << "the origin to complete the process:\n";
        cin >> pointB;
        cout << "That point is: " << pointB << endl;

        distance = distance + (pointA % pointB);

        cout << "Distance: " << distance << endl;

        pointA = pointB;
    } while(pointB != pointOrigin);

    distance = distance * oneHalf;

    cout << "\nArea: " << distance << endl << endl;
}

void operatorDemo() {
    Point p1(0/1,0/1);
    Point p2(1/1,1/1);

    Point temp;

    Fraction f(1,2);

    temp = p1 + p2;

    cout << "Point math examples\n";
    cout << "Point addition: " << p1 << "+" << p2 << "=" << temp << endl;

    temp = p2 - p1;

    cout << "Point subtraction: " << p2 << "-" << p1 << "=" << temp << endl;
}
