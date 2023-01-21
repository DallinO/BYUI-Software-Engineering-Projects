/******************************************************************************
* 1. Name:
*      John Morton, Dallin Olson
* 2. Assignment Name:
*      Practice 03: Angle Class
* 3. Assignment Description:
*      Create an angle class containing methods that convert between radians
*	   and degrees.
* 4. What was the hardest part? Be as specific as possible.
*      
* 5. How long did it take for you to complete the assignment?
*      
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

	double angle[2] = { 0, 0 };

public:

	/************************************
	* GET DEGREES
	* This method returns the angle in
	* degrees.
	************************************/ 
	double getDegrees() {

		char type = tolower(angle[0]);
		if (type == 1) {

			convertToDegrees();
			normalize();
		}

		return angle
	}


	/************************************
	* GET RADIANS
	* This method returns the angle in
	* radians.
	************************************/
	double getRadians() {

		char type = tolower(angle[0]);
		if (type == 0) {

			convertToDegrees();
			normalize();
		}

		return angle;
	}


	/************************************
	* SET DEGREES
	* This method sets the 'angle'
	* variable in degrees.
	************************************/
	double setDegrees() {

		angle[0] = 0;
		cout << 'Enter the angle\n>>> ';
		cin >> angle[1];
	}


	/************************************
	* SET RADIANS
	* This method sets the 'angle'
	* variable in radians.
	************************************/
	double setRadians() {

		angle[0] = 0;
		cout << 'Enter the angle\n>>> ';
		cin >> angle[1];
	}


	/*************************
	* DISPLAY
	* Displays the angle.
	*************************/
	void display() {

	}

private: 
	

	/*************************
	* CONVERT TO DEGREES
	* Converts a radian value
	* to degrees.
	*************************/
	double void convertToDegrees() {

		angle[0] = 0;
		double radian = angle[1];
		angle[1] = radian * (180 / M_PI);
	}


	/*************************
	* CONVERT TO RADIANS
	* Converts a degree value
	* to radians.
	*************************/
	double void convertToRadians() {

		angle[0] = 1;
		double degree = angle[1];
		angle[1] = degree * (M_PI / 180);
	}


	/*************************
	* NORMALIZE
	* Restricts the angle 
	* value to between 0 and
	* 2PI or 0 and 360.
	*************************/
	double normalize() {

	}

}


/*************************
* TEST CASES
* Runs input tests for
* the angle class
*************************/
void testCases() {

}





/*************************
* MAIN
*************************/
static int main() {

	Angle angleClass;


}