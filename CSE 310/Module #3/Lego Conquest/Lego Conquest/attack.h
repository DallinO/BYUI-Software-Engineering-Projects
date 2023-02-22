/*******************************************************************************
* ATTACK HEADER FILE
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "color.h"
#pragma once

using namespace std;

class Attack {
public:
	int targetplayer;
	int attackingUnit;
	int targetUnit;
	Color c;


	/***************************************
	* CHECK UNITS
	***************************************/
	bool CheckUnits(vector<Player>& players, int player) {
		if (players[player].GetArmySize() == 0) {
			cout << "No units to move!" << endl;
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
				return stoi(unit)-1;
		}
	}


	/***************************************
	* ACTION
	* Summary:
	*	Facilitates all actions neccissary
	*	to performing the attack procedure
	***************************************/
	void Action(int player, vector<Player>& players, int numplayers){
		
		// Check if the attacking player has any units
		if (CheckUnits(players, player)) {


			// Select attacking unit
			cout << "Select attacking unit: \n";
			attackingUnit = SelectUnit(players, player);


			// If there are more than 2 players then select
			// the player to attack
			if (numplayers > 2) {
				cout << "Enter the player to attack: ";
				cin >> targetplayer;


				// Select target unit
				cout << "Select unit to attack: \n";
				targetUnit = SelectUnit(players, targetplayer);
			}

			// If there are only two players than the target
			// player is automatically selected
			else {
				if (player == 0)
					targetplayer = 1;
				if (player == 1)
					targetplayer = 0;

				// Select target unit
				cout << "Select unit to attack: \n";
				targetUnit = SelectUnit(players, targetplayer);
			}

			// Apply damage based on the target unit type
			if (players[targetplayer].GetArmy()[targetUnit].GetType() == "Minifigure") {
				players[targetplayer].GetArmy()[targetUnit].ApplyDamage(players[player].GetArmy()[attackingUnit].GetMinifigureDamage());
			}
			else if (players[targetplayer].GetArmy()[targetUnit].GetType() == "Vehicle") {
				players[targetplayer].GetArmy()[targetUnit].ApplyDamage(players[player].GetArmy()[attackingUnit].GetVehicleDamage());
			}
			else if (players[targetplayer].GetArmy()[targetUnit].GetType() == "Aircraft") {
				players[targetplayer].GetArmy()[targetUnit].ApplyDamage(players[player].GetArmy()[attackingUnit].GetAircraftDamage());
			}

			// Check if the target was killed
			if (players[targetplayer].GetArmy()[targetUnit].GetIsDead())
			{
				// Remove the killed unit from the target
				// players army
				players[targetplayer].GetArmy().erase(players[targetplayer].GetArmy().begin() + (targetUnit - 1));

			}
		}

		cout << players[player].GetArmy()[attackingUnit].GetName() << "attacked " << players[targetplayer].GetArmy()[targetUnit].GetName() << endl;
	}
};
