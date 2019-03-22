// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 6

#include <iostream>
#include <math.h>
#include <fstream>
#include "Assignment6.cpp"

using namespace std;

int main()
{
    float test1= avgCharsPerLine("assignment6.txt");
    cout<<"Average is:"<<test1<<endl;

    float array[2][5];

    cout<<"Number of Lines: "<<fillArray("/home/user/assignment6point2.txt", array)<<endl;

    float test2= fillArray("/home/user/assignment6point2.txt", array);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;

    }

    float numbers[5][5];
    float ratings[5][9];

    string users[]={"Matt", "Lexie", "Lexie", "Dolly"}

    float test3=arrayStats("part3.txt", numbers);
    cout<<test3<<endl;

    float test4=addBookRatings("part4.txt", users, ratings)
    cout<<test4<<endl;
}
