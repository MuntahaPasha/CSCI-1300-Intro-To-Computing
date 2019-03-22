// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 8
// Ecosystem CPP File

#include <iostream>
#include <fstream>
#include <string>
#include "Ecosystem.h"

using namespace std;

UserIO::UserIO()
{
    //Default constructor for User IO
}
UserIO::~UserIO()
{
    //Destructor for User IO
}

/*Display Art Function
* Display art takes in a file, and it displays the contents of that to the user.
* I used this function specifically for my ASCII art, for the Ocean and Terrain Biomes.
* It merely reads the file and does nothing else with it except for displaying it.
* If it does not open it will explicitly state that. Otherwise, it will use getline to read the file in.
* Then using a user display function, used merely for "cout" statements, it will display the contents.
*/
void UserIO::displayArt(string file)
{
    string str;
    ifstream inputfile; //variable for file input
    inputfile.open(file); //opens the file

    if(!inputfile.is_open()) //if file doesn't open
    {
        cout<<"File could not open"<<endl; //tell us that it didn't open
        return;
    }

    while(!inputfile.eof()) //if it DID open, then make sure you're not at the end of file... if you're not, then...
    {
        getline(inputfile, str); //read in each line, store them into str
        displayUser(str); //use display user to cout<<str and display the image line by line
    }
}

/*Display User Function:
* Display user just takes in any string, and it outputs that sentence to the user.
* I just thought it'd be an easy function to make so you can call it every time you want to display something instead of always using a cout.
*/
void UserIO::displayUser(string sentence)
{
    cout<<sentence<<endl; //takes in parameter of string, then displays that string.
}

/*Prompt User Function:
* Prompt user just serves to take input from the user.
* It'll ask a sentence and then take input.
* Then, it will return input.
*/
string UserIO::promptUser(string sentence)
{
    string temp; //Temp to hold string
    cout<<sentence<<endl; //it will display whatever the sentence in the parameter is
    cin>>temp; //whatever the user inputs, it will store it into the temp variable

    return temp; //return whatever the user inputted
}

//Default Constructor
Ocean::Ocean()
{
    //Here you will want to initialize all the variables, and use your setters.
    stage=0;
    //initializing all arrays to zero.
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
               oceanAnimals[i][j]=0; //make sure to fill the array with zero's.
        }
    }

    userIO.displayArt("pic.txt"); //input the file that displays the art.

    userIO.displayUser("Pick and Choose your animals. You MUST pick a number greater than 30 for each."); //This calls display to ask the question

    setNumFish(stof(userIO.promptUser("How many fish would you like to start with?"))); //use a setter to store what the value is for Fish.

    setOctopi(stof(userIO.promptUser("How many octopi would you like to start with?"))); //use a setter to store what the value is for Octopi.

    setCoral(stof(userIO.promptUser("How many coral would you like to start with?"))); //use a setter to store what the value is for Coral.

    setShark(stof(userIO.promptUser("How many sharks would you like to start with?"))); //use a setter to store what the value is for Sharks.

    setPlankton(stof(userIO.promptUser("How many plankton would you like to start with?"))); //use a setter to store what the value is for Plankton.

    initializeGameplay(); //Call the initialize game play function.

}

