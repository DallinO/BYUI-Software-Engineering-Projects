/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/
#define GRAVITY     -1.625
#define LM_WIDTH	20.0

#pragma once
#include <iostream>

 /*********************************************
  * POINT
  * A single position.
  *********************************************/
class LM {
public:
    LM() {
	}


	double fuel = 5000;
	double counter;



	void burnFuel() {
		fuel = fuel - 10;
	}

	void burnRotateFuel() {
		fuel = fuel - 1;
	}

	
};