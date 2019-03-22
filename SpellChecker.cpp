// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 7
// Spell Checker CPP File

#include "SpellChecker.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

SpellChecker::SpellChecker()
{
    //Default constructor taking only these parameters
    start_marker = '~';
    end_marker = '~';
    language="English";
}

SpellChecker::SpellChecker(string name)
{
    //Constructor with only string, takes the same parameters as the default constructor
    start_marker = '~';
    end_marker = '~';
    language=name;
}

SpellChecker::SpellChecker(string lang, string validfile, string correctword)
{
    //Parameters for this constructor, which include not only the parameters from before, but now also the file names, because this parameter reads in files.
    validword=validfile;
    invalidword=correctword;
    start_marker = '~';
    end_marker = '~';
    language = lang;
    readValidWords(validword); //initializing these functions
    readCorrectedWords(invalidword); //initializing functions

}

SpellChecker::~SpellChecker()
{
    //Destructor
}

/*Algorithm: Read Valid Words
* Read valid words reads in an input file, and it stores the values of it into an array called "valid words"
* It will first read the words from a file, use a boolean to tell you if it opened or not. If it did, it will then take each line from the file, which in this
* case is just one word, and store each word into valid words array using an index to iterate through. If it has stored all values successfully in the
* valid words array from the file. At the end, your valid words array should now hold each individual word.
*/

bool SpellChecker::readValidWords(string filename)
{
    string temp; //A temporary variable that holds nothing as of now.
    ifstream inputfile; //The file being read in.
    inputfile.open(filename); //Opening the file.

    if(!inputfile.is_open()) //Testing to see if file opens. If it doesn't, return false.
    {
        return false;
    }

    while(!inputfile.eof()) //If it opened successfully, and while not at the end of file, then carry out these commands.
    {
        getline(inputfile, temp); //Gets each line from the file, which is according to the format one word, and stores it into a temp variable.
        validwords[counter]=temp; //That temp variable then is stored into the valid words array at position 0, and then as counter increments, where it is stored increments as well.
        counter++; //Incrementing the counter so that the next word read in will be in the next position.
        //cout<<temp<<endl;
    }

    return true; //Once it has stored all values in Valid Words array, return true.
}

/*Helper Function: Split
* Split just parses a given string with punctuation and stores it into an array of words.
* It will split every time it sees a punctuation mark, if nothing exists in the string however, then obviously return 0.
* If something does, then use split to piece up the given sentence with the punctuation, and store it into an array.
*/

int Split(string str, char separate, string words[], int max_size)
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

/*Algorithm: Read Corrected Words
* Firstly, you will receive a file with two words per line. A misspelled word, and it's corrected counterpart.
* You are going to read in that file's data, and check if the file opens. If it doesn't let us know and return false.
* If it does, then we want to create a temporary array that only holds two things at a time. The misspelled word, and the corrected word.
* We want to get each line from the file, we want to split it at the tab character, and we want to store each value into this temp array with size two.
* We are then storing each of the two values in our temp array to the corresponding row and columnn in the word array.
* You want to increment the row and column, each time you go on, so you're not overriding any information.
* You also want to set the column number to 0 each time you're you're starting from the same column, and not adding onto column numbers.
* At the end of this, corrected words should be filled into a 2D array that now holds a misspelled word in the first column, and it's corrected word in the second.
*/

bool SpellChecker::readCorrectedWords(string correctedwords)
{
   string line; //Temporary string variable.
    ifstream inputfile; //Reading in a file with the words.
    inputfile.open(correctedwords);

    if(!inputfile.is_open()) //If the file doesn't open...
    {
        return false; //return false.
    }

    while(!inputfile.eof()) //If it does open, and it's not at the end of the file...
    {
        string tempArray[2]; //Declaration of a temporary array to hold the values from the file. Which will be size two. For two words.
        getline(inputfile, line); //Get each line from the file.
        Split(line, '\t', tempArray, 2); //Split each line at the tab character and put it into the two slots of the temporary array.

        wordArray[rows][columns]=tempArray[0]; //Word array now holds the word at temp array 0, which will be stored in row 0 columnn 0.
        columns++; //Increment column.
        wordArray[rows][columns]=tempArray[1]; //word array now holds the word at temp array 1, which will be stored in row 0, column 1.
        rows++; //Increment row now.
        columns=0; //Set column back to 0, so that you start underneath the first two words exactly.
        //cout<<tempArray[0]<<" "<<tempArray[1]<<endl;
    }

    return true;
}

/*Helper Functions: Getting and Setting Markers
* In order to set the start and end markers, you need to use your getters and setters.
* The user will set the start marker, and it will be stored to the start marker variable in the .h file, and same for the end marker.
* The getters will return the markers.
*/
bool SpellChecker::setStartMarker(char begin)
{
    start_marker=begin; //This sets the parameter value to the value in the dot h file.
}

char SpellChecker::getStartMarker()
{
    return start_marker; //returns you the starting marker.
}

