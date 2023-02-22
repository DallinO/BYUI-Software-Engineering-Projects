/*******************************************************************************
* DIRECTOR SOURCE FILE
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "player.h"
#include "buy.h"
#include "attack.h"
#include "color.h"


using namespace std;

class Director {
private:
	int numPlayers;
	vector<Player> players;
	string action;
	int a;
	Attack attack;
	Buy buy;
	Attack att;
	Color c;
public:
	void RunGame() {

		/*** SET UP ***/
		cout << "Enter the number of players ";
		cout << c.y + ">>> "; cin >> numPlayers; cout << c.e;
		for (int i = 1; i <= numPlayers; i++)
		{
			string name;
			cout << c.e + "Enter the name of player " << i;;
			cout << c.y + "  >>> "; cin >> name; cout << c.e;
			Player user(i, name);
			players.push_back(user);
		}

		/*** MAIN LOOP ***/
		int day = 0;
		while (true) {

			for (int i = 0; i < numPlayers; i++) {
				players[i].AddCredits(150);
				while (true) {
					system("cls");
					/*** PRINT PLAYER DATA ***/
					cout << c.c + "\nDay: " << day << c.e + "\n";
					cout << "Player " << i + 1 << "'s turn...\n";
					cout << "-----------------\n"
						<< "NAME   : " + c.c << players[i].GetName() << c.e + "\n"
						<< "HEALTH : " + c.c << players[i].GetHealth() << c.e + "\n"
						<< "CR     : " + c.g << players[i].GetCredits() << c.e + "\n"
						<< "UNITS  : \n";
					cout << "   " << setw(25) << left << "NAME"
						<< setw(10) << left << "CLASS"
						<< setw(10) << left << "HEALTH"
						<< setw(10) << left << "MOVES"
						<< setw(10) << left << "RANGE" << endl;
					for (Actor unit : players[i].GetArmy())
						cout << "   " << setw(25) << left << unit.GetName() 
							 << setw(10) << left << unit.GetClass() 
							 << setw(10) << left << unit.GetHealth() 
							 << setw(10) << left << unit.GetMovement()
						     << setw(10) << left << unit.GetRange() << endl;
					cout << "-----------------\n";

					/*** SELECT ACTION ***/
					cout << "Select an option: \n"
						"1) Move\n"
						"2) Attack\n"
						"3) Buy\n"
						"4) End Turn\n"
						"5) Quit\n";

					while (true) {
						cout << c.y + ">>> "; cin >> action; cout << c.e;
						a = stoi(action);
						if (a < 1 || a > 5)
							cout << "Out of option range!";
						else
							break;
					}
					if (a == 1)
						continue;
					//Move(i, players);
					else if (a == 2)
						att.Action(i, players, numPlayers);
					else if (a == 3)
						buy.Action(i, players);
					else if (a == 4)
						break;
					else if (a == 5)
						exit(0);
				}
			}
			day++;
		}
	}

	/***************************************
	* MOVE
	***************************************/
	void Move(int user, vector<Player> players){}



};
