// Muntaha Pasha: CS1300 Fall 2017
// Recitation: – Camilla, 204
//
// Assignment 6

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

/*
 *ifstream to open filename, and then filenme.open
 *If statement, that determines if the file has opened or not, with a return value of -1
 *Variable for the sentences to be read will be "String sentence;"
 *Then we will read each sentence line by line using getline(file, sentence)
 *float value to store the count of the total chars, so float total; and float avg; to caclulate average
 *Store the line in an int line variable
 *for(line=0; !filename.eof; line++)
 *If you see a character, increment the total chars variable.
  a) totalchars= totalchars+sentence.length()
  b) when we exit the loop we will have count of all characters in the file
 *after loop has exited, the formula to find the average will be totalchars/line
 *Function will return that as a float. You will set a float variable to contain totalchars/line, and then return that.
*/

float avgCharsPerLine(string filename)
{
    ifstream tempfile;
    tempfile.open(filename.c_str(), ios::in);

        /*if(!tempfile.open())
        {
        cout<<"Unable to open file"<<endl;
        return -1;
        }*/

        string sentence; //A variable to hold get the strings in getline
        float linelength=0;
        float counter=0;

            while(!tempfile.eof()) //while not at the end of file...
            {
            getline(tempfile, sentence); //get each line, line by line,
            counter ++; //increase the count, so it tells you how many lines you have
            linelength=linelength+sentence.length(); //the sentence length from getline equals the sentence length plua the line length variable
            }

        float result = linelength/counter; //to compute average, you divide the number of characters in linelength by the count, number of lines.

        tempfile.close(); //close your file

        return result; //then return your results
}

/* Split Function to parse through the other functions.
 * It just splits the string up, and returns it as separate entities
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

   return count;
    }

/*Fill Array Algorithm:
* First you need to open the file, and skip over the header using a getline to remove the header.
* After that, while not at the end of file, use a temporary array to store the values using split, to chop them up and put them in the temp array.
* Now you have an index that's less than 5, the max number of columns it can be is 5.
* It's going to take the values from file, after having split the string, and store them into a temporary array as floats.
* Since your data came in as a string, you need to convert your string to a float, using stof.
* Close your file after that's done.
*/

int fillArray(string filename, float array[][5])
{
    ifstream tempfile; //Open the file into a new variable
    tempfile.open(filename.c_str(), ios::in);
    string sentence; //string you'll use to extract data
    getline(tempfile, sentence); //getline to skip the header.
       int j=0;
       int index=0;

    while(getline(tempfile, sentence)) //while not at the end of line
    {
        string temparray[5]; //temparray to hold 5 things
        Split(sentence, ',', temparray,5); //split the array

        for(j=0; j<5; j++)
        {
            array[index][j]=stof(temparray[j]); //convert array values to floats and store them in
        }
        index++;
    }
    tempfile.close(); //close the file
     return index;
}

/*Array Stats Algorithm:
* First you call your fill array function to calculate the number of rows, which will help calculate the averages.
* Define your two mean values that you'll be storing the mean of the rows and the mean of the columns in
* Your for loop only going up until 5, number of columns, and then counting only the odd columns
* Take the mean of the sum of the values in odd columns, divide by rows, get mean for that.
* Repeat the same process for the rows.
* Once you have the mean of those two things, you need to add the means.
* Return that value.
*/

float arrayStats(string filename, float numbers[][5])
{
    int rows= fillArray(filename, numbers); //storing the number of rows returned from this function into rows.
    float mean_value=0; //first mean value
    float other_mean=0; //second mean value

    for(int i=1; i<5; i+=2) //starts at one and goes up 2 because 1 is odd
    {
        float counter=0; //counter to hold the sum
        for(int j=0; j<rows; j++) //while its less than number of rows
        {
              counter=counter+numbers[j][i]; //add all the rows

        }
        mean_value=mean_value+(counter/rows); //take the mean of those rows
    }
    for(int i=1; i<rows; i+=2) //now for the number of columns

       {
           float sum=0; //again a variable to hold the sum
        for(int j=0; j<5; j++) //while columnns are less than 5
        {
            sum=sum+numbers[i][j]; //compute sum of columns

        }
        other_mean= other_mean+(sum/5); //take the mean
    }

    float total= mean_value+other_mean; //add the two means together
    return total;
}

/*Search Array from Assignment 5 to help in next part.
* It just searches for the users name in the array and returns what position it's at.
*/
int search(string users[100], string name)
{
    for(int index=0; index<100; index++) //for loop looking through index
    {
        if(users[index]==name) //if you see the target value in the index, then...
        {
            return index; //return this value to us!
        }
    }

    return 999; //otherwise if you look through entire array and you don't see a target value, then return -1.
}

/*Book Ratings Algorithm
* This is storing the file information into 2 arrays, a 2.D array and a single array for users only.
* By using the search function, you first see if the user is repeated in the file, and as long as the book I.D is not the same, the user can be repeatedly added.
* Iterate through the filename by using getline, splitting the string, storing the first value into users, and the second two values into ratings.
* You need to make sure you convert the values in the array at the position 1 and 2 where the book i.d and rating is held
* You need to transfer all that info from the files into those arrays
* Then you exit the file.
*/
void addBookRatings(string filename, string users[], int ratings[][50])
{
    ifstream tempfile; //opening the file here
    tempfile.open(filename.c_str(), ios::in);

    if(tempfile.is_open())
    {   string sentence; //making string variable to use in get line.
        getline(tempfile, sentence); //This is to skip over the header.
        int usersarrayindex=0; //A variable to iterate through the users index array
        while(getline(tempfile, sentence)) //while you're not at the end of file and you're iterating through line by line...
        {
            string tempArray[3]; //A temporary array that holds 3 values at a time. [Name, book I.D, Rating]
        Split(sentence,',',tempArray, 3); //Split chops the the lines, stores all 3 values into array.
        int x=search(users, tempArray[0]); //Search function searches in temparray position 0, where all the users are stored, and it returns the position of the user in the index.
            if(x==999) //If user not previously added then...
            {
                    users[usersarrayindex]=tempArray[0];//The users array is now the usersindexarray position at the TempArray 0, it just adds it in.
                    x=usersarrayindex; //Now that you have the index at where the user is, you store that into x, then increment it to hold the next user.
                    usersarrayindex++; //increment that.
            }
            int something=stoi(tempArray[1]); //this is converting the value at position 1 in the temparray to an integer
                ratings[x][something]=stoi(tempArray[2]); //You now store the value of x

            }
        }

}