bool SpellChecker::setEndMarker(char end)
{
    end_marker=end; //sets the parameter value to the value in the dot h file
}
char SpellChecker::getEndMarker()
{
    return end_marker; //returns the end marker
}

/*Helper Function: Check Punctuation
* Check punctuation takes a character, and matches it against any punctuation characters to test if it's a punctuation mark.
* If it is a punctuation mark, return true, if not, return false.
*/


bool SpellChecker::checkPunctuation(char c)
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

string SpellChecker::removePunctuation(string line)
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

/*Helper Function: findCorrectWord
* What this helper function does, is it looks for a target word in my wordsArray, which is a 2D array holding a misspelled word and it's correction.
* What we are doing is looking through each row one by one, to try and find the target correct word.
* If we find it, return the position to us of that word, so we can use it for further use in our later functions.
* If it doesn't find the word, that's important to know because it probably means that word doesn't exist in the array somewhere.
*/

int SpellChecker::findCorrectWord(string word)
{
    for(int i=0; i<10000; i++)
    {
        if(wordArray[i][0]==word) //indexing through the word array to find if the target word is there or not.
        {
            return i; //return the position.
        }
    }
    return -1; //If it's not found, it will return -1.
}

/*Helper Function: Check Valid Word
* This is very, very similar to find correct word in the sense that it looks for a target word in my valid words array.
* If the word given is found somewhere in the valid words array, then return true, otherwise return false.
* This will help us search for a specific word in a massive array to let us know if it's in there.
* Like find correct word, this one is a boolean that actually will return true or false depending on f it finds it.
*/

bool SpellChecker::checkValidWord(string word)
{
    for(int i=0; i<10000; i++)
    {
        if(validwords[i]==word) //indexes through valid words array to find if the word exists previously in there somewhere.
        {
            return true; //if it does, return true.
        }
    }
    return false; //if at no position you find the valid word, then return false.
}

/*Helper Function: Marker
* This function just takes a given word, and puts start and end markers around that world.
*/
string SpellChecker::marker(string word)
{
    return start_marker+word+end_marker; //The start marker will appear in front and behind the word. For Ex, if the word was hello, then: ~Hello~
}

/*Algorithm: Repair Function
* You'll first want to declare out the variables you'll be using. I decided to use a temporary array that holds no more than a few words at a time.
* I set it's size to 200 just to be safe, but it's really only used for holding sentences.
* You'll want a repaired sentence string, that will hold the repaired sentence at the end.
* I put the string that they feed into the function into my remove punctuation function that I call here.
* The string variable new sentence now holds the line without punctuation.
* You are now going to want to split the line into words and store them into a temporary array. It counts how many words it splits so you also have the size.
* So for example...If you had "Hello!! I'm Joe!" new sentence holds "hello i'm joe", and then the temp array holds [hello, i'm, joe]
* You are then going to call your check valid word function to check each word in the array which the size was told by the split function.
* If that valid word exists in the valid words array, then add it to the repaired string as it is. That means this is an acceptable word.
* If, however, you don't find it in valid words array, you then want to find if it has a corrected word corresponding to it.
* You will call the helper function for it, called checkValidWord, and if it returns true, that means it's in the word Array somewhere, and we use the position,
* which check valid words gives us, and we find the position corresponding in the correct words, we take that word and add it to the repaired sentence now.
* If it's not in valid words, or in corrected words, then you simply put a start an end marker on it to indicate it was not found in either arrays and has no
* corresponding values.
* You then need to add a space everytime you iterate so the words aren't mashed together.
* When the loop ends and you have iterated through every word in the line, the function will return you your corrected sentence.
*/
string SpellChecker::repair(string line)
{
    string temparray[200]; //Array for holding sentences
    string repairedsentence; //Repaired sentence string will hold your repaired sentence
    string newsentence=removePunctuation(line); //new sentence holds the line passed through remove punctuation.

    int wordcount= Split(newsentence, ' ', temparray, 200); //Word count holds the number of words, that split returns.

    for(int i=0; i<wordcount; i++) //for loop iterating until the word count is over.
    {
        if(checkValidWord(temparray[i])==true) //If the word is in the temp
        {
            repairedsentence=repairedsentence+temparray[i]; //Repaired sentence holds the temp array value
        }
        else
        {   int pos=findCorrectWord(temparray[i]); //If not in valid words, find the correct word for it, and return us the position.
            if(pos!=-1) //if the word does exist and has a correct spelling...
            {
                repairedsentence=repairedsentence+wordArray[pos][1]; //then it'll be at the position in the word array that corresponds with it's spellings. (In column 1, which holds corrected word)
            }
            else
            {
                repairedsentence=repairedsentence+marker(temparray[i]); //Add the markers around the word if you can't find it in the valid words or other array.
            }
        }
        repairedsentence=repairedsentence+" "; //add a space after every word
    }
        return repairedsentence; //return the corrected sentence.

}



