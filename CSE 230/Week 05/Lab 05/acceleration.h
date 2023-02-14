/***********************************************************************
 * Header File: LM
 * Author:
 *    Dallin Olson & John Morton
 * Summary: Contains the class definition and attribute pertaining to the
 * lunar lander.
 ************************************************************************/

#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;

#define M_PI     3.14159265358979323846
#define WEIGHT   15103.000 // Weight in KG
#define GRAVITY  -1.625 // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000 // Thrust of main engine, in Newtons (kg m/s^2)

class Acceleration {

	double ddx;
	double ddy;
	double total;

	Acceleration() {}
	Acceleration(double ddx, double ddy){
	}
	double GetDX() { return ddx; }
	double GetDY() { return ddy; }
	double GetSpeed() {
		total = sqrt((ddx * ddx) + (ddy * ddy));
	}
	void SetDX(double ddx) { this->ddx = ddx; }
	void SetDY(double ddy) { this->ddy = ddy; }




};