/*Initialize Gameplay Function:
* What this function does, is the real game play scenarios.
* Here you define all of your arrays from the h file, you define what goes into every spot of the array responsible for guiding the game.
* I defined all my stages array, which spans over 6 stages of the game, meaning 6 scenarios.
* I initialized all values in that array from 0 to 6.
* Next was my choices array. What my choices array did, was it holds all the scenarios, which are strings of different questions being asked to the user.
* I initialized 6 of them because there's 6 total stages. We don't want more, or less.
* My Actions array is responsible for holding the strings that correlate to what function will be carried out.
* If the scenario means an animal will die, or population will grow, I have addition and subtraction stored into my action array as strings that can later be
* used as actual function names to perform whatever type of function it is that they dictate.
* What choice to action does, is it holds whatever action is being performed according to the choice. So position 0 in choice to Action just means choice 0,
* and choice 0 corresponds to addition, so it will hold action #3, addition!
* Finally, I have an elements array which simply holds a member of the ecosystem in each of the provided slots.
*/
void Ocean::initializeGameplay()
{
    //Here is where I initialize all of my stages, from 0 to 5, making 6 stages. Each stage corresponds with what question is asked. To keep things simple...
    //I made it so that stage 0 associates with choice 0. And so on, and so on.
    stages[0]=0; //stage 0 will ask choice 0.
    stages[1]=1; //stage 1 will ask choice 1.
    stages[2]=2; //stage 2 will ask choice 2.
    stages[3]=3; //stage 3 will ask choice 3.
    stages[4]=4; //stage 4 will ask choice 4.
    stages[5]=5; //stage 5 will ask choice 5.

    //my choices array is straight forward, it holds each question the user must answer in the simulation.
    choices[0]="Your ecosystem is thriving! Choose one species to populate";
    choices[1]="An oil spill happened! Choose one species to conserve. (Note that all other species will go down in number)";
    choices[2]="Uh oh. Overfishing has occurred. Choose one species to deplete.";
    choices[3]="Coral Reef infected. Press 3";
    choices[4]="Thanks to some rescue efforts the ecosystem is doing better! More growth! (Choose a species)";
    choices[5]="Industrial Pollution seeps into ocean waters. Pick one species to conserve";

    //Actions array merely lists out what action will be performed. Whether it will lead to addition of some animal, subtraction of some animal, or conservation
    //of some animal, this merely dictates what action will be carried out on whatever animal the user picks.
    actions[0]="multiply"; //multiply in this simulation really just acts like addition.
    actions[1]="subtract"; //subtracts from an animal count.
    actions[2]="divide"; //division in this simulation really just acts like subtraction.
    actions[3]="addition"; //adds to an animal count.
    actions[4]="conserve"; //conserve preserves one animal count and decreases the count of all other animals.
    actions[5]="reserve"; //reserve in this simulation really just acts like conserve.

    //Choice to action arrays takes a choice and gives it the corresponding action to perform.
    choiceToAction[0]=actions[3]; //Choice number 0, responds to addition, so we give it action 3.
    choiceToAction[1]=actions[4]; //Choice number 1 responds to conservation so we give it action 4.
    choiceToAction[2]=actions[2]; //Choice number 2, responds to division, so we give it action 2.
    choiceToAction[3]=actions[1]; //Choice number 3, responds to subtraction, so we give it action 1.
    choiceToAction[4]=actions[0]; //Choice number 4, responds to multiplication, so we give it action 0.
    choiceToAction[5]=actions[5]; //Choice number 5, responds to reservation, so we give it action 5.

    //Elements just holds what animal is at what slot in that array.
    elements[0]="octopi";
    elements[1]="fish";
    elements[2]="sharks";
    elements[3]="coral";
    elements[4]="plankton";
}

/*Process Function:
* What process does, is it basically defines what each action means.
* It sets in place what addition is, what subtraction is, etc.
* It also initiates what the game's boundaries are. It makes sure to tell the user when the game is over, and to not go past stage 6, because the game is only
* wired to go up to 6 stages and that's it.
* It holds a variable that converts the user's pick of animal into a variable to be used to identify which animal corresponds to that number, which is dictated
* by the variable called "var."
* The string choice holds the choice string at the given stage. For example, at stage 0, it would hold the first choice presented in the game.
* Action does the exact same thing, it holds the action at any given stage.
* If, at any point in the game, you lose the count of animals you have. Or one species dies off, then the game will end.
* If you survive all stages, and none of your animals die off, then you have successfully completed Ecosystem Simulation.
*/
void Ocean::process()
{
    string choice=choices[stages[stage]]; //holds whatever choice is asked at any given stage
    string action=choiceToAction[stages[stage]]; //holds whatever action is assigned at any given stage
    userIO.displayUser(choice); //Calls a previous function in class User IO to display a choice across the screen.
    //cout<<"Action is "<<action<<endl;
    for(int i=0; i<5; i++) //This for loop displays all the animals for each question.
    {
        string temporary = to_string(i) + ". " + elements[i];; //The for loop converts i into a string, then displays each animal like. 0. Shark, 1. Octopus, etc.
        userIO.displayUser(temporary); //Displays the string to the user by calling the function
    }

    int var=stoi(userIO.promptUser("Pick your choice")); //Var holds whatever number the user picked.

    string element=elements[var]; //Element corresponds to the number value var holds, which gets converted into what animal they wish to change the count for.

    if(action=="addition") //if the action happens to be addition for a scenario...
    {
        oceanAnimals[var][stage]+=30; //Then increment the count of the animal they pick by 30.
    }
    else if(action=="conserve") //if the action happens to be conserve for a scenario...
    {
        for(int i=0; i<5; i++) //use a for loop to iterate through each animal count.
        {
            if(i!=var) //if the index value isn't the chosen animal
            {
                oceanAnimals[i][stage]-= 10; //then decrease the count of that animal by 10
            }
        }
    }
    else if(action=="divide") //if the action happens to be division for a scenario...
    {
    oceanAnimals[var][stage] -=15; //Then decrement the count of the animal they pick by 15.
    }
    else if(action=="subtract") //if the action happens to be subtraction for a scenario...
    {
        oceanAnimals[var][stage]-=30; //Then decrement the count of the animal they pick by 30.
    }
    else if(action=="multiply") //if the action happens to be multiplication for a scenario...
    {
        oceanAnimals[var][stage]+=40; //Then increment the count of the animal they pick by 40.
    }
    else if(action=="reserve") //if the action happens to be reserve for a scenario...
    {
        for(int i=0; i<5; i++) //use a for loop to iterate through each animal count.
        {
            if(i!=var) //if the index value isn't the chosen animal
            {
                oceanAnimals[i][stage]-= 30; //then decrease the count of that animal by 10
            }
        }
    }

    for(int i=0; i<5; i++) //Use this for loop to return the count of each animal after each scenario has been run so they know what the current counts are.
    {
        cout<<elements[i]<<" "<<oceanAnimals[i][stage]<<endl; //Simply cout the count of each animal.
    }

    stage++; //increment the stage here and go to the next stage.

    if(stage>=6) //if the stage is greater than or equal to 6...
    {
        cout<<"You have a thriving, healthy ecosystem! Congratulations."<<endl; //Then you have passed the simulation!
        exit(0); //Exit the game.
    }

    for(int i=0; i<5; i++) //This is a for loop used for checking.
    {
        oceanAnimals[i][stage]=oceanAnimals[i][stage-1];

        if(oceanAnimals[i][stage]<=0) //If any animal count is below or equal to zero...
        {
            cout<<elements[i]<<" have been wiped out. Ecosystem thrown off balance. End of game."<<endl; //then the ecosystem has been wiped out.
        exit(0); //exit the game.
        }
    }
}

