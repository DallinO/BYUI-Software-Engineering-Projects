/*******************************************************************************
* ASSAULT HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

class Assault : public Actor
{
public:
	Assault(string name) : Actor{name } {
		health = 100;
		movement = 2;
		moveReset = 2;
		minifigureDamage = 50;
		vehicleDamage = 10;
		aircraftDamage = NULL;
		range = 2;
		cost = 75;
		type = "Minifigure";
		klass = "Assualt";
		description = "Your basic grunt.";
	}
};