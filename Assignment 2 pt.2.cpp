// Author: CS1300 Fall 2017
// Recitation: 123 – Favorite TA
//
// Assignment 2

#include <iostream>

using namespace std;

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

int main()
{
    howLong(90061);

}
