#pragma once
#include "interface.hpp"

#include <random>

typedef struct
{
    std::string charType;
    int charSize;
} CharType;

class RNG
{
public:
    RNG();
    void setMaxDist(int max);
    int getRand();

private:
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
};

class Gen
{
private:
    // requires an Object to work

    RNG rng;

    const CharType charTypes[4] =
        {
            {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26},
            {"abcdefghijklmnopqrstuvwxyz", 26},
            {"0123456789", 10},
            {"!#$%&()*+,-./:;<=>?@", 20}};

    std::vector<int> inputCharTypes;
    

    int PasswordSize;
    

    int randomArraySize;
    std::string randomArray;
    char getRandomChar();

public:
    std::vector<std::string> passwordHistory;
    Gen(parameters &in);
    void computeArray();
    void generate();
    void setParams(parameters &in);
    void resetPasswordHistory();
};
