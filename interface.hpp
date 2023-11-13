#pragma once

#include <iostream>
#include <vector>

class parameters
{
    /**
     * \brief   object that is returned after calling getInput()
     * @var uint8_t $passwordLength
     *          Length of the password
     * @var std::vector $charTypes
     *          sorted Vector containing the
     *
     */

public:
    unsigned int passwordLength = 0;
    std::vector<int> charTypes;
    parameters();
    bool setLength(std::string inLength);
    bool populateVector(std::string &in);
};

class IO
{
public:
    static parameters getInput();
    static int getNewPasswordLength();
    static void displayPassword(std::vector<std::string> &in);
    static void getAction();

private:
    static int getNumber(std::string in);
};

