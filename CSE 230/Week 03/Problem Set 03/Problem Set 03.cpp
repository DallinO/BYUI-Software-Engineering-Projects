/******************************************************************************
* 1. Name:
*      John Morton, Dallin Olson
* 2. Assignment Name:
*      Practice 03: Angle Class
* 3. Assignment Description:
*      Create an angle class containing methods that convert between radians
*	   and degrees.
* 4. What was the hardest part? Be as specific as possible.
*	   The hardest part was setting the correct statements for the while loops
*	   for the normalize method.
* 5. How long did it take for you to complete the assignment?
*	   2 Hours
******************************************************************************/

#define _USE_MATH_DEFINES

#include <iostream> 
#include <cctype>
#include <cmath>

using namespace std;


/*************************
* ANGLE
*************************/
class Angle {

	double angle = 0;


public:

	/************************************
	* GET DEGREES
	* This method returns the angle in
	* degrees.
	************************************/
	double getDegrees() {

		return angle;
	}


	/************************************
	* GET RADIANS
	* This method returns the angle in
	* radians.
	************************************/
	double getRadians() {

		return angle;
	}


	/************************************
	* SET DEGREES
	* This method sets the 'angle'
	* variable in degrees.
	************************************/
	void setDegrees(double degree) {

		angle = degree;
	}


	/************************************
	* SET RADIANS
	* This method sets the 'angle'
	* variable in radians.
	************************************/
	void setRadians(double radian) {

		angle = radian;
	}


	/*************************
	* DISPLAY
	* Displays the angle.
	*************************/
	void display(char type, char convert) {

		cout.setf(ios::fixed | ios::showpoint);
		cout.precision(2);
		normalize(type);
		if (convert == 'y') {

			if (type == 'r') {
				convertToDegrees();
			}
			if (type == 'd') {
				convertToRadians();
			}
		}	

		cout << "Angle: " << angle << endl;
	}

private:


	/*************************
	* CONVERT TO DEGREES
	* Converts a radian value
	* to degrees.
	*************************/
	void convertToDegrees() {

		double radian = angle;
		angle = radian * (180 / M_PI);
	}


	/*************************
	* CONVERT TO RADIANS
	* Converts a degree value
	* to radians.
	*************************/
	void convertToRadians() {

		double degree = angle;
		angle = degree * (M_PI / 180);
	}


	/*************************
	* NORMALIZE
	* Restricts the angle
	* value to between 0 and
	* 2PI or 0 and 360.
	*************************/
	void normalize(char input) {

		char type = tolower(input);	
		if (angle >= 0) {
			if (type == 'r') {

				while (angle > (2 * M_PI)) {
					angle = angle - (2 * M_PI);
					//cout << "ALPHA" << endl;
				}
			}
			if (type == 'd') {

				while (angle > 360) {
					angle = angle - 360;
					//cout << "BETA" << endl;
				}
			}
		} else if (angle < 0) {
			if (type == 'r') {

				while (angle < 0) {
					angle = angle + (2 * M_PI);
					//cout << "CHARLIE" << endl;
				}
			}
			if (type == 'd') {

				while (angle < 0) {
					angle = angle + 360;
					//cout << "DELTA" << endl;
				}
			}
		}
	}
};


/*************************
* TEST CASES
* Runs input tests for
* the angle class
*************************/
void testCases(Angle angleClass) {

	double angles[] = { -360, 0, 90, 420, -M_PI, M_PI_2, (2 * M_PI), (3 * M_PI)};
	char type = 'd';
	char convert = 'n';
	// Display randian angles. Testing display(), normalize() & setDegrees()
	cout << "TEST: DISPLAY DEGREE ANGLE" << endl;
	for (int i = 0; i < 4; i++) {

		angleClass.setDegrees(angles[i]);
		angleClass.display(type, convert);
	}
	// Convert degrees to radians. Testing convertToRadians()
	cout << "TEST: CONVERT DEGREE TO RADIAN" << endl;
	convert = 'y';
	for (int i = 0; i < 4; i++) {

		angleClass.setDegrees(angles[i]);
		angleClass.display(type, convert);
	}
	// Display randian angles. Testing display(), normalize() & setRadians()
	cout << "TEST: DISPLAY RADIAN ANGLE" << endl;
	type = 'r';
	convert = 'n';
	for (int i = 4; i < 8; i++) {

		angleClass.setRadians(angles[i]);
		angleClass.display(type, convert);
	}
	// Convert radians to degrees. Testing convertToDegrees()
	cout << "TEST: CONVERT RADIAN ANGLE" << endl;
	convert = 'y';
	for (int i = 4; i < 8; i++) {

		angleClass.setRadians(angles[i]);
		angleClass.display(type, convert);
	}
	angleClass.setDegrees(180);
	// Test getDegrees()
	cout << "TEST: GET DEGREES" << endl;
	cout << angleClass.getDegrees() << endl;
	angleClass.setRadians(M_PI);
	// Test getRadians()
	cout << "TEST: GET RADIANS" << endl;
	cout << angleClass.getRadians() << endl;
}


/*************************
* MAIN
*************************/
int main() {

	Angle angleClass;
	testCases(angleClass);
}