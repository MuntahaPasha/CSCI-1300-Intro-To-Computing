// Author: CS1300 Fall 2017
// Recitation: 123 – Favorite TA
//
// Assignment 2

#include <iostream>

using namespace std;

/**
 * Algorithm description for function howMany() goes here
 * Outputs Current Population based on three rates
 * b.r: every 8 secs, d.r: every 12 secs, i.r: 33 secs
 * Returns Population in Year
 */
int howMany(int population)
{
    int birthrate;
    int deathrate;
    int immigrationrate;
    int secondsinyear;


    secondsinyear = 31536000;
    birthrate = secondsinyear/8;
    deathrate = secondsinyear/12;
    immigrationrate = secondsinyear/33;

    int howMany = population + birthrate + immigrationrate - deathrate;
    return howMany;
}

int main()
{
    int population = howMany(1000000);
    cout << "Population In A Year: " << population << endl;

}
