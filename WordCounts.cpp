// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 7
// Word Counts CPP File

#include "WordCounts.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

WordCounts::WordCounts()
{
	index = 0; //initializing an index variable to be used later to zero.
	temp = 0; //initializing a temp variable to be used later to zero.

	for(int i=0; i<10000; i++) //for each value in my two arrays to be used (10000 at max)
    {
        wording[i]=""; //fill the words array with nothing. Just empty slots.
        counting[i]=0; //fill the count array to 0 throughout.
    }
}

WordCounts::~WordCounts()
{
    //destructor
}

/*Helper Function: Check Punctuation
* Check punctuation takes a character, and matches it against any punctuation characters to test if it's a punctuation mark.
* If it is a punctuation mark, return true, if not, return false.
*/

bool WordCounts::checkPunctuation(char c)
{
    char punctuation[]={'?', ',', '.','!','\'','"','!', ':', ';'}; //an array of punctuation marks
    for(int i=0; i<sizeof(punctuation); i++)
    {
        if(c==punctuation[i]) //if the character is a punctuation mark
        {
            return true; //return true
        }
    }
        return false; //else return false
}

/*Helper Function: Remove Punctuation
* This function does exactly what it sounds like. It removes punctuation from a given line.
* It takes in a line, iterates through the length of the line, makes each character lowercase first, then uses each character in the check punctuation function
* to compare if it's a mark or not. If check punctuation is true, and there is punctuation, we need to test a bunch of other criteria.
* We are removing punctuation at the end and beginning of words, but not from in between words. Meaning "How're you?!" would be "how're you", and the apostrophe
* between how and re would remain.
* So, in order to test, we need to see if the word has a space before it, or a space after it.
* We begin by checking each end of the line, if it has punctuation, and then each word individually, which we do using a boolean method.
* Booleans will return true or false depending on if there's a space or not.
* At the end, we will return the line having no punctuation in it anymore.
*/

string WordCounts::removePunctuation(string line)
{
    string newline;
 for (int j = 0; j < line.length(); j++)
 {
    char c = tolower(line[j]); //Storing each character through every iteration
    bool shouldIgnore = false; //Flag used to check if we should ignore the char or not.
    if (checkPunctuation(c)) //calling check punctuation on our variable c.
    {
        bool isLineEdge = (j == 0 || j == line.length() - 1); // Check either end of line
        bool hasSpaceNextToIt=false; //boolean set to investigate if there's a space or not.

        if(j==0 || j==line.length()-1) //if we are at beginning and end of line...
        {
            hasSpaceNextToIt=false; //Then there is no space next to it.
        }
        else if(line[j-1]==' ' || line[j+1]==' ') //If we notice that there is a space at the position of the line either before and after...
        {
            hasSpaceNextToIt=true; //then our condition is true.
        }
        else
        {
            hasSpaceNextToIt=false; //Otherwise it's false.
        }

        if (hasSpaceNextToIt || isLineEdge) //if it has a space next to it but is at the end of the line...
        {
            shouldIgnore = true; //just ignore it.
        }
    }

    if (!shouldIgnore) //However, if those conditions are not met... then you need to remove the punctuation.
    {
        newline = newline + c; //Our new line becomes each character except punctuation. (Unless it's in between letters)
    }

 }

    return newline; //return us that new line.
}

/*Helper Function: Split
* Split just parses a given string with punctuation and stores it into an array of words.
* It will split every time it sees a punctuation mark, if nothing exists in the string however, then obviously return 0.
* If something does, then use split to piece up the given sentence with the punctuation, and store it into an array.
*/

int WordCounts::Split(string str, char separate, string words[], int max_size)
{
        int count = 1;
        int indexarray = 0;
        if(str=="")
        {
            return 0;
        }
      for(int index=0; index<str.length(); index++)
        {
       if(str[index]==separate)
       {
           words[indexarray]=str.substr(0, index);
           str.erase(0, (index+1));
           indexarray++;
           count++;
           index =0;
       }

        }

   words[indexarray]=str;

   return count; //Split returns the number of times it split the sentence, which is useful for finding out how many words are in a given string.
}

/*Helper Function: Check Words
* This function searches through an index of my wording array, which holds all the words, and if it finds a target word in there.
* It returns us the position of the word if it finds it in the array, and puts that position into a temp variable.
* It also returns true if it sees the word.
* If it does not find the word at all, then it returns false.
*/

bool WordCounts::checkWords(string word)
{

	for (int i = 0; i<index; i++)
	{
		if (wording[i] == word) //if the word is found in some index in my wording array...
		{
			temp = i; //then return the position of that word in the wording array
			return true; //return true.
		}
	}
	return false; //if you don't find it, return false.
}

