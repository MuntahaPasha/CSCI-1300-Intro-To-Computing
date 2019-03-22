// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 7
// Spell Checker Header File

#ifndef SpellChecker_H
#define SpellChecker_H

#include <iostream>
using namespace std;

class SpellChecker
{
    public:
        SpellChecker(); //default constructor
        ~SpellChecker(); //destructor

        string language; //the language that the spell checker is in
        string validword; //variable for file name to be read in
        string invalidword; //variable for file name to be read in
        int counter=0; //setting counter for readvalidwords in the .h so that in the .cpp it'll always use the current value of counter

        SpellChecker(string); //constructor that only takes a string

        SpellChecker(string, string validwords, string invalidwords); //constructor that takes your file names

          bool readValidWords(string filename); //function declaration

          bool readCorrectedWords(string correctedwords); //function declaration

          bool setStartMarker(char begin); //setter for start marker
          char getStartMarker(); //getter for start maker
          bool setEndMarker(char end); //setter for end marker
          char getEndMarker(); //getter for end marker

          string removePunctuation(string sentence); //function declaration

          string repair(string sentence); //function declaration
          bool checkPunctuation(char); //function declaration

    private:
        char start_marker; //private data member
        char end_marker; //private data member
        string validwords[10000]; //private array data member for valid words

  string wordArray[10000][2]; //2D word array for correct word and misspelled word
  int rows=0; //initializing rows of it
  int columns=0; //initializing columns of it

  int findCorrectWord(string word); //function declaration
  bool checkValidWord(string word); //function declaration
  string marker(string word); //function declaration
};

#endif
