#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H

// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 7
// Word Counts Header File

#include <fstream>
#include <string>
using namespace std;

class WordCounts
{
public:
	int index; //variable declaration
	int temp; //variable declaration
	WordCounts(); //default constructor
	~WordCounts(); //destructor
	void tallyWords(string); //function declaration for the tally words function
	int getTally(string); //function declaration get tally which gets the tally of a specific word
	void resetTally(); //function declaration
	int mostTimes(string[], int[], int); //function declaration
	void sortArray(); //function declaration
	bool checkWords(string); //function declaration
	bool checkPunctuation(char); //function declaration

private:


	int Split(string, char, string[], int); //function declaration

	string removePunctuation(string); //function declaration
	int counting[10000]; //declaring counting array that holds 10000 values
	string wording[10000]; //word array with corresponding values to the tally's.

};

#endif // WORDCOUNTS_H
