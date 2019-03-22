#include "WordCounts.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <string>

WordCounts::WordCounts()
{
   index=0;
   position;

   for(int i=0; i<10000; i++)
   {
       counting[i]=0;
       wording[i]="";
   }
}

WordCounts::~WordCounts()
{

}

bool WordCounts::checkPunctuation(char c)
{
    char punctuation[]={'?', ',', '.','!','\'','"','!', ':', ';'};
    for(int i=0; i<sizeof(punctuation); i++)
    {
        if(c==punctuation[i])
        {
            return true;
        }
    }
        return false;
}


int WordCounts::removePunctuation(string line)
{
    int count=1;
    string newline;
    for(int j=0; j<line.length(); j++)
    {
        char m=tolower(line[j]);
        if(!checkPunctuation(m))
        {
            newline=newline+m;
        }
        if(line[j]== ' ')
        {
            count++;
        }
    }
    return count;
}

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

   return count;
    }

bool WordCounts::checkWords(string word)
{
    bool check=false;
    for(int i=0; i<index; i++)
    {
        if(wording[i]==word)
        {
            position=i;
            check=true;
        }
    }
    //return false;
    return check;
}

void WordCounts::tallyWords(string inputsentence)
{
	int size = 0;
	string tempArray[10000];
	string inputsentence_nopunc = removePunctuation(inputsentence);

	size = Split(inputsentence_nopunc, ' ', tempArray, size);

	for (int i = 0; i<size; i++)
	{
		if (checkWords(tempArray[i]) == true)
		{
			counting[temp]++;
		}
		else
		{
			wording[index] = tempArray[i];
			counting[index]++;
			index++;
		}

	}

}

/*void WordCounts::tallyWords(string inputsentence)
{
    string tempArray[10000];
    int size=removePunctuation(inputsentence);

    Split(inputsentence, ' ', tempArray, size);

        for(int i=0; i<size; i++)
        {
            if(checkWords(tempArray[i])==true)
            {
                counting[position]++;
            }
            else
            {
                wording[index]=tempArray[i];
                counting[index]++;
                index++;
            }

        }

}*/

int WordCounts::getTally(string inputword)
{
    removePunctuation(inputword);
    for(int i=0; i<index; i++)
    {
        if(wording[i]==inputword)
        {
            return counting[i];
        }
    }
    return 0;
}

void WordCounts::resetTally()
{
    for(int i=0; i<index; i++)
    {
        counting[i]=0;
    }
}

void WordCounts::sortArray()
{
    int maximum=0;
    int swapp;
    string swapper;

    for(int i=0; i<10000; i++)
    {
        for(int j=0; j<10000; j++)
        {
            maximum=counting[i];
            if(counting[j] < maximum)
            {
                swapp=counting[i];
                counting[i]=counting[j];
                counting[j]=swapp;

                swapper=wording[i];
                wording[i]=wording[j];
                wording[j]=swapper;
            }
        }
    }
}

int WordCounts::mostTimes(string words[], int count[], int n)
{
    int counter=0;
    int counter2=0;
    int timesItCounted;
    sortArray();
    for(int i=0; i<n; i++)
    {
        count[i]=counting[i];
        counter++;
    }

    for(int j=0; j<n; j++)
    {
        words[j]=wording[j];
        counter2++;
    }

    timesItCounted=counter+counter2;

    return timesItCounted;
}



