'''
Author:Muntaha Pasha
CS1300 Fall 2017
Recitation: 204 Camila
Assignment 9
'''

'''
 COMPUTE CENCUS
 * Algorithm description for function howMany() goes here
 * Outputs Current Population based on three rates
 * b.r: every 8 secs, d.r: every 12 secs, i.r: 33 secs
 * Returns Population in Year
 '''

def compute_census(List_of_rates, Curr_population):
    secondsinyear=31536000 #The number of seconds in a year
    birthrate=secondsinyear/List_of_rates[0] #seconds in year divide by first rate in list of rates which is birth rate
    deathrate=secondsinyear/List_of_rates[1] #seconds in year divide by second rate in list of rates which is death rate
    immigrationrate=secondsinyear/List_of_rates[2] #seconds in year divide by third rate in list of rates which is immmigration rate

    howMany = Curr_population + birthrate + immigrationrate - deathrate #add all the populations and take the death rate out of the total
    return howMany #return total

'''
 CONVERT SECONDS
 *To find days, you would do s/86,400
 *You will get a remainder, and you take that away from the total number of seconds
 *Then, to find the number of hours you would do s/3600
 *You take the remainder away from the total number of seconds again
 *To find minutes you would do s/60
 *Your remainder would then be the number of seconds leftover
 *Final function output should be expressed as cout of days, hours, minutes,
 seconds.
'''

def convert_seconds():
	seconds=int(raw_input()) #input the number of seconds you wish to convert
	clock=seconds #store that into a variable called clocks

	if seconds>10000000000 or seconds<0: #condition for seconds
		days=0 #set all variables to zero
		hours=0 #set all variables to zero
		minutes=0 #set all variables to zero
		seconds=0 #set all variables to zero
		remainder=0 #set all variables to zero

	else:
		days=seconds/86400 #the number of days
		remainder=seconds%86400 #Whatever you have left over you use to calculate the hours
		hours=remainder/3600 #number of hours
		remainder=remainder%3600 #that remainder becomes amount of time for minutes
		minutes=remainder/60 #number of minutes
		remainder=remainder%60 #that remainder is the remainder
		seconds=remainder #seconds is the remainder
		print "{} corresponds to: {} days, {} hours, {} minutes, {} seconds.".format(clock,days,hours,minutes,seconds)


'''
 GENERATE STORY
* Algorithm description:
* First you will create 3 separate function for all the stories. Story 1, Story 2, and Story 3.
* All stories will be voids, and in them you'll make string variables, and define them, then have user inputs for each of the variables.
* The Menu function will call all 3 story function, on the menu function you can pick which story you want to play, by setting a char variable that takes user input.
* Depending on what char the user inputs, menu will generate the story number, and if they don't select a valid response, no story will generate.
* Story 1-3 will all be voids, they don't return you any value, they're all just manipulating strings into a function.
* Menu function will also be a void because it's not returning you any value either, but through menu, you need a set of if and else statements to guide which char entry leads to what response.
* Then, at the end, all of this will be called into your main. Main will not do anything except call the menu function, which menu will call all three of your stories.
* No function inputs our outputs will be done in main. main will only execute menu.
	list_of_strings.append("I was going to ")
	list_of_strings.append(raw_input("Enter a location:"))
	list_of_strings.append(raw_input("Enter number of hours:"))

	first iterate through the list of strings
	at every odd number we are taking input, print whatever at list and use raw input
	users input replaces the string at the odd number position
	print/concatinate list of strings
'''


def generate_story(list_of_strings):

	for i in range(0,len(list_of_strings)): #for loop iterating through a list of strings
		if i%2!=0: #if the number of numbers in the list is even..
			prompt=list_of_strings[i] #store that index of the half number value into prompt
			list_of_strings[i]=raw_input(prompt) #the list of strings at i is extracted into raw input

	story="" #empty string variable to hold something
	for j in range(0,len(list_of_strings)): #another for loop
		story+=list_of_strings[j]+" " #add the different values together

	return story #return the story


'''
 SIMILARITY SCORES
* float function similarity score will take two parameters, sequence 1, and sequence 2.
* It will only calculate a similarity
* The index will reiterate through both strings, one character at a time, and compare them.
* Whenever it sees a mismatch, it'll store it into hamming distance.
* You calculate simscore by putting hamming distance and sequence length into the formula for it.
* Once that's been calculated, return the simscore.
'''

