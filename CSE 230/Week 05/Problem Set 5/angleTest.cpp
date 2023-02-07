#define _USE_MATH_DEFINES

#include <iostream> 
#include <cctype>
#include <cmath>
#include "angle.h"

using namespace std;

/*************************************
* TEST CASES
* Runs input tests for the angle class
*************************************/
void testCases(Angle angleClass) {

	double angles[] = { -360, 0, 90, 420, -M_PI, M_PI_2, (2 * M_PI), (3 * M_PI) };
	char type = 'd';
	char convert = 'n';
	// Display randian angles. Testing display(), normalize() & setDegrees()
	cout << "TEST: DISPLAY DEGREE ANGLE" << endl;
	for (int i = 0; i < 4; i++) {

		angleClass.SetDegrees(angles[i]);
		angleClass.Display(type, convert);
	}
	// Convert degrees to radians. Testing convertToRadians()
	cout << "TEST: CONVERT DEGREE TO RADIAN" << endl;
	convert = 'y';
	for (int i = 0; i < 4; i++) {

		angleClass.SetDegrees(angles[i]);
		angleClass.Display(type, convert);
	}
	// Display randian angles. Testing display(), normalize() & setRadians()
	cout << "TEST: DISPLAY RADIAN ANGLE" << endl;
	type = 'r';
	convert = 'n';
	for (int i = 4; i < 8; i++) {

		angleClass.SetRadians(angles[i]);
		angleClass.Display(type, convert);
	}
	// Convert radians to degrees. Testing convertToDegrees()
	cout << "TEST: CONVERT RADIAN ANGLE" << endl;
	convert = 'y';
	for (int i = 4; i < 8; i++) {

		angleClass.SetRadians(angles[i]);
		angleClass.Display(type, convert);
	}
	angleClass.SetDegrees(180);
	// Test getDegrees()
	cout << "TEST: GET DEGREES" << endl;
	cout << angleClass.GetDegrees() << endl;
	angleClass.SetRadians(M_PI);
	// Test getRadians()
	cout << "TEST: GET RADIANS" << endl;
	cout << angleClass.GetRadians() << endl;
}


/*************************
* MAIN
*************************/
int main() {

	Angle angle1;
	Angle angle2(90);
	Angle angle3(angle1);
	cout << "Angle1" << endl;
	testCases(angle1);
	cout << "Angle2" << endl;
	testCases(angle2);
	cout << "Angle3" << endl;
	testCases(angle3);
}