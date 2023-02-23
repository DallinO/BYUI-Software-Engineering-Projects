/*******************************************************************************
* CHECKNSELECT HEADER FILE
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "color.h"
#include <Windows.h>
#pragma once

using namespace std;

class CheckNSelect {
protected:
	Color c;
public:

	/***************************************
	* CHECK UNITS
	***************************************/
	bool CheckUnits(vector<Player>& players, int player) {
		if (players[player].GetArmySize() == 0) {
			system("cls");
			cout << c.r + "No units available!" + c.e << endl;
			Sleep(2000);
			return false;
		}
		else
			return true;
	}


	/***************************************
	* SELECT UNIT
	***************************************/
	int SelectUnit(vector<Player>& players, int player) {
		string unit;
		int u = 1;
		for (Actor actor : players[player].GetArmy()) {
			cout << u << ") " << actor.GetName() << endl;
			u++;
		}
		while (true) {
			cin >> unit;
			u = stoi(unit);
			if (u > players[player].GetArmySize() || u < 1)
				cout << c.r + "Out of option range!" + c.e;
			else
				return stoi(unit) - 1;
		}
	}
};
