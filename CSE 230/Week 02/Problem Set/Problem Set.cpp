/******************************************************************************
* 1. Name:
*      John Morton, Dallin Olson
* 2. Assignment Name:
*      Practice 04: Vector and List
* 3. Assignment Description:
*      This program prompts the user for ten words to be stored inside a list.
*      The list contents are displayed in order and copied into a vector. The
*      vector contents are then displayed in reverse order.
* 4. What was the hardest part? Be as specific as possible.
*	   The hardest part was learning the proper syntax, methods and format to
*      iterate through the list and vector.
* 5. How long did it take for you to complete the assignment?
*	   1 Hours
******************************************************************************/
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<string> listData;
    vector<string> vectorData;
    string word;

    // #1 Prompt user for input
    cout << "Please enter 10 words:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "> ";
        // Store input
        cin >> word;
        // Add string to the list
        listData.push_back(word);
    }

    // #2 Display list contents & copy contects into the vector
    cout << "The data in listData displayed forwards is:" << endl;
    for (auto i = listData.cbegin(); i != listData.end(); ++i) {
        cout << "\t" << *i << endl;
    }

    // #3 Copy listData into vectorData
    for (auto i = listData.cbegin(); i != listData.end(); ++i) {
        vectorData.push_back(*i);
    }

    // #4 Display vector contents using the size() method0
    cout << "The data in vectorData displayed backwards is:" << endl;
    for (int i = vectorData.size() - 1; i >= 0; --i) {
        cout << "\t" << vectorData[i] << endl;
    }
}