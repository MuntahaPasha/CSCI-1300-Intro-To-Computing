// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 7
// Word Counts and Spell Checker Main CPP

#include <iostream>
#include "SpellChecker.h"
#include "WordCounts.h"
#include <fstream>


using namespace std;

int main()
{
    SpellChecker spellChecker;

    spellChecker.setStartMarker('~');

    spellChecker.setEndMarker('~');

    spellChecker.readValidWords("/home/user/Desktop/VALID_WORDS_3000.txt");

    spellChecker.readCorrectedWords("/home/user/Desktop/MISSPELLED.txt");

    string result = spellChecker.removePunctuation("Hello! I'm Mun!");

    string result2 = spellChecker.repair("I liek bleu");

    cout<<"result ="<<result<<endl;

    cout<<"Repair: "<<result2<<endl;

    WordCounts wordCounts;
    wordCounts.tallyWords("Hello!");
    int stuff= wordCounts.getTally("Hello!");

    cout << endl;
    cout<<"cout "<< stuff<<endl;
}
