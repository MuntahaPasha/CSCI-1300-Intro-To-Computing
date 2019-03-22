// Muntaha Pasha: CS1300 Fall 2017
// Recitation:  – Camila
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

/**
 *To find days, you would do s/86,400
 *You will get a remainder, and you take that away from the total number of seconds
 *Then, to find the number of hours you would do s/3600
  *You take the remainder away from the total number of seconds again
 *To find minutes you would do s/60
 *Your remainder would then be the number of seconds leftover
 *Final function output should be expressed as cout of days, hours, minutes,
seconds.
*/


void howLong(int seconds)
{
    if(0 <= seconds && seconds <= 1000000)
    {
    int minutes;
    int days;
    int hours;
    int remainder;
    days = seconds/86400;
    remainder = seconds%86400;
    hours = remainder/3600;
    remainder = remainder%3600;
    minutes = remainder/60;
    remainder = remainder%60;
    seconds = remainder;

    cout<< "Time is: " << days << " days " << hours << " hours " << minutes << " minutes " << seconds << " seconds";

    return;
    }
}

/**
 *To Calculate Fahrenheit, perform function c*1.8+32
 *Operation Output will equal the temperature in Celsius.
 */

int howHot (int celcius)
    {

        int farenheit = celcius*1.8+32;

        return farenheit;
    }

int main() {
    int population = howMany(1000000);
    cout << "Population In A Year: " << population << endl;

    int celcius = howHot(20);
   cout<<"Celcius to Farenheit: " <<  celcius << endl;

    howLong(90061);
}