Ocean::~Ocean()
{
    //Destructor
}

/*Getters and Setters (Ocean)
* What my getters do, is they take in a value to be set, a float value incase someone puts a hundred, and it first checks if that value is greater than 30.
* 30 is my threshold number, you can not go below it, otherwise you will not be able to advance far in the game.
* It'll first check if any animal is 30, if an animal is, then cout "Invalid value" and exit the game.
* If it's above 30 though, it will store that number into the oceanAnimals array.
* Setters will return you that number value in the array for any given animal.
* We are using these to interact with private attributes.
*/
void Ocean::setOctopi(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
    oceanAnimals[0][stage]=value;
}
float Ocean::getOctopi()
{
    return oceanAnimals[0][stage];
}
void Ocean::setNumFish(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
    oceanAnimals[1][stage]=value;

}
float Ocean::getNumFish()
{
    return oceanAnimals[1][stage];
}
void Ocean::setCoral(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
    oceanAnimals[3][stage]=value;
}
float Ocean::getCoral()
{
    return oceanAnimals[3][stage];
}
void Ocean::setShark(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
    oceanAnimals[2][stage]=value;
}
float Ocean::getShark()
{
    return oceanAnimals[2][stage];
}
void Ocean::setPlankton(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
   oceanAnimals[4][stage]=value;
}
float Ocean::getPlankton()
{
    return oceanAnimals[4][stage];
}

//Default constructor for Terrain Biome.
Terrain::Terrain()
{
    //Here you will want to initialize all the variables, and use your setters.
    stage=0;
    //intitializing all arrays to zero.
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)

        terrainAnimals[i][j]=0; //make sure to fill the array with zero's.
    }

    seconduserIO.displayArt("bird.txt"); //input file to read the bird ASCII art and insert it

    seconduserIO.displayUser("Pick and Choose your animals. You MUST pick a number greater than 30 for each."); //Displays the choice to the user

    setWolves(stof(seconduserIO.promptUser("How many wolves would you like to start with?"))); //use a setter to store what the value is for Wolves.

    setRabbits(stof(seconduserIO.promptUser("How many rabbits would you like to start with?"))); //use a setter to store what the value is for Rabbits.

    setHawk(stof(seconduserIO.promptUser("How many hawks would you like to start with?"))); //use a setter to store what the value is for Hawks.

    setFieldMouse(stof(seconduserIO.promptUser("How many field mice would you like to start with?"))); //use a setter to store what the value is for Field Mice.

    setShrubs(stof(seconduserIO.promptUser("How many shrubs would you like to start with?"))); //use a setter to store what the value is for Shrubs.

    initializeGameplay(); //Call the initialize Game play function.

}

