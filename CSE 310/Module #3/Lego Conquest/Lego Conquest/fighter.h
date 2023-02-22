/*******************************************************************************
* FIGHTER VEHICLE HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

class Fighter : public Actor
{
public:
	Fighter(string name) : Actor{name} {
		health = 100;
		movement = 3;
		minifigureDamage = 75;
		vehicleDamage = 50;
		aircraftDamage = 50;
		range = 2;
		cost = 250;
		type = "Aircraft";
		klass = "Fighter";
		description = "Fighter.";
	}
};
