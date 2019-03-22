// Author: CS1300 Fall 2017
// Recitation: 123 – Favorite TA
//
// Assignment 2

#include <iostream>

using namespace std;

/**
 *To Calculate Fahrenheit, perform function c*1.8+32
 *Operation Output will equal the temperature in Celsius.
 */

int howHot (int celcius)
    {

        int farenheit = celcius*1.8+32;

        return farenheit;
    }

int main()
{
    int celcius = howHot(20);
   cout<<"Celcius to Farenheit: " <<  celcius << endl;
}
