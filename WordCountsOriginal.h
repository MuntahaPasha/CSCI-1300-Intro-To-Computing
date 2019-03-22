#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class WordCounts
{
    public:
        int index;
           int temp;
        WordCounts();
        ~WordCounts();
        void tallyWords(string);
        int getTally(string);
        void resetTally();
        int mostTimes(string[], int [], int);
        void sortArray();
        bool checkWords(string);
        bool checkPunctuation(char);

    private:


        int Split(string, char, string[], int);
        int counting[10000];
        string wording[10000];
        int removePunctuation(string);

};

#endif // WORDCOUNTS_H
