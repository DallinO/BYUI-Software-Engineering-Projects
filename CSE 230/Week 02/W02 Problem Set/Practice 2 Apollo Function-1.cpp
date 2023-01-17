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

#include <iostream>  // for CIN and COUT
#include <cmath>
using namespace std;

#define M_PI     3.14159265358979323846
#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)


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
public:double calc_dist(double s, double v, double a, double t)
{
    double ss = s + (v * t) + (0.5 * (a * pow(t, 2)));
    return ss;
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
public:double calc_acc(double f, double m)
{
    double a = f / m;
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
public:double calc_vel(double v, double a, double t)
{
    double vv = v + (a * t);
    return vv;
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
public:double calc_vert(double a, double tot)
{
    double vert = cos(a) * tot;
    return vert;
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
       *     x : the vertical component of the total
       ***********************************************/
public:double calc_horz(double a, double tot)
{
    double horz = sin(a) * tot;
    return horz;
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

public:double calc_totcomp(double x, double y)
{
    double tot = pow(x, 2) + pow(y, 2);
    return sqrt(tot);
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
public:double calc_rads(double deg)
{
    if (deg < 0)
    {
        deg = deg + 360;
    }
    double rads = (deg) / 360;
    return rads * (2 * M_PI);
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
double prompt(string in)
{
    double x;
    cout << in;
    cin >> x;
    return x;
}

/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
int main()
{
    Physics physics;
    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    double x = 0;
    double t = 1;
    double aRadians;            // Angle in radians
    double accelerationThrust;  // Acceleration due to thrust 
    double ddxThrust;           // Horizontal acceleration due to thrust
    double ddyThrust;           // Vertical acceleration due to thrust
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double v;                   // Total velocity
    int time;
    time = 1;
    aRadians = physics.calc_rads(aDegrees);

    // Go through the simulator five times
    for (int i = 0; i < 5; i++)
    {

        accelerationThrust = physics.calc_acc(THRUST, WEIGHT);
        ddxThrust = physics.calc_horz(aRadians, accelerationThrust);
        ddyThrust = physics.calc_vert(aRadians, accelerationThrust);
        ddx = ddxThrust;
        ddy = ddyThrust + GRAVITY;

        dx = physics.calc_vel(dx, ddx, t);
        dy = physics.calc_vel(dy, ddy, t);
        v = physics.calc_totcomp(dx, dy);

        x = physics.calc_dist(x, dx, ddx, t);
        y = physics.calc_dist(y, dy, ddy, t);

        // Output
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        cout << "Time: " << time;
        cout << "\n\tNew position: (" << x << ", " << y << ")m\n";
        cout << "\tNew velocity: (" << dx << ", " << dy << ")m/s\n";
        cout << "\tSpeed: " << v << "m/s\n";
        cout << "\tAngle: " << aDegrees << " Degrees\n\n";
        time++;
    }

    aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    aRadians = physics.calc_rads(aDegrees);

    for (int i = 0; i < 5; i++)
    {

        accelerationThrust = physics.calc_acc(THRUST, WEIGHT);
        ddxThrust = physics.calc_horz(aRadians, accelerationThrust);
        ddyThrust = physics.calc_vert(aRadians, accelerationThrust);
        ddx = ddxThrust;
        ddy = ddyThrust + GRAVITY;

        dx = physics.calc_vel(dx, ddx, t);
        dy = physics.calc_vel(dy, ddy, t);
        v = physics.calc_totcomp(dx, dy);

        x = physics.calc_dist(x, dx, ddx, t);
        y = physics.calc_dist(y, dy, ddy, t);

        // Output
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        //        cout << ddxThrust <<" "<< ddyThrust << " " << ddx << " " << ddy << " " << accelerationThrust;
        cout << "Time: " << time;
        cout << "\n\tNew position: (" << x << ", " << y << ")m\n";
        cout << "\tNew velocity: (" << dx << ", " << dy << ")m/s\n";
        cout << "\tSpeed: " << v << "m/s\n";
        cout << "\tAngle: " << aDegrees << " Degrees\n\n";
        time++;
    }

    return 0;
}