/*Initialize Gameplay Function:
* What this function does, is the real game play scenarios.
* Here you define all of your arrays from the h file, you define what goes into every spot of the array responsible for guiding the game.
* I defined all my stages array, which spans over 6 stages of the game, meaning 6 scenarios.
* I initialized all values in that array from 0 to 6.
* Next was my choices array. What my choices array did, was it holds all the scenarios, which are strings of different questions being asked to the user.
* I initialized 6 of them because there's 6 total stages. We don't want more, or less.
* My Actions array is responsible for holding the strings that correlate to what function will be carried out.
* If the scenario means an animal will die, or population will grow, I have addition and subtraction stored into my action array as strings that can later be
* used as actual function names to perform whatever type of function it is that they dictate.
* What choice to action does, is it holds whatever action is being performed according to the choice. So position 0 in choice to Action just means choice 0,
* and choice 0 corresponds to addition, so it will hold action #3, addition!
* Finally, I have an elements array which simply holds a member of the ecosystem in each of the provided slots.
*/
void Terrain::initializeGameplay()
{
    //Here is where I initialize all of my stages, from 0 to 5, making 6 stages. Each stage corresponds with what question is asked. To keep things simple...
    //I made it so that stage 0 associates with choice 0. And so on, and so on.
    stages[0]=0; //stage 0 will ask choice 0.
    stages[1]=1; //stage 1 will ask choice 1.
    stages[2]=2; //stage 2 will ask choice 2.
    stages[3]=3; //stage 3 will ask choice 3.
    stages[4]=4; //stage 4 will ask choice 4.
    stages[5]=5; //stage 5 will ask choice 5.

    //my choices array is straight forward, it holds each question the user must answer in the simulation.
    choices[0]="Your ecosystem is thriving! Choose one species to populate";
    choices[1]="Illegal Hunting is taking place! Choose one species to conserve. (Note that all other species will go down in number)";
    choices[2]="Pine Beetle's have invaded. Choose one species to deplete.";
    choices[3]="Beetle Infection have caused Shrub population to become infected. Press 4.";
    choices[4]="Thanks to some rescue efforts the ecosystem is doing better! More growth! (Choose a species)";
    choices[5]="Poaching is increasing. Pick one species to conserve";

    //Actions array merely lists out what action will be performed. Whether it will lead to addition of some animal, subtraction of some animal, or conservation
    //of some animal, this merely dictates what action will be carried out on whatever animal the user picks.
    actions[0]="multiply"; //multiply in this simulation really just acts like addition.
    actions[1]="subtract"; //subtracts from an animal count.
    actions[2]="divide"; //division in this simulation really just acts like subtraction.
    actions[3]="addition"; //adds to an animal count.
    actions[4]="conserve"; //conserve preserves one animal count and decreases the count of all other animals.
    actions[5]="reserve"; //reserve in this simulation really just acts like conserve.

    //Choice to action arrays takes a choice and gives it the corresponding action to perform.
    choiceToAction[0]=actions[3]; //Choice number 0, responds to addition, so we give it action 3.
    choiceToAction[1]=actions[4]; //Choice number 1 responds to conservation so we give it action 4.
    choiceToAction[2]=actions[2]; //Choice number 2, responds to division, so we give it action 2.
    choiceToAction[3]=actions[1]; //Choice number 3, responds to subtraction, so we give it action 1.
    choiceToAction[4]=actions[0]; //Choice number 4, responds to multiplication, so we give it action 0.
    choiceToAction[5]=actions[5]; //Choice number 5, responds to reservation, so we give it action 5.

    //Elements just holds what animal is at what slot in that array.
    elements[0]="wolves";
    elements[1]="rabbits";
    elements[2]="hawks";
    elements[3]="field mice";
    elements[4]="shrubs";
}

