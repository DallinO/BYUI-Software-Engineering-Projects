/*******************************************************************************
* ACTOR HEADER FILE
*******************************************************************************/
#include <iostream>
#include "actor.h"
#pragma once

using namespace std;

Actor::Actor(string name) {
	this->name = name;
	isDead = false;
}

void Actor::ApplyDamage(int damage) {
	health -= damage;
	if (health <= 0)
		isDead = true;
}

