#ifndef COLOR_H
#define COLOR_H

#include <string>
#pragma once

using namespace std;

class Color {
public:
	string p = "\033[95m";
	string b = "\033[94m";
	string c = "\033[96m";
	string g = "\033[92m";
	string y = "\033[93m";
	string r = "\033[91m";
	string e = "\033[0m";
};
#endif
