// Author: Muntaha Pasha
// Recitation: 204, Camilla
//
// Assignment 3
// Problem 1

#include <iostream>

using namespace std;

/**
* Algorithm description:
* First you will create 3 separate function for all the stories. Story 1, Story 2, and Story 3.
* All stories will be voids, and in them you'll make string variables, and define them, then have user inputs for each of the variables.
* The Menu function will call all 3 story function, on the menu function you can pick which story you want to play, by setting a char variable that takes user input.
* Depending on what char the user inputs, menu will generate the story number, and if they don't select a valid response, no story will generate.
* Story 1-3 will all be voids, they don't return you any value, they're all just manipulating strings into a function.
* Menu function will also be a void because it's not returning you any value either, but through menu, you need a set of if and else statements to guide which char entry leads to what response.
* Then, at the end, all of this will be called into your main. Main will not do anything except call the menu function, which menu will call all three of your stories.
* No function inputs our outputs will be done in main. main will only execute menu.
*/


void story1(void)
{
    string pluralnoun;
    string occupation;
    string animalname;
    string place;

    cout<<"Enter a plural noun: ";
    cin >> pluralnoun;
    cout<<"Enter an occupation: ";
    cin >> occupation;
    cout << "Enter an animal name: ";
    cin >> animalname;
    cout<<"Enter a place: ";
    cin >> place;

    cout<<"In the book War of the "<<pluralnoun<<", the main character is an anonymous "<<occupation<<" who records the arrival of the "<<animalname<<"s in "<<place<<"."<<endl;
 }

void story2(void)
{
    string name;
    string statecountry;

    cout<<"Enter your name: ";
    cin >>name;
    cout<<"Enter a state/country: ";
    cin>>statecountry;

    cout<<name<<", I've got a feeling we're not in "<<statecountry<<" anymore."<<endl;
}

void story3(void)
{
    string firstname;
    string verb;
    string relative;

    cout<<"Enter a first name: ";
    cin>>firstname;
    cout<<"Enter a relative: ";
    cin>>relative;
    cout<<"Enter a verb: ";
    cin>>verb;

    cout<<"Hello. My name is "<<firstname<<". You killed my "<<relative<<". Prepare to "<<verb<<"."<<endl;
}

void menu(void)
{
    char storynumber;
    cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
    cin>>storynumber;
    if(storynumber=='1')
    {
        story1();
    }
    else if(storynumber=='2')
    {
        story2();
    }
    else if(storynumber=='3')
    {
        story3();
    }
    else if(storynumber=='q')
    {
        cout<<"good bye"<<endl;
        return;
    }
    else(storynumber != '1' && storynumber != '2' && storynumber != '3' && storynumber != 'q');
    {
        cout<<"Valid choice not selected."<<endl;
    }

}

int main()
{
    menu();
}
