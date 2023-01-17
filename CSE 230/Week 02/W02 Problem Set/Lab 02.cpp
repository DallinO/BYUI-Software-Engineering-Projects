/*************************************************************
* 1. Name:
*      John Morton, Dallin Olson
* 2. Assignment Name:
*      Lab 02: Apollo 11
* 3. Assignment Description:
*      Simulate the Apollo 11 landing
* 4. What was the hardest part? Be as specific as possible.
*      Debugging the issues between our programs was main issue at first,
*      but we quickly solved that. The other issue was learning the class
*      syntax, but we learned that pretty quickly as well.
* 5. How long did it take for you to complete the assignment?
*      2 hours
*****************************************************************/

#define _USE_MATH_DEFINES
#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

#include <iostream>  // for CIN and COUT
#include <cmath>

using namespace std;

class Physics {

    /***************************************************
    * COMPUTE DISTANCE
    * Apply inertia to compute a new position using the distance equation.
    * The equation is:
    *     s = s + v t + 1/2 a t^2
    * INPUT
    *     s : original position, in meters
    *     v : velocity, in meters/second
    *     a : acceleration, in meters/second^2
    *     t : time, in seconds
    * OUTPUT
    *     s : new position, in meters
    **************************************************/
    public : double computeDistance(double s, double v, double a, double t)
    {
        s = s + (v * t) + (0.5 * a * (pow(t, 2)));
        return s;
    }


    /**************************************************
    * COMPUTE ACCELERATION
    * Find the acceleration given a thrust and mass.
    * This will be done using Newton's second law of motion:
    *     f = m * a
    * INPUT
    *     f : force, in Newtons (kg * m / s^2)
    *     m : mass, in kilograms
    * OUTPUT
    *     a : acceleration, in meters/second^2
    ***************************************************/
    public : double computeAcceleration(double f, double m)
    {
        double a;
        a = f / m;
        return a;
    }


    /***********************************************
    * COMPUTE VELOCITY
    * Starting with a given velocity, find the new
    * velocity once acceleration is applied. This is
    * called the Kinematics equation. The
    * equation is:
    *     v = v + a t
    * INPUT
    *     v : velocity, in meters/second
    *     a : acceleration, in meters/second^2
    *     t : time, in seconds
    * OUTPUT
    *     v : new velocity, in meters/second
    ***********************************************/
    public: double computeVelocity(double v, double a, double t)
    {
        v = v + (a * t);
        return v;
    }


    /***********************************************
    * COMPUTE VERTICAL COMPONENT
    * Find the vertical component of a velocity or acceleration.
    * The equation is:
    *     cos(a) = y / total
    * This can be expressed graphically:
    *      x
    *    +-----
    *    |   /
    *  y |  / total
    *    |a/
    *    |/
    * INPUT
    *     a : angle, in radians
    *     total : total velocity or acceleration
    * OUTPUT
    *     y : the vertical component of the total
    ***********************************************/
    public: double computeVertileComponent(double a, double total)
    {
        double y;
        y = cos(a) * total;
        return y;
    }


    /***********************************************
    * COMPUTE HORIZONTAL COMPONENT
    * Find the horizontal component of a velocity or acceleration.
    * The equation is:
    *     sin(a) = x / total
    * This can be expressed graphically:
    *      x
    *    +-----
    *    |   /
    *  y |  / total
    *    |a/
    *    |/
    * INPUT
    *     a : angle, in radians
    *     total : total velocity or acceleration
    * OUTPUT
    *     x : the horizontal component of the total
    ***********************************************/
    public : double computeHorizontalCompnent(double a, double total)
    {
        double x;
        x = sin(a) * total;
        return x;
    }


