/**
 * \brief generates an Array based on input
 * computes size based on input
 * concats the subarrays
 * generates Password
 */

#include <random>
#include "generation.hpp"
#include "interface.hpp"
// used for random numbers
using namespace std;

Gen::Gen(parameters &in)
{
    PasswordSize = in.passwordLength;
    inputCharTypes = in.charTypes;
}

void Gen::setParams(parameters &in)
{
    this->PasswordSize = in.passwordLength;
    this->inputCharTypes = in.charTypes;
}

void Gen::computeArray()
{
    // generates the random Array and returns its size
    this->randomArray = "";
    int currentSize = 0;
    for (int i : this->inputCharTypes)
    {
        if (i > 4)
        {
            cerr << "inputCharTypes contains invalid types!" << endl;
            exit(EXIT_FAILURE);
        }
        currentSize += this->charTypes[i - 1].charSize;
        this->randomArray.append(this->charTypes[i - 1].charType);
    }
    this->randomArraySize = currentSize;
    
}

void Gen::generate()
{
    string password = "";
    computeArray();
    this->rng.setMaxDist(randomArraySize);
    for (int i = 0; i < PasswordSize; i++)
    {
        password += this->getRandomChar();
    }
    this->passwordHistory.push_back(password);
    IO::displayPassword(passwordHistory);
}

char Gen::getRandomChar()
{
    int tmp = this->rng.getRand();
    return this->randomArray[tmp];
}


int RNG::getRand()
{
    auto rand = distrib(gen);
    return rand;
}

void RNG::setMaxDist(int max)
{
    this->distrib = std::uniform_int_distribution<int>(0, max);
}

RNG::RNG() : gen(std::random_device()()), distrib(0, 1) {}

void Gen::resetPasswordHistory()
{
    this->passwordHistory.clear();
}

