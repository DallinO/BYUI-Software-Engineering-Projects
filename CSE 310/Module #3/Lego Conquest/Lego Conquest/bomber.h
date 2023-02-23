/*******************************************************************************
* BOMBER VEHICLE HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

class Bomber : public Actor
{
public:
	Bomber(string name) : Actor{name} {
		health = 250;
		movement = 1;
		moveReset = 1;
		minifigureDamage = 100;
		vehicleDamage = 100;
		aircraftDamage = NULL;
		range = 1;
		cost = 600;
		type = "Aircraft";
		klass = "Bomber";
		description = "Bomber\nCan target the tile it is over.\nDeals damage to all entities on the tile.";
	}
};
