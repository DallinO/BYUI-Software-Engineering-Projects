/*******************************************************************************
* SCOUT HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

class Scout : public Actor
{
public:
	Scout(string name) : Actor{name } {
		health = 75;
		movement = 1;
		moveReset = 1;
		minifigureDamage = 150;
		vehicleDamage;
		aircraftDamage;
		range = 3;
		cost = 300;
		type = "Minifigure";
		klass = "Scout";
		description = "Scout";
	}
};
