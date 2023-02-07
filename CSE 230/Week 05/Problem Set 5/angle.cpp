/******************************************************************************
* 1. Name:
*      John Morton, Dallin Olson
* 2. Assignment Name:
*      Practice 05: C++ Methods
* 3. Assignment Description:
*      Create a header and source file for the Angle class. Create a seperate
*	   file for testing the class. Add constructors to the Angle class.
* 4. What was the hardest part? Be as specific as possible.
*	   The assignment was simple and we did not run into any issues.
* 5. How long did it take for you to complete the assignment?
*	   1 Hours
******************************************************************************/

#define _USE_MATH_DEFINES

#include <iostream> 
#include <cctype>
#include <cmath>
#include "angle.h"

using namespace std;

/*************************
* DISPLAY
* Displays the angle.
*************************/
const void Angle::Display(char type, char convert) {

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
	Normalize(type);
	if (convert == 'y') {

		if (type == 'r') {
			ConvertToDegrees();
		}
		if (type == 'd') {
			ConvertToRadians();
		}
	}	

	cout << "Angle: " << this->angle << endl;
}


/************************************
* CONVERT TO DEGREES
* Converts a radian value to degrees.
************************************/
void Angle::ConvertToDegrees() {

	double radian = this->angle;
	this->angle = radian * (180 / M_PI);
}


/************************************
* CONVERT TO RADIANS
* Converts a degree value to radians.
************************************/
void Angle::ConvertToRadians() {

	double degree = this->angle;
	this->angle = degree * (M_PI / 180);
}


/*************************************************************
* NORMALIZE
* Restricts the angle value to between 0 and 2PI or 0 and 360.
*************************************************************/
const void Angle::Normalize(char input) {

	char type = tolower(input);	
	if (this->angle >= 0) {
		if (type == 'r') {

			while (this->angle > (2 * M_PI)) {
				this->angle = this->angle - (2 * M_PI);
				//cout << "ALPHA" << endl;
			}
		}
		if (type == 'd') {

			while (this->angle > 360) {
				this->angle = this->angle - 360;
				//cout << "BETA" << endl;
			}
		}
	} else if (this->angle < 0) {
		if (type == 'r') {

			while (this->angle < 0) {
				this->angle = this->angle + (2 * M_PI);
				//cout << "CHARLIE" << endl;
			}
		}
		if (type == 'd') {

			while (this->angle < 0) {
				this->angle = this->angle + 360;
				//cout << "DELTA" << endl;
			}
		}
	}
}