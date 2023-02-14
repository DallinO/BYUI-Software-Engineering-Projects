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
#include "point.h"
#include "velocity.h"
#include "acceleration.h"
#include "uiDraw.h"
using namespace std;

class Star {
	Point pt;
	char phase;

	Star(){}
	void Reset(int width, int height){}
	void Draw(ogstream gout){}
};
