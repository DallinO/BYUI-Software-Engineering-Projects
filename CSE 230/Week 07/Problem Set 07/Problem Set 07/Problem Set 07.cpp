/*************************************************************
 * 1. Name:
 *      -your name-
 * 2. Assignment Name:
 *      Practice 07: Templates
 * 3. Assignment Description:
 *      Two templates: one of a function, one of a class
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

/***************************************
 * PROMPT
 **************************************/
 template <typename T> void prompt(T& value, const char* message)
 {
     while (true)
     {
         // Instructions
         cout << message << ": ";
         cin >> value;
 
         // Check for error
         if (cin.fail())
         {
             cerr << "ERROR, try again\n";
             cin.clear();
             cin.ignore(256, '\n');
         }
         else
             return;
     }
 }


/***************************************
 * STACK
 **************************************/
 class Stack
{
public:
    Stack() : numElements(0) {}

    // Add an element to the stack
    template <typename T> void push(T value)
    {
        if (numElements < 10)
            data[numElements++] = value;
    }

    // Remove an element from the stack
    void pop()
    {
        if (numElements)
            numElements--;
    }

    // Retrieve the top-most element
    double top()
    {
        if (numElements)
            return data[numElements - 1];
        return -1.0;
    }

private:
    double data[10];
    int numElements;
};


/*********************************
 * MAIN
  ********************************/
int main()
{
    //
    // Test prompt
    //

    // prompt for a double
    //int valueInt;
    //double valueDouble;
    //char valueChar;
    //string valueString;
    //prompt(valueDouble, "Enter a double");
    //prompt(valueInt, "Enter a integer");
    //prompt(valueChar, "Enter a character");
    //prompt(valueString, "Enter a string");

    // prompt for a string

    // prompt for an integer

    //
    // Test stack
    //

    // a stack of doubles
    Stack stackDoubles;
    stackDoubles.push(1.1);
    stackDoubles.push(2.2);
    stackDoubles.push(3.3);
    stackDoubles.pop();
    stackDoubles.pop();
    cout << "The first element is: "
        << stackDoubles.top() << endl;

    Stack stackInts;
    stackInts.push(1);
    stackInts.push(2);
    stackInts.push(3);
    stackInts.pop();
    stackInts.pop();
    cout << "The first element is: "
        << stackInts.top() << endl;

  /*  Stack stackChars;
    stackChars.push("a");
    stackChars.push("b");
    stackChars.push("c");
    stackChars.pop();
    stackChars.pop();
    cout << "The first element is: "
        << stackChars.top() << endl;*/


    // a stack of strings

    // a stack of integers

    return 0;
}
/***************************************
 * PROMPT
 **************************************/


