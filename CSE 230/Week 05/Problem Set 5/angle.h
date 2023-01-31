#define _USE_MATH_DEFINES

#include <iostream> 
#include <cctype>
#include <cmath>

using namespace std;

#pragma once

/*************************
* ANGLE
*************************/
class Angle {

	double angle;

public:

	/*************************
	* CONSTRUCTORS
	*************************/
	Angle()					{ this->angle = 0; }
	Angle(double degree)	{ this->angle = degree; }
	Angle(const Angle& rhs) { angle = rhs.angle; }

	/******************************************
	* GET DEGREES
	* This method returns the angle in degrees.
	******************************************/
	const double GetDegrees() { return this->angle; }


	/******************************************
	* GET RADIANS
	* This method returns the angle in radians.
	******************************************/
	const double GetRadians() { return this->angle; }


	/**************************************************
	* SET DEGREES
	* This method sets the 'angle' variable in degrees.
	**************************************************/
	void SetDegrees(double degree) { this->angle = degree; }


	/**************************************************
	* SET RADIANS
	* This method sets the 'angle' variable in radians.
	**************************************************/
	void SetRadians(double radian) { this->angle = radian; }


	/*************************
	* DISPLAY
	* Displays the angle.
	*************************/
	const void Display(char type, char convert);


	/************************************
	* CONVERT TO DEGREES
	* Converts a radian value to degrees.
	************************************/
	void ConvertToDegrees();


	/************************************
	* CONVERT TO RADIANS
	* Converts a degree value to radians.
	************************************/
	void ConvertToRadians();


	/*******************************************
	* NORMALIZE
	* Restricts the angle value to between 0 and
	* 2PI or 0 and 360.
	*******************************************/
	const void Normalize(char input);
};