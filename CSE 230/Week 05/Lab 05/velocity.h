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

class Velocity {
private:
	double dx;
	double dy;
	double total;
public:
	Velocity() {}
	Velocity(double dx, double dy) {}
	double GetDX() { return dx; }
	double GetDY() { return dy; }
	double GetSpeed() {
		total = sqrt((dx * dx) + (dy * dy));
	}
	void SetDX(double dx) { this->dx = dx; }
	void SetDY(double dy) { this->dy = dy; }
	double Add(double accel, int time) {
		dx = dx + (accel * time);
		dy = dy + (accel * time);
	}




};