/*******************************************************************************
* ACTOR HEADER FILE
*******************************************************************************/
#include <iostream>
#pragma once

using namespace std;

class Actor
{
protected:
	string name;
	string type;
	string klass;
	string description;
	int health;
	int movement;
	int range;
	bool isDead;
	int cost;
	
	int minifigureDamage;
	int vehicleDamage;
	int aircraftDamage;

public:
	Actor(string name) {
		this->name = name;
		isDead = false;
	}

	void ApplyDamage(int damage) {
		this->health -= damage;
		if (health <= 0)
			isDead = true;
	}

	void MoveActor(int spaces)		{ movement -= spaces; }
	void ResetMovement()			{}
	string GetName()				{ return name; }
	string GetClass()				{ return klass; }
	string GetType()				{ return type; }
	int GetHealth()					{ return health; }
	int GetMovement()				{ return movement; }
	int GetRange()					{ return range; }
	int GetMinifigureDamage()		{ return minifigureDamage; }
	int GetVehicleDamage()			{ return vehicleDamage; }
	int GetAircraftDamage()			{ return aircraftDamage; }
	string GetDescription()			{ return description; }
	bool GetIsDead()				{ return isDead; }
};