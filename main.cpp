#include "interface.hpp"
#include "generation.hpp"

// #pragma once
using namespace std;

int main(void)
{
    // gets the parameters
    parameters input = IO::getInput();
    // creates a Generator
    Gen generator(input);
    // generate and print Password
    generator.generate();
    // this should go into interface.cpp
    while (true)
    {
        char cinput;
        cout << "\033[1m\033[32mSelect Next Action: \033[0m\n[r] regenerate\n[x] reconfigure\n[e] \033[31mExit Program\033[0m" << endl;
        cin >> cinput; 

        switch (tolower(cinput))
        {
        case 'r':
        {
            cout << "\033[2J\033[1;1H\033[1m\033[37mPassword:\n";
            generator.generate();
            cout << "\033[0m" << endl;
            break;
        }
        case 'e':
        {
            cout << "\033[JExiting " << endl;
            exit(EXIT_SUCCESS);
            break;
        }
        case 'x':
        
            cout << "\033[2J\033[1;1H\033[1m\033[37mRESETTING\033[0m\n";
            input = IO::getInput();
            // creates a Generator
            generator.setParams(input);
            // generate and print Password
            generator.resetPasswordHistory();
            generator.generate();
            break;
        
        default:
            cout << "\033[JInvalid! " << endl;
            break;
        }
    }
}