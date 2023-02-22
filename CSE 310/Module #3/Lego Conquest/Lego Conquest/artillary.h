/*******************************************************************************
* ARTILLARY VEHICLE HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

class Artillary : public Actor
{
public:
	Artillary(string name) : Actor{name} {
		health = 225;
		movement = 1;
		minifigureDamage = 100;
		vehicleDamage = 75;
		aircraftDamage = NULL;
		range = 3;
		cost = 550;
		type = "Vehicle";
		klass = "Artillary";
		description = "Deals damage to all entities on a single tile.\nCan not target tiles immediatly adjacent.";
	}
};
