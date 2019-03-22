// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 8
// Ecosystem Main File
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Ecosystem.h"

using namespace std;

/*Display Text Function:
* Display function is a function I'm using in my main to display a file full of information about my ecosystem that I want the user to be able to see.
* It reads in a file, and outputs the contents line by line.
* It's used to just display the text from the file onto the screen.
*/
    void displayText(string file)
{
    string str;
    ifstream inputfile; //Inputting the file
    inputfile.open(file); //Opening the file

    if(!inputfile.is_open()) //If file can't open
    {
        cout<<"File could not open"<<endl; //Then cout << "File can't open"
        return; //return after that
    }

    while(!inputfile.eof()) //if it does open, and you're not at the end of the file
    {
        getline(inputfile, str); //read each line in, line by line
        cout<<str<<endl; //display each line of the file
    }
}

int main()
{
    UserIO userIO; //an object of user IO to be used in main

    userIO.displayUser("Welcome to Ecosystem Simulator!"); //calling my display user function to output this on the screen.
    //prompt user is going to ask the user the main menu sequence, and take some sort of value, for the number they want. Convert it to an integer.
    int value= stoi(userIO.promptUser("Would you like to play Ocean or Terrain? Enter 0 for Ocean and 1 for Terrain. If you would like to read more information on the Ecosystem Simulator and its purpose, press 2."));
    if(value==0) //if the value is zero
    {
        Ocean ocean; //execute the ocean class
        while(1)
        {
        ocean.process(); //used to prevent the program from closing
        usleep(10000);
        }
    }
    else if(value==1) //if the value is one
    {
        Terrain terrain; //execute the terrain class
        while(2)
        {
            terrain.process(); //used to prevent program from closing, so it keeps running
            usleep(10000);
        }
    }
    else if(value==2) //if they press 2
    {
        displayText("/home/user/Desktop/All_Assignments/Eco_Info.txt"); //open the text file with the information.
    }
}
