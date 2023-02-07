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

/*********************************************
 * CLASS DEFINITION: LM
 *********************************************/
class LM {
public:

    double fuel = 5000;
    double counter;
    double x;
    double y;
    double dx;
    double dy;
    double ddx;
    double ddy;
    double angle;

    // CONSTRUCTOR
    LM(double altitude, double position,
        double verticalVelocity,
        double horizontalVelocity,
        double degrees)
    {
        x = position;
        y = altitude;
        dx = horizontalVelocity;
        dy = verticalVelocity;
        ddx = 0.0;
        ddy = 0.0;

        updateAngle(degrees);
    }
    
    /********************************
    * BURN ROTATE FUEL
    * Reduces the fuel when the
    * lander is rotated
    ********************************/
    void burnFuel()                     { fuel = fuel - 10; }


    /********************************
    * BURN ROTATE FUEL
    * Reduces the fuel when the
    * lander is rotated
    ********************************/
    void burnRotateFuel()               { fuel = fuel - 1; }


    /********************************
    * UPDATE ANGLE
    * Updates the angle.
    ********************************/
    void updateAngle(double degrees)    { angle = radiansFromDegrees(degrees); }


    /********************************
    * APPLY GRAVITY
    * Applies gravity to the lander.
    ********************************/
    void applyGravity()                 { dy += GRAVITY; }


    /*******************************
    * TOTAL VELOCITY
    * Calculates the total velocity.
    *******************************/
    double totalVelocity() const        { return sqrt(dx * dx + dy * dy); }


    /************************************
    * APPLY INERTIS
    * Applies inertia to the lander.
    ************************************/
    void applyInertia() {
        x += dx + 0.5 * ddx;
        y += dy + 0.5 * (ddy + GRAVITY);
    }
    /************************************
    * APPLY THRUST
    * Applies thrust to the lander.
    ************************************/
    void applyThrust() {
        ddx = sin(angle) * -THRUST / WEIGHT;
        ddy = cos(angle) * THRUST / WEIGHT;

        dx += ddx;
        dy += ddy;
    }
    /************************************
    * DEGREES FROM RADIANS
    * Converts radians to degrees.
    ************************************/
    double degreesFromRadians(double radians) const
    {
        return 360.0 * (radians / 2.0 * M_PI);
    }
    /************************************
    * RADIANS FROM DEGREES
    * Converts degrees to radians.
    ************************************/
    double radiansFromDegrees(double degrees) const
    {
        return (2.0 * M_PI) * (degrees / 360.0);
    }
};