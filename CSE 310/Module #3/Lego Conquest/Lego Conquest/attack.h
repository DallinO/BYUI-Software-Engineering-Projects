/*******************************************************************************
* ATTACK HEADER FILE
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "color.h"
#include <Windows.h>
#pragma once

using namespace std;

class Attack {
public:
	int targetPlayer;
	int attackingUnit;
	int targetUnit;
	Color c;


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
				return stoi(unit)-1;
		}
	}


	/***************************************
	* APPLY DAMAGE
	***************************************/
	void ApplyDamage(int player, vector<Player>& players)
	{
		if (players[targetPlayer].GetArmy()[targetUnit].GetType() == "Minifigure") {
			players[targetPlayer].GetArmy()[targetUnit].ApplyDamage(players[player].GetArmy()[attackingUnit].GetMinifigureDamage());
		}
		else if (players[targetPlayer].GetArmy()[targetUnit].GetType() == "Vehicle") {
			players[targetPlayer].GetArmy()[targetUnit].ApplyDamage(players[player].GetArmy()[attackingUnit].GetVehicleDamage());
		}
		else if (players[targetPlayer].GetArmy()[targetUnit].GetType() == "Aircraft") {
			players[targetPlayer].GetArmy()[targetUnit].ApplyDamage(players[player].GetArmy()[attackingUnit].GetAircraftDamage());
		}

		// Check if the target was killed
		if (players[targetPlayer].GetArmy()[targetUnit].GetIsDead())
		{
			// Remove the killed unit from the target
			// players army
			players[targetPlayer].GetArmy().erase(players[targetPlayer].GetArmy().begin() + (targetUnit - 1));

		}

		cout << players[player].GetArmy()[attackingUnit].GetName() << "attacked " << players[targetPlayer].GetArmy()[targetUnit].GetName() << endl;
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
				cin >> targetPlayer;
				if (CheckUnits(players, targetPlayer))	
				{
					// Select target unit
					cout << "Select unit to attack: \n";
					targetUnit = SelectUnit(players, targetPlayer);
					ApplyDamage(player, players);
				}
			}

			// If there are only two players than the target
			// player is automatically selected
			else {
				if (player == 0)
					targetPlayer = 1;
				else
					targetPlayer = 0;
				if (CheckUnits(players, targetPlayer)) {
					// Select target unit
					cout << "Select unit to attack: \n";
					targetUnit = SelectUnit(players, targetPlayer);
					ApplyDamage(player, players);
				}
			}
		}	
	}
};
