#include <iostream>
#include <vector>
#include "point.h"
#include "project1.h"

using namespace std;

// int main() contains a do/while loop that runs
// based on an integer value selected by the user
// corresponding to the visible menu options.
// Also contains input validation check (only
// happens once so no need for a separate function)
int main() {
    // Define and initialize menu selection integer
    int intMenuSelection = -1;
    
    // Display the menu then check if selection is 2. exit
    do {
        cout << "Please select from the following menu options:\n";
        cout << "\t1. Calculate area\n";
        cout << "\t2. Exit program\n";
        cout << "Selection: ";
        
        cin >> intMenuSelection;
        
        // Validate input, only used once in application
        // so no separate function was created
        while(!cin || intMenuSelection < 1 || intMenuSelection > 2) {
            cout << "Please select from the visible menu options.\n";
            cout << "Selection: ";
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cin >> intMenuSelection;
        }
        
        // Exit loop if exit integer is entered
        if(intMenuSelection != 1) {
            break;
        }
        
        // Otherwise user enters points to add to a vector
        // the calculates the area based on that vector of points
        calculateArea(generatePointsVector());
    } while(intMenuSelection != 2);
    
    return 0;
}

// This function returns a vector of Points
// and performs checks on vector size to ensure
// a polygon is entered (3 or more points)
vector<Point> generatePointsVector() {
    // Vector to hold all points in the polygon
    vector<Point> vPoints;
    
    // Create temporary point variable to add to vPoints
    Point point;
    // Defined point to use as exit command
    Point exitPoint(-999,-999);
    
    // While the last entered point isn't the exit point
    // and there are less than 3 points (not a polygon),
    // the user will be prompted to enter a point.
    while(point != exitPoint || vPoints.size() < 3) {
        cout << "\nPlease enter a point in the format\n";
        cout << "x,y or -999,-999 to quit: ";
        // Error detection is done in point.cc
        cin >> point;

        // If there is more than a single point in the vector and
        // the new point is the same as the last entered point,
        // notify the user and force them to enter a unique point
        if(vPoints.size() > 0 && point == vPoints[vPoints.size() - 1]) {
            cout << "\nYou must enter a unique point\n\n";
        }
        // If point isn't the exit point, add it to the vector
        else if(point != exitPoint) {
            vPoints.push_back(point);
        }
        // If the point is the exit point and there are less than
        // three elements to the vector, prompt for another point
        else if(vPoints.size() < 3) {
            cout << "You must enter at least three points.\n";
        }
        // If the vector contains 3 or more elements and the
        // entered point is -999,-999, exit the loop
        else if(point == exitPoint) {
            break;
        }
        // Error message
        else {
            cout << "ERROR EDITING POINTS VECTOR\n";
            break;
        }
    }
    
    return vPoints;
}

// This function takes a vector of points and uses
// them to calculate the area of the polygon
// that it contains
void calculateArea(vector<Point> vPoints) {
    int total = 0;
    double area;
    
    // Loops through the vector based on vector size property
    for(int i = 0 ; i < vPoints.size() ; i++) {
        // General case for all but last vertex
        if(i < vPoints.size() - 1) {
            total += vPoints[i] * vPoints[i+1];
        }
        // Special case, last vertex needs to be multiplied
        // with the first vertex
        else if(i == vPoints.size() - 1) {
            total += vPoints[i] * vPoints[0];
        }
        // Error message
        else {
            cout << "ERROR CALCULATING DISTANCE BETWEEN TWO POINTS\n";
        }
    }
    
    // Calculate area
    area = total / 2.0;
    
    // If area is negative, switch the sign
    if(area < 0) {
        area = -area;
    }
    
    // Output result
    cout << "\nArea: " << area << endl << endl;
}
