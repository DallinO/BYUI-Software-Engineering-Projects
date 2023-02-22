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
	Actor(string name);
	void ApplyDamage(int damage);
	void MoveActor(int spaces) { movement -= spaces; }
	void ResetMovement();
	string GetName() { return name; }
	string GetClass() { return type; }
	int GetMovement() { return movement; }
	int GetMinifigureDamage() { return minifigureDamage; }
	int GetVehicleDamage() { return vehicleDamage; }
	int GetAircraftDamage() { return aircraftDamage; }
	string GetDescription() { return description; }
	bool GetIsDead() { return isDead; }
};