/*************************************************************
 * 1. Name:
 *      Dallin Olson & John Morton
 * 2. Assignment Name:
 *      Practice 08 Pointers
 * 3. Assignment Description:
 *      This program demonstrates the basic use of pointers by
 *		creating a new pointer, passing in the address of
 *		another variable, and then dereferencing the pointer to
 *		perform data manipulation.
 * 4. What was the hardest part? Be as specific as possible.
 *      There were no issues completing this assignment.
 * 5. How long did it take for you to complete the assignment?
 *      1 hour.
 **************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	double accountSam;
	double accountSue;
	double* pAccount;
	double dinner;
	double movie;
	double iceCream;

	cout << "What is Sam's account balance? $";
	cin >> accountSam;
	cout << "What is Sue's account balance? $";
	cin >> accountSue;

	cout << "Cost of the date:\n";
	cout  << setw(12) << left << "\tDinner:" << "$";
	cin >> dinner;
	cout  << setw(12) << left << "\tMovie:" << "$";
	cin >> movie;
	cout  << setw(12) << left << "\tIce Cream:" << "$";
	cin >> iceCream;

	if (accountSam > accountSue)
		pAccount = &accountSam;
	else
		pAccount = &accountSue;

	*pAccount -= (dinner + movie + iceCream);
	
	cout << "Sam's balance: " << accountSam << endl;
	cout << "Sue's balance: " << accountSue << endl;

	return (0);

}
