/******************************************************************************
* 1. Name:
*      John Morton, Dallin Olson
* 2. Assignment Name:
*      Practice 06: C++ Files
* 3. Assignment Description:
*      This program demonstrates basin file reading and writing.
* 4. What was the hardest part? Be as specific as possible.
*	   The hardest part was learning how to set up the different for loops for
*      write and read.
* 5. How long did it take for you to complete the assignment?
*	   1 Hours
******************************************************************************/

#include <iostream>

using namespace std;

class Position
{
public:
	Position() {};
	int GetRow() { 
		try {
		
			return position / 8;
			throw (position);
		}
		catch (char position)
		{
			cout << "ERROR: Position out of range!";
			cout << position;
		}
	}
	int GetCol() { return position % 8; }
	void Set(int row, int column) { position = row * 8 + column; }
	void Display() { cout << position << endl;  }
private:
	char position;
};

class PositionTest {
public:
	Position pos;

	PositionTest() {}
	void SetNDisplayTest() {
		cout << "SET TEST" << endl;
		for (int x = 0; x <= 256; x++)
		{
			for (int y = 0; y <= 256; y++)
			{
				
				pos.Set(x, y);
				pos.Display();
				
			}
		}
		cout << "END OF TEST" << endl;
	}

	void GetTest() {
		cout << "GET TEST" << endl;
		pos.Set(1, 1);
		cout << "Position: ";
		pos.Display();
		cout << pos.GetCol() << pos.GetRow() << endl;
		cout << "END OF TEST" << endl;
	}
};

int main() {
	PositionTest post;
	post.SetNDisplayTest();
	post.GetTest();

	return 0;
}