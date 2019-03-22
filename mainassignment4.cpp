// Muntaha Pasha: CS1300 Fall 2017
// Recitation:  – Camilla, 204
//
// Assignment 4

#include <iostream>
#include "Assignment4.cpp"

using namespace std;

int main()
{
    cout<<"Test 1: "<<similarityScore("ACGT","ACGG")<<endl;
    cout<<"Test 1.5: "<<similarityScore("TAGT","GATT")<<endl;
    cout<<"Test 2: "<<countMatches("CCGCCGCCGA","CGC", 0.60)<<endl;

    cout<<"Test 3: "<<findBestMatch("AAAAAAAA", "TTTT")<<endl;

    cout<<"Test 4: "<<findBestGenome("A","B","C","A")<<endl;
}
