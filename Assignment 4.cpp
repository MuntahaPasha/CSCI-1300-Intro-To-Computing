// Muntaha Pasha: CS1300 Fall 2017
// Recitation:  – Camilla, 204
//
// Assignment 4

#include <iostream>

using namespace std;

/* Algorithm Part 1:
* float function similarity score will take two parameters, sequence 1, and sequence 2.
* It will only calculate a similarity
* The index will reiterate through both strings, one character at a time, and compare them.
* Whenever it sees a mismatch, it'll store it into hamming distance.
* You calculate simscore by putting hamming distance and sequence length into the formula for it.
* Once that's been calculated, return the simscore.
*/

float similarityScore(string sequence1, string sequence2)
{
    float seqlen1 = sequence1.length(); //length of sequence 1
    float seqlen2 = sequence2.length(); //length of sequence 2
    float index = 0.0;
    float similarity_score=0.0; //the function declaration
    float hammingdistance = 0.0; //hamming distance

    if(seqlen1 == seqlen2) //only if the two are equal, should you do this loop.
    {

    while(index <= seqlen1) //setting index less than sequence length, so the loop has boundaries.
    {

        if(sequence1[index] != sequence2[index]) //if the character where the index is at for sequence one doesn't match the character at sequence 2...
        {
            hammingdistance++; // increment hamming
        }

        index ++; //increment index
    }

    similarity_score = (seqlen1-hammingdistance)/seqlen1; //the function similarity score being initialized

    return similarity_score; //return it, should be a float.
    }
    else
        {
        return 0; //must have an else return zero to complete if statement, because if sequence 1 and sequence 2 are equal, then return zero.
     }
}

/*
 * Algorithm for Part 2
 * * The function should find all the positions of the genome where genome’s substring matches sequence1 with a similarity greater than or equal to the min_score.
 * You're given the three parameters, and with this function, you wanna count how many times the character in genome equals the character of the sequence given.
 * You go through the index of the substring of the genome, which is in your for loop,
 * Set a variable for which you will store the results of simscore in, and if that's greater than min score, then, and only then, increase the count for that.
 * Return the variable for count.
 * The function should return the count of the number of such positions it found.
 */

int countMatches(string genome, string sequence1, float min_score)
{
    int counting=0;

    for (int index = 0; index < (genome.length()-sequence1.length()+1); index++) //index is less than genome length is when we initiate this call.
    {
        float x = similarityScore(genome.substr(index,sequence1.length()),sequence1);
        if(x >= min_score) //if the character of sequence 1 matches the character of genome at the index position
        {
            counting++; //increase the count
        }
    }
    return counting; //return the value you get from counting.
}

/*
 * Algorithm for Part 3: Find best match
 * This function should traverse the entire genome and find the highest similarity score by using similarityScore function for the comparisons between seq and each sequential substring of genome.
 * you're going to use your previous simscore function to implement the result you need in this.
 * After declaring your index and the variable to store your result, call your function, store result in one variable.
 * Compare that result to your compare value, and if they're equal store that value into compare.
 * Return compare value.
 */

float findBestMatch(string genome, string seq)
{
    float index =0.0; //index declaration
    float compare =0.0; //variable to store the compare value in to use.
    while(index< genome.length())
    {
    float result = similarityScore(genome.substr(index,seq.length()), seq); //calling SimScore with function parameters
    if(result > compare) //If the result returned by the similarity score is bigger than the compare, then go through if loop.
    {
        compare = result; //you store result inside of compare, if result is bigger than the compare value. You do that each time.
    }
    index ++; //increment index each time.
    }
    return compare; //return the value of the compare
}

/*
 * Algorithm for Part 3: Best Genome Function
 * For this, you are finding which of the 3 genomes best matches the sequence..
 * By calling the best match function, it'll automatically calculate how much the genome matches the string.
 * However, that's only for that genome alone. You need some way to compare it to the other scores, because maybe genome 2 can be better than 1, or vice versa.
 * To compare them, use if and else statements to compare the genomes to eachother to find the best match.
*/

int findBestGenome(string genome1, string genome2, string genome3, string seq)
{
    float genome1score = findBestMatch(genome1, seq); //gives you best match for first genome
    float genome2score = findBestMatch(genome2, seq); //gives you best match for second genome
    float genome3score = findBestMatch(genome3, seq); //gives you best match for third genome

    if(genome1score > genome2score && genome1score > genome3score) //comparing first genome to all others to see if it's best.
    {
        return 1;
    }
    else if(genome2score > genome1score && genome2score > genome3score) //comparing second genome to all others to see if it's best.
    {
        return 2;
    }
    else if(genome3score > genome1score && genome3score > genome2score)  //comparing third genome to all others to see if it's best.
    {
        return 3;
    }
    else
    {
        return 0; //if nothing is better than anything, return zero.
    }
}

