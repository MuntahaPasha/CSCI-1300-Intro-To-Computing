#include <iostream>
#include "SpellChecker.h"
//#include "WordCounts.cpp"
#include <fstream>


using namespace std;

int main()
{
    SpellChecker spellChecker;

   // WordCounts wordCounts;

    spellChecker.setStartMarker('~');

    spellChecker.setEndMarker('~');

    spellChecker.readValidWords("/home/user/Desktop/VALID_WORDS_3000.txt");

    spellChecker.readCorrectedWords("/home/user/Desktop/MISSPELLED.txt");

    string result = spellChecker.removePunctuation("Hello! I'm Mun!");

    string result2 = spellChecker.repair("I liek bleu");

   // wordCounts.tallyWords

    cout<<"result ="<<result<<endl;

    cout<<"Repair: "<<result2<<endl;

    WordCounts wordCounts;

    wordCounts.tallyWords("Hey hi, hi Hey")

    cout<<wordCounts.wording[0]<<" "<<wordCounts.counting[0]<<endl;

}
