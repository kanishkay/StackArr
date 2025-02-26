// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "Stack.h"

using namespace std;

int main() {
    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;
    string command;        // operation to be executed

    char item;
    Stack<char> stack;
    int numCommands;


    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return." << endl;
    cin >> outputLabel;
    outFile << outputLabel << endl;

    inFile >> command;


    try {
        stack.Push(5);      // Can throw an instance of full stack
    }
    catch (FullStack error){

    }
    numCommands = 0;
    while (command != "Quit") {
        try {
            if (command == "Push") {
                inFile >> item;
                stack.Push(item);
            } else if (command == "Pop")
                stack.Pop();
            else if (command == "Top") {
                item = stack.Top();
                outFile << "Top element is " << item << endl;
            } else if (command == "IsEmpty")
                if (stack.IsEmpty())
                    outFile << "Stack is empty." << endl;
                else
                    outFile << "Stack is not empty." << endl;

            else if (command == "IsFull")
                if (stack.IsFull())
                    outFile << "Stack is full." << endl;
                else outFile << "Stack is not full." << endl;
            else
                outFile << command << " not found" << endl;
        }
        catch (FullStack error) {
            outFile << "FullStack exception thrown." << endl;
        }
        catch (EmptyStack) {
            outFile << "EmptyStack exception thrown." << endl;
        }
        numCommands++;
        cout << " Command number " << numCommands << " completed."
             << endl;
        inFile >> command;

    };

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}


