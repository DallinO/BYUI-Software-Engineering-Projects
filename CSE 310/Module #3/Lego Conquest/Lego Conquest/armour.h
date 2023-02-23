/*******************************************************************************
* ARMOUR VEHICLE HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

class Armour : public Actor
{
public:
	Armour(string name) : Actor{name} {
		health = 150;
		movement = 2;
		moveReset = 2;
		minifigureDamage = 100;
		vehicleDamage = 75;
		aircraftDamage = 50;
		range = 2;
		cost = 250;
		type = "Vehicle";
		klass = "Armour";
		description = "Well rounded assualt vehicle.";
	}
};