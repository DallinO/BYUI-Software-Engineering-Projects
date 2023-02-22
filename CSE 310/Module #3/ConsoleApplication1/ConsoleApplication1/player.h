/*******************************************************************************
* PLAYER SOURCE FILE
*******************************************************************************/
#include <iostream>
#include <vector>
#include "actor.h"

using namespace std;

class Player {
private:
	vector<Actor> army;
	int number;
	string name;
	int credits;
	int health;

public:
	Player(int number, string name) {}
	void Addcredits(int credits) { this->credits += credits; }
	void Removecredits(int credits) { this->credits -= credits; }
	int GetCredits() { return credits; }
	int GetNumber() { return number; }
	int GetHealth() { return health; }
	string GetName() { return name; }
	int GetArmySize() { return army.size(); }
	vector<Actor> GetArmy() { return army; }
	void AddUnit(vector<string> unit, int klass, int name) {}
};