/*Process Function:
* What process does, is it basically defines what each action means.
* It sets in place what addition is, what subtraction is, etc.
* It also initiates what the game's boundaries are. It makes sure to tell the user when the game is over, and to not go past stage 6, because the game is only
* wired to go up to 6 stages and that's it.
* It holds a variable that converts the user's pick of animal into a variable to be used to identify which animal corresponds to that number, which is dictated
* by the variable called "var."
* The string choice holds the choice string at the given stage. For example, at stage 0, it would hold the first choice presented in the game.
* Action does the exact same thing, it holds the action at any given stage.
* If, at any point in the game, you lose the count of animals you have. Or one species dies off, then the game will end.
* If you survive all stages, and none of your animals die off, then you have successfully completed Ecosystem Simulation.
*/
void Terrain::process()
{
    string choice=choices[stages[stage]]; //holds whatever choice is asked at any given stage
    string action=choiceToAction[stages[stage]]; //holds whatever action is assigned at any given stage
    seconduserIO.displayUser(choice); //Calls a previous function in class User IO to display a choice across the screen.
    //cout<<"Action is "<<action<<endl;
    for(int i=0; i<5; i++) //This for loop displays all the animals for each question.
    {
        string temporary = to_string(i) + ". " + elements[i];; //The for loop converts i into a string, then displays each animal like. 0. Wolf, 1. Rabbits, etc.
        seconduserIO.displayUser(temporary); //Displays the string to the user by calling the function
    }

    int var=stoi(seconduserIO.promptUser("Pick your choice")); //Var holds whatever number the user picked.

    string element=elements[var]; //Element corresponds to the number value var holds, which gets converted into what animal they wish to change the count for.

    if(action=="addition") //if the action happens to be addition for a scenario...
    {
        terrainAnimals[var][stage]+=30; //Then increment the count of the animal they pick by 30.
    }
    else if(action=="conserve") //if the action happens to be conserve for a scenario...
    {
        for(int i=0; i<5; i++) //use a for loop to iterate through each animal count.
        {
            if(i!=var) //if the index value isn't the chosen animal
            {
                terrainAnimals[i][stage]-= 10; //then decrease the count of that animal by 10
            }
        }
    }
    else if(action=="divide") //if the action happens to be division for a scenario...
    {
        terrainAnimals[var][stage] -=15; //Then decrement the count of the animal they pick by 15.
    }
    else if(action=="subtract") //if the action happens to be subtraction for a scenario...
    {
        terrainAnimals[var][stage]-=30; //Then decrement the count of the animal they pick by 30.
    }
    else if(action=="multiply") //if the action happens to be multiplication for a scenario...
    {
        terrainAnimals[var][stage]+=40; //Then increment the count of the animal they pick by 40.
    }
    else if(action=="reserve") //if the action happens to be reserve for a scenario...
    {
        for(int i=0; i<5; i++) //use a for loop to iterate through each animal count.
        {
            if(i!=var) //if the index value isn't the chosen animal
            {
                terrainAnimals[i][stage]-= 30; //then decrease the count of that animal by 10
            }
        }
    }

    for(int i=0; i<5; i++) //Use this for loop to return the count of each animal after each scenario has been run so they know what the current counts are.
    {
        cout<<elements[i]<<" "<<terrainAnimals[i][stage]<<endl; //Simply cout the count of each animal.
    }

    stage++; //increment the stage here and go to the next stage.

    if(stage>=6) //if the stage is greater than or equal to 6...
    {
        cout<<"You have a thriving, healthy ecosystem! Congratulations."<<endl; //Then you have passed the simulation!
        exit(0); //Exit the game.
    }

    for(int i=0; i<5; i++) //This is a for loop used for checking.
    {
        terrainAnimals[i][stage]=terrainAnimals[i][stage-1];

        if(terrainAnimals[i][stage]<=0) //If any animal count is below or equal to zero...
        {
            cout<<elements[i]<<" have been wiped out. Ecosystem thrown off balance. End of game."<<endl; //then the ecosystem has been wiped out.
        exit(0); //exit the game.
        }
    }
}

Terrain::~Terrain()
{
    //destructor
}
/*Getters and Setters (Terrain)
* What my getters do, is they take in a value to be set, a float value incase someone puts a hundred, and it first checks if that value is greater than 30.
* 30 is my threshold number, you can not go below it, otherwise you will not be able to advance far in the game.
* It'll first check if any animal is 30, if an animal is, then cout "Invalid value" and exit the game.
* If it's above 30 though, it will store that number into the terrainAnimals array.
* Setters will return you that number value in the array for any given animal.
* We are using these to interact with private attributes.
*/
void Terrain::setWolves(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
    terrainAnimals[0][stage]=value;
}
float Terrain::getWolves()
{
    return terrainAnimals[0][stage];
}
void Terrain::setRabbits(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
    terrainAnimals[1][stage]=value;
}
float Terrain::getRabbits()
{
    return terrainAnimals[1][stage];
}
void Terrain::setHawk(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
    terrainAnimals[2][stage]=value;
}
float Terrain::getHawk()
{
    return terrainAnimals[2][stage];
}
void Terrain::setFieldMouse(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
    terrainAnimals[3][stage]=value;
}
float Terrain::getFieldMouse()
{
    return terrainAnimals[3][stage];
}
void Terrain::setShrubs(float value)
{
    if(value<30)
    {
        cout<<"Invalid Value, Terminating Program"<<endl;
        exit(0); //terminates program
    }
   terrainAnimals[4][stage]=value;
}
float Terrain::getShrubs()
{
    return terrainAnimals[4][stage];
}
