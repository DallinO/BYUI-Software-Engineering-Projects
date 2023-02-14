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
#include "uiInteract.h"
#include "lander.h"
#include "thrust.h"
using namespace std;

#define M_PI     3.14159265358979323846
#define WEIGHT   15103.000 // Weight in KG
#define GRAVITY  -1.625 // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000 // Thrust of main engine, in Newtons (kg m/s^2)
//class Lander;
//double  Thrust :: applyThrust() {
//        ddx = sin(angle) * -(THRUST / WEIGHT);
//        ddy = cos(angle) * (THRUST / WEIGHT);
//        dx += ddx;
//        dy += ddy;
//    }