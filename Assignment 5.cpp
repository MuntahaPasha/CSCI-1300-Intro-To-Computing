// Muntaha Pasha: CS1300 Fall 2017
// Recitation:  – Camilla, 204
//
// Assignment 5

#include <iostream>
#include <math.h>

using namespace std;

/* Sum Array Algorithm:
* Function called sumArray, which adds up all the numbers in an array and returns a floating point value.
* You can find this sum by setting up a float variable called sum, which will store the sum value each time you iterate through the index.
* Sum starts out at 0, but then you add the number to sum at the position of the index where we initially start, so zero.
* That value gets stored in sum, and the process repeats now for the next value in the index, that plus the initial sum now makes the new sum.
*/

float sumArray(float array[], int size)
{
    float sum= 0.0; //variable to store sum
    for(int index=0; index<size; index++) //for loop telling the function its boundaries
    {
        sum=sum+array[index]; //formula for finding the sum
    }
    return sum; //returning sum value
}

/* Search function Algorithm:
* This function looks for a given target value, an integer, in a long array.
* Using a nested loop, an if inside a for, you iterate through the index with the for loop.
* The if loop is used to see if the index position in the array holds the target value. If so, return that position.
*/

int search(int array[], int size, int target)
{
    for(int index=0; index<size; index++) //for loop looking through index
    {
        if(array[index]==target) //if you see the target value in the index, then...
        {
            return index; //return this value to us!
        }
    }

    return -1; //otherwise if you look through entire array and you don't see a target value, then return -1.
}

/* Calculate Difference Algorithm:
* In order to calculate the difference of two values in different arrays and square it, you know you'll need an index, and a pow.
* To start off you'll make a float variable, matching our data type, to hold the value of the smaller function inside.
* Set difference equal to zero, then make your for loop, and call your difference variable inside it to calculate the difference squared.
* It'll take the same index position in array a, and array b, and minus those, then square them, all inside a pow.
* Difference will hold the result, and once the loop is exited, you will return the value of difference.
*/

float calculateDifference(int a[], int b[], int size)
{
    float difference=0.0; //your difference variable which will hold the results

    for(int i=0; i<size; i++) //for loop that iterates through index
    {
        difference=difference + pow((a[i]-b[i]),2); //pow function, base is the index position of a minus same index position of b, then the exponent is 2.
    }
    return difference; //return the variable which you found in the for loop.
}

/* Sort Array Algorithm:
* Function called sortArray, which, using a bubble sort, iterates through the array.
* You can do this by checking if the position at index is greater than the position of the index after that, if so, switch the two.
* If the position at index is not greater than the one next to it, then leave it.
* There will be two index's, the second one is most important in the sense that second index that is meant to convey how far along we have moved. For example,
  if the array length was seven, seven minus zero, which is the index position, minus 1, tells you that you have sorted one number, now you have 6 more to sort.
* Keep going through index and swapping numbers accordingly.
*/

void sortArray(float unsortedArray[], int size)
{
    for(int index=0; index<size; index++) //first index to step through each value in the array
    {
        for(int j=0; j<size-index-1; j++) //the second index meant to tell you where you are moving in each array, where the sort gets you
        {
            if(unsortedArray[j] > unsortedArray[j+1]) //if the value in the index is greater than the value next to it...
            {
            float positionarray = unsortedArray[j+1]; //then swap the first and second numbers by holding the second number in a new variable
            unsortedArray[j+1]= unsortedArray[j]; //store the value of the first value now in the value next to it
            unsortedArray[j]= positionarray; //and store the variable you stored the second value in equal to the first value place holder
            }
        }
    }
}

/* Copy Array Algorithm:
* This takes two parameters, a source, and a destination. The source array provides the inputs needed to put into the destination array.
* You copy the value from source array and index position, and then the index at that position in destination array value becomes that number.
* So now, destination at that index should equal the source at that index in value.
*/

void copyArray(float source[], int size, float dest[])
{
    for(int index=0; index<size; index++) //iterate through index
    {
        dest[index]=source[index]; //the index position in the destination array must be set equal to that same index position of the second array
    }
}

/* Convert Function Algorithm:
* This function coverts a number from an array to a string in the next array.
* Based on what number is present in the first array, there is a corresponding string value that will be entered in the position of the other array.
* It goes through the index of the first, according to the value in each index position, it then makes that a string in the position of the second array.
* It then goes through the index, at each position, searching for those certain integer values to convert to strings in the second array, and if it sees a
  number other than the ones provided, it will give back "INVALID"
*/

void convert(int rating[], string text[], int size)
{
    for(int index=0; index<size; index++) //step through index
    {
        if(rating[index]==0) //looking for the number 0 in the index. If it finds it, then...
        {
            text[index]="Not-read"; //the value in the second array at the same position becomes a string saying "Not-read"
        }
        else if(rating[index]==-5) //repeat steps above for all other if and else statements in the nested loop.
        {
            text[index]="Terrible";
        }
        else if(rating[index]==-3)
        {
            text[index]="Disliked";
        }
        else if(rating[index]==1)
        {
            text[index]="Average";
        }
        else if(rating[index]==3)
        {
            text[index]="Good";
        }
        else if(rating[index]==5)
        {
            text[index]="Excellent";
        }
        else //if you did not see any of those numbers
        {
            text[index]="INVALID"; //then the string that text array holds is simply "INVALID"
        }
    }
}

/*Float find Median function algorithm
* Frst you are copying the original array over, using the copy function that you wrote, so that you can store the array into a variable that you have control
* over, and so that you don't mess with the original array.
* After that, you want to call your sorting function to sort the array so that we can find the median.
* Once the array has been copied, and sorted, you write out the median function. If it's odd, you know the median is the position of the size/2.
* However, if it's an even array, you have to calculate the average between two middle numbers, so it requires more steps. You divide, and then average.
* The function will then return you the middle value.
*/

float findMedian(float array[], int size)
{
    float array2[size]; //this is the variable you will storing the original array in, as a copy.
    copyArray(array, size, array2); //copy the array into the variable
    sortArray(array2, size); //sort the array in that variable
    float middlevalue; //use a variable to hold the result of the median as a float because the function returns a float.
    int index1; //index one is just a temp variable and so is index 2, just to make my math more cleaner in the equation below.
    int index2;
    if(size%2==0) //if the array has an even set of numbers...
    {
        index1=(size/2); //divide it's size by two, and store that in index one.
        index2=index1-1; //take the value from index one and subtract one from it to find the value next to it, with which you'll be averaging the result.
        middlevalue=(array2[index1]+array2[index2])/2.0; //Average both index one and index two to find the middle of the two.
    }
    else
    {
        middlevalue=array2[index1]; //if the array size is odd, then simply divide by two.
    }

    return middlevalue; //return the median.
}



