/*******************************************************************************
* BUY HEADER FILE
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include "player.h"
#include "color.h"
#pragma once

using namespace std;

class Buy {
private:
	vector<int> minifigureCost = { 75, 150, 300, 500 };
	vector<int> vehicleCost = { 250, 550 };
	vector<int> aircraftCost = { 250, 600 };
	vector<string> minifigures;
	vector<string> vehicles;
	vector<string> aircraft;
	Color c;
public:
	Buy() {
		fstream file;

		file.open("minifigures.txt", ios::in);
		if (file.is_open()) {
			string minifigure;
			while (getline(file, minifigure)) {
				minifigures.push_back(minifigure);
			}
			file.close();
		}
		file.open("vehicles.txt", ios::in);
		if (file.is_open()) {
			string vehicle;
			while (getline(file, vehicle)) {
				vehicles.push_back(vehicle);
			}
			file.close();
		}
		file.open("aircraft.txt", ios::in);
		if (file.is_open()) {
			string airplane;
			while (getline(file, airplane)) {
				aircraft.push_back(airplane);
			}
			file.close();
		}
	}

	bool CheckFunds(int player, vector<Player>& players, int klassCost) {
		if (players[player].GetCredits() < klassCost) {
			cout << c.r + "\nNot enough credits!\n\n" + c.e;
			Sleep(2000);
			return false;
		}
		else
			return true;
	}

void GetInput(string& str, int& i, int max){
		while (true) {
			cout << c.y + ">>> "; cin >> i; cout << c.e;
			//i = stoi(str);
			if (i < 0 || i > max)
				cout << c.r + "Out of option range!\n" + c.e;
			else
				break;
		}
	}


	void Action(int player, vector<Player>& players) {

		string type;
		int t;
		string klass;
		int k;
		bool transaction;
		string num;
		int n;

		system("cls");
		cout << "-----BUY-----\n";
		cout << c.p + "TYPE:\n" + c.e; 
		cout << "1) Minifigure\n"
				"2) Vehicle\n"
				"3) Aircraft\n";
		GetInput(type, t, 3);

		/*** MINIFIGURE ***/
		if (t == 1) {
			int i = 1;
			for (string unit : minifigures) {
				cout << c.y << setw(3) << right << i << ") " + c.e << setw(30) << left << unit;
				if (i % 3 == 0)
					cout << endl;
				Sleep(10);
				i++;
			}
			cout << "\n\n";
			cout << "Select minifiure: ";
			GetInput(num, n, minifigures.size());

			cout <<
				c.c + "CLASS:\n" + c.e +
				"1) Assualt		 75 CR\n" 
				"2) Heavy		150 CR\n"
				"3) Scout		300 CR\n"
				"4) Officer		500 CR\n" << endl;
			GetInput(klass, k, 4);

			if (CheckFunds(player, players, minifigureCost[k - 1])) {
				players[player].AddUnit(minifigures, k, n - 1);
				players[player].RemoveCredits(minifigureCost[k - 1]);
			}
		}

		/*** VEHICLE ***/
		if (t == 2) {
			for (int i = 0; i < vehicles.size(); i++) {
				cout << i << ") " << vehicles[i] << endl;
				Sleep(10);
			}

			cout << "Select Vehicle: ";
			GetInput(num, n, vehicles.size());
			cout <<
				c.c + "CLASS:\n" + c.e +
				"1) Armour		250 CR\n"
				"2) Artillary	550 CR\n" << endl;
			GetInput(klass, k, 2);
			if (CheckFunds(player, players, vehicleCost[k - 1])) {
				players[player].AddUnit(vehicles, k, n - 1);
				players[player].RemoveCredits(minifigureCost[k - 1]);
			}
		}

		/*** AIRCRAFT ***/
		if (t == 3) {
			for (int i = 0; i < aircraft.size(); i++) {
				cout << i << ") " << aircraft[i] << endl;
				Sleep(10);
			}

			cout << "Select Aircraft: ";
			GetInput(num, n, aircraft.size());
			cout <<
				c.c + "CLASS:\n" + c.e +
				"1) Fighter		250 CR\n"
				"2) Bomber		600 CR\n" << endl;
			GetInput(klass, k, 2);
			if (CheckFunds(player, players, aircraftCost[k - 1])) {
				players[player].AddUnit(aircraft, k, n - 1);
				players[player].RemoveCredits(minifigureCost[k - 1]);
			}
		}
	}
};