    /************************************************
    * COMPUTE TOTAL COMPONENT
    * Given the horizontal and vertical components of
    * something (velocity or acceleration), determine
    * the total component. To do this, use the Pythagorean Theorem:
    *    x^2 + y^2 = t^2
    * where:
    *      x
    *    +-----
    *    |   /
    *  y |  / total
    *    | /
    *    |/
    * INPUT
    *    x : horizontal component
    *    y : vertical component
    * OUTPUT
    *    total : total component
    ***********************************************/
    public : double computeTotalComponent(double x, double y)
    {
        double total;
        total = sqrt((x * x) + (y * y));
        return total;
    }


    /*************************************************
    * RADIANS FROM DEGEES
    * Convert degrees to radians:
    *     radians / 2pi = degrees / 360
    * INPUT
    *     d : degrees from 0 to 360
    * OUTPUT
    *     r : radians from 0 to 2pi
    **************************************************/
    public : double convertRadiansFromDegrees(double d)
    {
        double r;
        r = (d / 360) * (2 * M_PI);
        return r;
    }

};


/**************************************************
* PROMPT
* A generic function to prompt the user for a double
* INPUT
*      message : the message to display to the user
* OUTPUT
*      response : the user's response
***************************************************/
double prompt(string message)
{
    double response;
    cout << message;
    cin >> response;
    return response;
}


/****************************************************************
* MAIN
* Prompt for input, compute new position, and display output
****************************************************************/
int main()
{
    Physics physics;
    double aRadians;            // Angle in radians
    double accelerationThrust;  // Acceleration due to thrust 
    double ddxThrust;           // Horizontal acceleration due to thrust
    double ddyThrust;           // Vertical acceleration due to thrust
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double v;                   // Total velocity

    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    double x = prompt("What is your position (m)? ");
    double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    double t = prompt("What is the time interval (s)? ");
    int time = 1;
    // Convert degrees to radians
    aRadians = physics.convertRadiansFromDegrees(aDegrees);

    for (int i = 0; i < 5; i++)
    {
        // Compute accelerations
        accelerationThrust = physics.computeAcceleration(THRUST, WEIGHT);   
        ddxThrust = physics.computeHorizontalCompnent(aRadians, accelerationThrust);
        ddyThrust = physics.computeVertileComponent(aRadians, accelerationThrust);
        ddx = ddxThrust;
        ddy = ddyThrust + GRAVITY;
        // Compute velocities
        dx = physics.computeVelocity(dx, ddx, t);
        dy = physics.computeVelocity(dy, ddy, t);
        v = physics.computeTotalComponent(dx, dy);
        // Compute positions
        x = physics.computeDistance(x, dx, ddx, t);
        y = physics.computeDistance(y, dy, ddy, t);
        // Display
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        cout << time << "s - x,y:(" << x << ", " << y << ")m  dx,dy:"
            "(" << dx << ", " << dy << ")m/s  Speed:" << v << "m/s  "
            "angle:" << aDegrees << "deg\n";
        time++;
    }

    aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    aRadians = physics.convertRadiansFromDegrees(aDegrees);


    for (int i = 0; i < 5; i++)
    {
        // Compute accelerations
        accelerationThrust = physics.computeAcceleration(THRUST, WEIGHT);
        ddxThrust = physics.computeHorizontalCompnent(aRadians, accelerationThrust);
        ddyThrust = physics.computeVertileComponent(aRadians, accelerationThrust);
        ddx = ddxThrust;
        ddy = ddyThrust + GRAVITY;
        // Compute velocities
        dx = physics.computeVelocity(dx, ddx, t);
        dy = physics.computeVelocity(dy, ddy, t);
        v = physics.computeTotalComponent(dx, dy);
        // Compute positions
        x = physics.computeDistance(x, dx, ddx, t);
        y = physics.computeDistance(y, dy, ddy, t);
        // Display
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        cout << time << "s - x,y:(" << x << ", " << y << ")m  dx,dy:"
            "(" << dx << ", " << dy << ")m/s  Speed:" << v << "m/s  "
            "angle:" << aDegrees << "deg\n";
        time++;
    }

    return 0;
}