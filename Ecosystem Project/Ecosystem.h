// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 8
// Ecosystem Header File

#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H
#include <string>
#include <iostream>
using namespace std;

/*USER IO Class:
* What my User IO Class is used for, is to interact with the user. Instead of writing all these cout statements over and over, and trying to read in files over
* and over again, by using User IO, I can just call the functions it uses in other classes, and make displaying and reading in information very easy.
*/
class UserIO
{
    public:
    UserIO(); //default constructor
    ~UserIO(); //destructor

    string promptUser(string); //a function used to ask the user something and take input.

    void displayUser(string); //Function used to show the user some kind of message.
    void displayArt(string); //Function used to display ASCII art.
    void setArrays(string []); //Function that sets up the arrays.


};

/*OCEAN Class:
* My Ocean class is used as a separate biome, with all of its separate features, like different animals that correlate with the ocean itself. I also have here
* all my scenarios and arrays to hold the information for the ocean class only. Arrays to hold counts for all my animals, and arrays to hold choices that have
* to do with the ocean.
*/
class Ocean
{
    public:

        Ocean(); //Default Constructor
        ~Ocean(); //Destructor

        float getOctopi(); //Getter for octopi
        void setOctopi(float); //Setter for octopi

        float getNumFish(); //Getter for Fish
        void setNumFish(float); //Setter for Fish

        float getShark(); //Getter for Shark
        void setShark(float); //Setter for Shark

        float getPlankton(); //Getter for Plankton
        void setPlankton(float); //Setter for Plankton

        float getCoral(); //Getter for Coral
        void setCoral(float); //Setter for Coral

        void resestArrays(float); //Function to reset arrays at end of game

        void process(); //Function used to define the actions, and initialize game play



    private:
        //each array of animals will hold up to a max of 10 values as the game goes on
        float oceanAnimals[5][5]; //Two D array holding count of each animal and the stage
        string choices[6]; //Array of choices to be asked
        string actions[6]; //Array of actions to be performed
        string choiceToAction[6]; //Array of choices corresponding to given actions
        int stages[6]; //Array of stages
        string elements[5]; //Ocean animals, "Sharks", "Octopi", etc,


        int stage; //A variable used to hold the stage number

        void initializeGameplay(); //Initializing a game play function which will be responsible for carrying out most of the game

        UserIO userIO; //an object of user IO specifically made for Ocean


};

/*TERRAIN Class:
* My Terrain class is used as a separate biome, with all of its separate features, like different animals that correlate with the terrain itself. I also have here
* all my scenarios and arrays to hold the information for the terrain class only. Arrays to hold counts for all my animals, and arrays to hold choices that have
* to do with the terrain.
*/
class Terrain
{
    public:

        Terrain(); //default constructor
        ~Terrain(); //destructor

        float getWolves(); //getter for Wolves
        void setWolves(float); //setter for Wolves

        float getRabbits(); //getter for Rabbits
        void setRabbits(float); //setter for Rabbits

        float getHawk(); //getter for Hawks
        void setHawk(float); //setter for Hawks

        float getFieldMouse(); //getter for Field Mice
        void setFieldMouse(float); //setter for Field Mice

        float getShrubs(); //getter for Shrubs
        void setShrubs(float); //setter for Shrubs

        void resestArrays(float); //Resets the arrays values back to 0 at the end of the game.

        void process(); //Process is the function used to guide the game.


    private:

    //each array of animals will hold up to a max of 10 values as the game goes on
        float terrainAnimals[5][5]; //Two D array holding count of each animal and the stage
        string choices[6]; //Array of choices to be asked
        string actions[6]; //Array of actions to be performed
        string choiceToAction[6]; //Array of choices corresponding to given actions
        int stages[6]; //Array of stages
        string elements[5]; //Terrain animals, "Wolves", "Hawks", etc,


        int stage; //A variable used to hold the stage number

        void initializeGameplay(); //Initializing a game play function which will be responsible for carrying out most of the game

        UserIO seconduserIO; //an object of user IO specifically made for Terrain
};

#endif

