/*******************************************************************************
* PLAYER SOURCE FILE
*******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "actor.h"
#include "assault.h"
#include "heavy.h"
#include "scout.h"
#include "officer.h"
using namespace std;

class Player {
private:
	vector<Actor> army;
	int number;
	string name;
	int credits;
	int health;

public:
	Player(int number, string name) {
		this->number = number;
		this->name = name;
		health = 4000;
		credits = 0;
	}
	void AddCredits(int credits) { this->credits += credits; }
	void RemoveCredits(int credits) { this->credits -= credits; }
	int GetCredits() { return credits; }
	int GetNumber() { return number; }
	int GetHealth() { return health; }
	string GetName() { return name; }
	int GetArmySize() { return army.size(); }
	vector<Actor>& GetArmy() { return army; }
	void AddUnit(vector<string> unit, int klass, int name) {
		if (klass == 1) {
			Assault assualt(unit[name]);
			army.push_back(assualt);
		}
		else if (klass == 2) {
			Heavy heavy(unit[name]);
			army.push_back(heavy);
		}
		else if (klass == 3) {
			Scout scout(unit[name]);
			army.push_back(scout);
		}
		else if (klass == 4) {
			Officer officer(unit[name]);
			army.push_back(officer);
		}
	}
};
#endif