/*Algorithm: Tally Words
* Tally words is supposed to take in a sentence, and it is supposed to read it in, and store the words in one array called wording array.
* It is also supposed to store the count of how many times that word appeared in the sentence in another counting array.
* For example, if you had "The bat the cat" it will store [the, bat, cat] in wording and corresponding counting would be [2, 1, 1] because "the" showed up twice.
* In order to properly adjust the sentence to that, you must first strip it of punctuation by calling remove punctuation on it, and then you need to split it.
* As usual, splitting the sentence will return the size, and you need that to find out how big the input sentence is.
* You iterate through a for loop, and you use the check words function to see if the value in your temp array, where all your words have now been stored, comes
* out to be true. If it does, you need to find that position in the count array, using the temp variable that holds the position, and increment it at the same
* place for the count. That way wording and counting arrays correspond exactly.
* We also need to increment our index's.
*/

void WordCounts::tallyWords(string inputsentence)
{
	int size = 0; //Just a size variable
	string tempArray[10000]; //A temporary array used for testing
	string inputsentence_nopunc = removePunctuation(inputsentence); //remove punctuation from the input sentence first.

	size = Split(inputsentence_nopunc, ' ', tempArray, size); //Now, split the sentence up, after each space character, and store into a temp array.

	for (int i = 0; i<size; i++)
	{
		if (checkWords(tempArray[i]) == true) //if the temp array has the target word we are looking for...
		{
			counting[temp]++; //increment the count at the corresponding position of where that word's count exists.
		}
		else
		{
			wording[index] = tempArray[i]; //if it's not already in the word array, put it in the word array.
			counting[index]++; //also increment the count for that word at that same position in counting array.
			index++; //increment the index.
		}
	}
}

/*Algorithm: Get Tally
* What get tally does, is very simple. It takes an input word as a parameter.
* It looks for that word in the wording array where it's stored, and if it's in the wording array...
* It will return you the corresponding tally for it stored in the same position in the counting array.
*/

int WordCounts::getTally(string inputword)
{
	for (int i = 0; i<index; i++)
	{
		if (wording[i] == inputword) //It looks for the input word in my wording array, to see if it exists there.
		{
			return counting[i]; //If it does, return the tally for it in the counting array.
		}
	}
	return 0; //if it does not, just return 0, because it means it's not in the array.
}

/*Algorithm: Reset Tally
* Reset tally resets all tally's in counting array back to zero.
* You use a simple for loop to iterate through each position in tally, and set all values to zero.
*/

void WordCounts::resetTally()
{
	for (int i = 0; i<index; i++)
	{
		counting[i] = 0; //Set all values up to index value to 0. Index is the variable that holds how many slots in the wording array and counting array are full.
	}
}

/*Helper Function: Sort Array
* I used this sort function to sort my counting and wording arrays from highest to lowest.
* Meaning, whatever word has the highest tally, will now be in position 0, and so on, and so on.
* I used a selection sort, and a for loop to sort both arrays at the same time, because you want to make sure the count and words still correspond.
* You swap the highest value with the lowest value, and also swap the corresponding words around.
* You are going to want to use two index's that are similarly incrementing.
*/

void WordCounts::sortArray()
{
	int maximum = 0; //A temporary integer value.
	int swapp; //Another temporary integer value
	string swapper; //Temporary string value

	for (int i = 0; i<10000; i++)
	{
		for (int j = 0; j<10000; j++)
		{
			maximum = counting[i]; //maximum is equal to the count position at i, or in the first iteration, 0
			if (counting[j] < maximum) //if the value at position j in counting is less than the max, then..
			{
				swapp = counting[i]; //store the value of max into a swapp integer value
				counting[i] = counting[j]; //store counting at j position into the new counting of i
				counting[j] = swapp; //and store swapp value back into the position of counting j

				swapper = wording[i]; //at the same time, with the same index, store the corresponding word into swapper
				wording[i] = wording[j]; //store wording at j position into new wording of i
				wording[j] = swapper; //and store swapper value back into position of wording j
			}
		}
	}
}

/*Algorithm: Most Times
* Most times takes an array of strings, an array of integers, and a number that indicates how many results it wants back.
* If n=10, it will take the top 10 tally's, and corresponding words, and return those to the user.
* In order to do that, you first call your sort function to sort the arrays.
* After that, you iterate through a for loop and fill the arrays given in the parameter with n number of results needed.
* At the end, you will have the information from my arrays stored into the parameter arrays, with n number of tally's and words.
*/

int WordCounts::mostTimes(string words[], int count[], int n)
{
	sortArray(); //call sort array to sort the arrays
	for (int i = 0; i<n; i++) //for i<n, because we only want n number of things stored into the new arrays
	{
		count[i] = counting[i]; //store everything from counting array into this new count array for every n'th time
	}

	for (int j = 0; j<n; j++)
	{
		words[j] = wording[j]; //similarly, store everything from wording array into this new word array for every n'th time
	}

	return n; //return the number of values inputted
}
