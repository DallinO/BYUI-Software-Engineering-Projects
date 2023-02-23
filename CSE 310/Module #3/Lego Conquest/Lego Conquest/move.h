/*******************************************************************************
* MOVE HEADER FILE
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "color.h"
#include "checknselect.h"
#include <Windows.h>
#pragma once

using namespace std;

class Move : CheckNSelect {
private:
	Color c;
	int unit;
	int spaces;
public:

	void ResetMoves(int player, vector<Player>& players) {
		for (Actor unit : players[player].GetArmy())
			unit.ResetMovement();
	}

	void Action(int player, vector<Player>& players) {
		if (CheckUnits(players, player)) {

			// Select unit
			cout << "Select unit to move: \n";
			unit = SelectUnit(players, player);
			cout << "Spaces: \n";
			while (true) {
				cout << c.y + ">>> "; cin >> spaces; cout << c.e;
				if (spaces > players[player].GetArmy()[unit].GetMovement())
					cout << c.r + "Not enough movements available!" + c.e << endl;
				else {
					players[player].GetArmy()[unit].MoveActor(spaces);
					break;
				}
			}
		}
	}
};
