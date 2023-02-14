///***********************************************************************
// * Header File: LM
// * Author:
// *    Dallin Olson & John Morton
// * Summary: Contains the class definition and attribute pertaining to the
// * lunar lander.
// ************************************************************************/
//
//#pragma once
//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#include <cassert>
//#include "fuel.h"
//#include "thrust.h"
//#include "lander.h"
//using namespace std;
//
//#define M_PI     3.14159265358979323846
//#define WEIGHT   15103.000 // Weight in KG
//#define GRAVITY  -1.625 // Vertical acceleration due to gravity, in m/s^2
//#define THRUST   45000.000 // Thrust of main engine, in Newtons (kg m/s^2)
//
///*********************************************
// * CLASS DEFINITION: LM
// *********************************************/
//Lander :: Lander(){}
//
//
///********************************
//* UPDATE ANGLE
//* Updates the angle.
//********************************/
//void Lander::updateAngle(double degrees) { angle = radiansFromDegrees(degrees); }
//
//
///********************************
//* APPLY GRAVITY
//* Applies gravity to the lander.
//********************************/
//void Lander::applyGravity() { dy += GRAVITY; }
//
//
///*******************************
//* TOTAL VELOCITY
//* Calculates the total velocity.
//*******************************/
//double Lander::totalVelocity() const { return sqrt(dx * dx + dy * dy); }
//
//
///************************************
//* APPLY INERTIS
//* Applies inertia to the lander.
//************************************/
//void Lander::applyInertia() {
//    position = position + (dx * t) + (0.5 * ddx * (pow(t, 2)));
//    alttitude = alttitude + (dy * t) + (0.5 * ddy * (pow(t, 2)));
//}
//
///************************************
//* DEGREES FROM RADIANS
//* Converts radians to degrees.
//************************************/
//double Lander::degreesFromRadians(double radians) const
//{
//    return 360.0 * (radians / 2.0 * M_PI);
//}
///************************************
//* RADIANS FROM DEGREES
//* Converts degrees to radians.
//************************************/
//double Lander::radiansFromDegrees(double degrees) const
//{
//    return (2.0 * M_PI) * (degrees / 360.0);
//}
//
//double Lander::GetAngle() { return angle; }
//void Lander::SetAngle(double z) { angle += z; }
//Point Lander::GetPtLM() { return Point(position, alttitude); }
//
//double Lander :: applyThrust() {
//    ddx = sin(angle) * -(THRUST / WEIGHT);
//    ddy = cos(angle) * (THRUST / WEIGHT);
//    dx += ddx;
//    dy += ddy;
//}