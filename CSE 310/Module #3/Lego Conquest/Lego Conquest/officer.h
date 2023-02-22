/*******************************************************************************
* OFFICER HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

class Officer : public Actor
{
public:
	Officer(string name) : Actor{name} {
		health = 200;
		movement = 2;
		minifigureDamage = 150;
		vehicleDamage = 50;
		aircraftDamage = NULL;
		range = 2;
		cost = 500;
		type = "Minifigure";
		klass = "Officer";
		description = "Officer\nIt must be desperate times if officers are fighting.";
	}
};
