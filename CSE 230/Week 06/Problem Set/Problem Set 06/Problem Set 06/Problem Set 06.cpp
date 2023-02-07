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
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/********************************
* WRITE NUMBERS
* Writes numbers to the file.
********************************/
void write_numbers(string fileName, vector<double> numbers)
{
    ofstream fout;
    ifstream fin;
    fout.open(fileName);
    if (fin.fail())
        return;

    for (auto num : numbers)
    {
        fout << num
            << "\n";
    }
    fin.close();
}


/********************************
* READ NUMBERS
* Read in numbers from the file.
********************************/
vector<double> read_numbers(string fileName)
{
    ofstream fout;
    ifstream fin;
    vector<double> numbers;

    fin.open(fileName);
    if (!fin.fail())
    {
        double num;
        while (fin >> num)
            numbers.push_back(num);
    }
    fin.close();
    return numbers;
}


/***********************************
* DISPLAY NUMBERS
* Displays the number from the file.
***********************************/
void DisplayNumbers(vector<double> num) {

    cout << "Account balance: $ "<< num[0] << endl;
}


/********************************
* UPDATE BALANCE
* Updates the file data.
********************************/
void UpdateBalance(string filename, vector<double> num) {

    double change;
    cout << "Change: $";
    cin >> change;
    num[0] += change;
    write_numbers(filename, num);
    num = read_numbers(filename);
    DisplayNumbers(num);
}


/********************************
* MAIN
********************************/
int main()
{
    ofstream fout;
    ifstream fin;
    vector<double> num = { 30.56 };
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    write_numbers(filename, num);
    num = read_numbers(filename);
    DisplayNumbers(num);
    UpdateBalance(filename, num);

    return 0;
}


