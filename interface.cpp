/**
 * \brief handles all IO, IO::getInput returns an Object
 *
 */
#include <iostream>
#include <vector>
#include <cctype>
#include <unordered_set>
#include <algorithm>
#include "interface.hpp"
using namespace std;

bool parameters::setLength(string inLength)
{

    try
    {
        // try to convert the raw input into a string
        this->passwordLength = stoi(inLength);
    }
    catch (const std::exception &e)
    {
        // stoi() fails, print Error and return false to requery
        cerr << "\033[1m\033[31mInput may only consist of numbers\033[0m" << endl;
        return false;
    }
    return true;
}

bool parameters::populateVector(std::string &in)
{
    // populates a vector with unique numbers from 1 to 4, only add if not in vector already
    unordered_set<int> uniqueVals;
    // inserts all valid
    for (const char &c : in)
    {

        if (isdigit(c))
        {
            short int x = c - '0';
            // cout << x << "X in in\n";
            // check if element exists already in the set
            if (x == 0 || x > 4)
            {
                cerr << "\033[1m\033[31mOnly input numbers between 1 and 4!\033[0m" << endl;
                continue;
            }
            if (uniqueVals.find(x) == uniqueVals.end())
            {
                uniqueVals.insert(x);
                // cout << "Inserted: " << x << endl;
            }
        }
        else
        {
            cerr << "\033[1m\033[31mOnly input numbers!\033[0m" << endl;
            return false;
        }
    }
    // insert values from set into vector for further processing
    for (const int i : uniqueVals)
    {
        // cout << i << " ";
        this->charTypes.push_back(i);
    }
    // sort to make generating the final array later easier
    sort(charTypes.begin(), charTypes.end());
    // cout << endl;
    return true;
}

parameters::parameters()
{
    // do nothing
}
parameters IO::getInput()
{
    parameters *output = new parameters;
    string inputLength;
    string inputCharTypes;
    do
    {
        cout << "\033[2J\033[1;1H\033[1m\033[37mPlease enter the length of your password[1-255]: \033[0m" << endl;
        cin >> inputLength;

    } while (!output->setLength(inputLength));

    do
    {
        cout << "\033[2J\033[1;1HEnter the desired character Sets:\033[0m\n\033[48;5;238m[1] A-Z\033[0m\n\033[48;5;238m[2] a-z\033[0m\n\033[48;5;238m[3] 0-9\033[0m\n\033[48;5;238m[4] Special characters\033[0m\n"
             << endl;
        cin >> inputCharTypes;

    } while (!output->populateVector(inputCharTypes));

    return *output;
}

int IO::getNewPasswordLength()
{
    string inTmp;
    int val;
    do
    {
        cout << "\033[2J\033[1;1H\033[1m\033[37mPlease enter the length of your password[1-255]: \033[0m" << endl;
        cin >> inTmp;
        val = getNumber(inTmp);
    } while (!val == 0);
    return val;
}

int IO::getNumber(std::string in)
{
    try
    {
        // try to convert the raw input into a string
        int tmp = stoi(in);
        return tmp;
    }
    catch (const std::exception &e)
    {
        // stoi() fails, print Error and return false to requery
        cerr << "\033[1m\033[31mInput may only consist of numbers\033[0m" << endl;
        return 0;
    }
}

void IO::displayPassword(std::vector<std::string> &in)
{
    for (auto i : in)
   {
        cout << "" << i << "\033[0m" << endl;
   } 
    
}
