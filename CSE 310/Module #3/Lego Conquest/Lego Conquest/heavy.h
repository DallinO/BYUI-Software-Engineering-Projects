/*******************************************************************************
* HEAVY HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

class Heavy : public Actor
{
public:
	Heavy(string name) : Actor{name } {
		health = 115;
		movement = 2;
		minifigureDamage = 75;
		vehicleDamage = 25;
		aircraftDamage = NULL;
		range = 1;
		cost = 150;
		type = "Minifigure";
		klass = "Heavy";
		description = "";
	}
};