def similarity_score(seq1, seq2): 
	seqlen1=len(seq1) #length of first sequence
	seqlen2=len(seq2) #length of second sequence
	index=0 #index is zero
	sim_score=0.0 #similarity score is zero
	hamming_dist=0.0 #hamming distance is zero

	if seqlen1 == seqlen2: #if the two sequence lengths are equal
		while index < seqlen1: #and while index length is less than sequence length
			if seq1[index] != seq2[index]: #if the two don't have the same values at the index
				hamming_dist+=1 #Then increment hamming distance
			index+=1 #Also increment index

		sim_score=(seqlen1-hamming_dist)/seqlen1 #the score is the sequence length minus the hamming distance all divided by sequence length
		return sim_score #return the similarity score

	else:
		return 0


'''
 BEST MATCH
 * For this, you are finding which of the 3 genomes best matches the sequence..
 * By calling the best match function, it'll automatically calculate how much the genome matches the string.
 * However, that's only for that genome alone. You need some way to compare it to the other scores, because maybe genome 2 can be better than 1, or vice versa.
 * To compare them, use if and else statements to compare the genomes to eachother to find the best match.
'''

def best_match(genome, sequence):
	index=0 #index is zero
	compare=0.0 #compare is zero
	bestindex=0 #best index is zero

	while index<len(genome):
		result=similarity_score(genome[index:index+len(sequence)], sequence) #calling function with parameters from best match
		#print "substring", genome[index:index+len(sequence)], "sequence", sequence
		#print "result",result
		if result>compare: #if it's greater than compare
			compare=result #then compare is the result
			bestindex=index
		index+=1
	return bestindex #return the position of where best match begins


'''
 CALCULATE THE STATS
* Frst you are copying the original array over, using the copy function that you wrote, so that you can store the array into a variable that you have control
* over, and so that you don't mess with the original array.
* After that, you want to call your sorting function to sort the array so that we can find the median.
* Once the array has been copied, and sorted, you write out the median function. If it's odd, you know the median is the position of the size/2.
* However, if it's an even array, you have to calculate the average between two middle numbers, so it requires more steps. You divide, and then average.
* The function will then return you the middle value.
* For average you add all the elements and then divide by the length of the list.
'''

def calc_stats(list_of_values):

	result=0.0 #result is zero
	median=0.0 #median is zero
	
	for i in range(0,len(list_of_values)): #iterate through a list of values
		result+=list_of_values[i] #store that index value into result
	average=result/len(list_of_values) #take that result and divide it by how many numbers there are in the list

	list_of_values.sort() #sort the number of values

	if len(list_of_values)%2==0: #if the numbers in the list are even
		index1=len(list_of_values)/2 #then divide list by half
		index2=index1-1 #take the next value next to it
		median=(list_of_values[index1]+list_of_values[index2])/2.0 #average those two values
	else:
		index3=len(list_of_values)/2 #if it's odd it's only rhe middle number
		median=list_of_values[index3]

	return [average,median] #return the average then the median


'''
 PARSE RATINGS
* This is storing the file information into 2 arrays, a 2.D array and a single array for users only.
* By using the search function, you first see if the user is repeated in the file, and as long as the book I.D is not the same, the user can be repeatedly added.
* Iterate through the filename by using getline, splitting the string, storing the first value into users, and the second two values into ratings.
* You need to make sure you convert the values in the array at the position 1 and 2 where the book i.d and rating is held
* You need to transfer all that info from the files into those arrays
* Then you exit the file.
'''
def parse_ratings(file_name):
	
	fr=open(file_name,'r') #open and read the file
	lines=fr.readlines() #read it in line by line and store it in lines
	temp=[] #temp list

	for line in lines:
		line=line.replace('\n',"") #replace end of line character with empty
		splitted=line.split(', ') #split at the comma
		name=splitted[0] #name is at splitted position 0
		rates=splitted[1].split(' ') #ratings at splitted position 1
		rates=map(int, rates) #converts string to int
		temp.append([name, rates]) #append the names and rates into temp

	return temp #return temp


'''
MAIN FUNCTION FOR TESTING
'''

def main():
	birth_rate=8
	death_rate=12
	Curr_population=1000000
	new_immigration_rate=33
	List_of_rates=[birth_rate, death_rate, new_immigration_rate]
	print compute_census(List_of_rates, Curr_population)

	print convert_seconds()

	str1='I went skiing to'
	prompt1='Enter a location:'
	str2='it was really crowded and I stayed in line for'
	prompt2='Enter number of hours:'
	str3='hours'
	list_to_story=[str1,prompt1,str2,prompt2,str3]

	print(generate_story(list_to_story))

	print similarity_score("CCGCCGCCGA","CCTCCTCCTA")

	print best_match("AAGTTCAGTCGCTACAGT", "GBT")

	list_of_numbers=[1,2.5,3,8,10.5,5]
	print calc_stats(list_of_numbers)

	print parse_ratings("file.txt")

if __name__=="__main__":
	main()