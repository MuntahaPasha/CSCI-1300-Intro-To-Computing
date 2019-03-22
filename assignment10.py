'''
Author:Muntaha Pasha
CS1300 Fall 2017
Recitation: 204 Camila
Assignment 10
'''
'''
READ BOOKS Function:
1. This function will firstly read in a file, that contains a list full of book names and Author names.
2. It will parse the book and authors from one another, and store them into a list.
3. The function will then strip it of punctuation, and split it at the commas.
4. It will then store the data into the other list.
5. It will return the list.
'''
def read_books(filename):
	temp=[] #Temporary List to hold values
	try:
		file=open(filename, "r") #Opening file command
		for line in file: 
			if(len(line)==0): #if the length of the line is zero it means nothing is stored
				continue #move ahead
			else:
				line=line.strip().split(',') #strip and split the line of punctuation
				temp.append(line[::-1]) #append to the list through the end
		file.close() #close the file
		return temp #return the list
	except:
		return None

'''
READ USERS Function:
1.Read users takes in a list of users
2. It stores the values into a dictionary, making the user I.D the key, and the ratings the corresponding values
3. The key will be the name of the user, and the rest will be the ratings.
4. This function reads in the file, parses it, and stores the corresponding values.
'''
def read_users(user_file):
	temp={} #temporary list to hold values
	try:
		file=open(user_file, "r") #open the file to read
		for line in file:
			if(len(line)==0): #for each line, if the file is empty
				continue #then just continue
			else:
				line=line.strip().split(' ') #strip and split the line
				temp[line[0]]=map(int,line[1:]) #convert all string ratings to int, and store them into the dictionary
		file.close() #close the file
		return temp #return the dictionary
	except:
		return None

'''
CALCULATE AVERAGE Function:
1. This function calculates average values between two users.
2. It will take in a dictionary of ratings, and it will calculate the average using it.
3. It will read down the list of users.
4. It will find their scores for the certain book it's rating.
5. Skip over the zero's which means the user hasn't read the book.
6. Going down by column, calculate the average of the book.
7. Return the average rating for whatever the user inputs.
'''
def calculate_average_rating(ratings_dict):
	avg_ratings=[] #temp list to hold average ratings
	keep_going=True #A true or false statement to initiate the loop
	index=0 #index variable
	while keep_going==True: #while this variable is true
		counter=0 #set a count to zero
		summ=0.0 #set a variable to hold sum
		for user in ratings_dict: #for each user in the rating dictionary that the user passes in
			user_ratings=ratings_dict[user] #store it into a new array called the user ratings
			if index>=len(user_ratings): #if index has succeeded length of the user rating
				keep_going=False #then the variable becomes false
				break #break away and quit loop
			if user_ratings[index]==0: #if there is nothing in the dictionary
				continue #continue on
			summ+=user_ratings[index] #the sum of each rating gets held in sum vairable
			counter+=1 #incrememnt counter
		if counter==0: #if the count is zero
			avg_ratings.append(0.0) #then your average is jsut zero because it means nothing is in the dictionary
		else:
			#avg_ratings.append(round(summ/counter,2))
			avg_ratings.append(summ/counter) #calculate average and store it into avg ratings list
		index+=1 #increment the index
	return avg_ratings #return the average ratings

'''
LOOKUP AVERAGE Function:
1. This function will look up the average rating given any book dictionary at any position.
2. It will look at whatever index is provided.
3. The function will return you the book name, the author, and the rating for it.
4. Using the index variable it will assign the proper names and averages.
5. It will print it all out in the end.
'''
def lookup_average_rating(index, book_dict, avg_ratings_dict):
	book=book_dict[index] #find the book name and author at the given index
	rating=avg_ratings_dict[index] #find the rating

	#return "("+str(rating)+") "+book[0]+" by "+book[1]
	return "("+"%.2f"%rating+") "+book[0]+" by "+book[1] #display the rating, the book name and then the author.


class Recommender:
	#DEFAULT CONSTRUCTOR
	def __init__(self, books_filename, self_filename): 
		self.book_list=[] #Setting a book list attribute to be shared by methods
		self.user_dictionary={} #Setting a user dictionary attribute
		self.average_rating_list=[]	#Setting another list to hold all average ratings
		self.read_books(books_filename) #Defining a method of read books
		self.read_users(self_filename) #Define method of read users
		self.calculate_average_rating() #calculate the average method

	#READ BOOKS FUNCTION
	def read_books(self, file_name):
		try:
			file=open(file_name, "r") #Open the file
			for line in file:
				if(len(line)==0):
					continue
				else:
					line=line.strip().split(',') #Strip all lines in the file of their punctuation
					self.book_list.append(line[::-1]) #use the attribute given, of book_list to hold the book title and author
			file.close()
		except:
			return None

	#READ USERS FUNCTION
	def read_users(self, file_name):
		try:
			file=open(file_name, "r") #read in file
			for line in file:
				if(len(line)==0):
					continue
				else:
					line=line.strip().split(' ') #strip it
					self.user_dictionary[line[0]]=map(int,line[1:]) #convert and store it into user dictionary given
			file.close()
		except:
			return None

	#CALCULATE AVERAGE RATING
	def calculate_average_rating(self):
		keep_going=True
		index=0
		while keep_going==True:
			counter=0
			summ=0.0
			for user in self.user_dictionary: #Use the parameter dictionary privided
				user_ratings=self.user_dictionary[user]
				if index>=len(user_ratings):
					keep_going=False
					break
				if user_ratings[index]==0:
					continue
				summ+=user_ratings[index]
				counter+=1
			if counter==0:
				self.average_rating_list.append(0.0)
			else:
				#self.average_rating_list.append(round(summ/counter,2))
				self.average_rating_list.append(summ/counter)
			index+=1

	#LOOKUP AVERAGE RATING 
	def lookup_average_rating(self, book_index):
		book=self.book_list[book_index]
		rating=self.average_rating_list[book_index] #use the average rating list provided

		#return "("+str(rating)+") "+book[0]+" by "+book[1]
		return "("+"%.2f"%rating+") "+book[0]+" by "+book[1]

	#CALCULATE THE SIMILARITY FUNCTION
	'''
	Calculate the similarity takes two users scores, it calculates the dot product of them.
	It first multiplies the two numbers of the two users at the same index, and adds them to all other indexes.
	It stores that into a vairable called similarity measure which is the dot product result.
	The function then returns that.
	'''
	def calc_similarity(self, user1, user2):
		userOne=self.user_dictionary[user1] #user one is the user dictionary position of the first user privided
		userTwo=self.user_dictionary[user2] #user two is the user dictionary position of the second user provided
		similarity_measure=0 #the measure is set to 0

		for index in range(0,len(userOne)): 
			similarity_measure=similarity_measure+(userOne[index]*userTwo[index]) #calculate at the same index the dot product of the two users' ratings
		return similarity_measure #return that number

	#GET MOST SIMILAR USER FUNCTION
	'''
	Most similar user compares the rating of a given user with any other user in the dictionary
	It takes the user I.D, it looks at their ratings
	It then loops down through all other user's ratings and performs the dot product with their ratings.
	Using the dot product, it will return a certain score, after comparing their ratings.
	Depending on what the number is, it will tell you the name of the user who has ratings similar to yours.
	'''
	def get_most_similar_user(self, current_user_id):
		best_match_key="" #An empty string
		best_score=0 #Variable to hold best score
		for user in self.user_dictionary:
			if user==current_user_id: #make sure you don't loop over the user itself
				continue
			result=self.calc_similarity(current_user_id,user) #calculate the similarity function is called to give us the dot product
			if result>best_score: #if it's greater than compare
				best_score=result #then compare is the result
				best_match_key=user #best match key is the user's result

		return best_match_key #return that best match

	#RECCOMMEND BOOKS FUNCTION
	'''
	This Function returns a list of books that matches a given user's ratings.
	What this does, is it uses the similar user from the previous function, and finds books that they rated a 3 star or higher.
	It then displays all the books that said user has rated highly.
	The user can see what books might they read next deending on what they loved.
	'''
	def recommend_books(self, current_user_id):
		book_list=[] #temporary list
		best_match=self.get_most_similar_user(current_user_id) #use the most similar user function to first find the user that best matches given user
		best_match_ratings=self.user_dictionary[best_match] #Find all the ratings of the similar user
		user_ratings=self.user_dictionary[current_user_id] #Find ratings of the other user
		for i in range(0,len(best_match_ratings)-1): 
			if best_match_ratings[i]<3: #If the ratings are less than 3, we want to ignore them
				continue
			if user_ratings[i]!=0: #If they are not 0 we also want to ignore them
				continue
			book_list.append(self.lookup_average_rating(i)) #Add to the list the average rating function which gives the rating and book name and author
		return book_list #return the list of books

#MAIN TESTING
def main():
    
	print read_books("book.txt")
	print read_users("ratings.txt")
	var=read_users("ratings.txt")
	print calculate_average_rating(var)
	print lookup_average_rating(0, read_books("book.txt"), calculate_average_rating(read_users("ratings.txt")))
	
	rec= Recommender("book.txt", "ratings.txt")
	print rec.lookup_average_rating(1)
	print rec.calc_similarity("Ben","Moose")
	print rec.get_most_similar_user("Moose")
	
	print rec.recommend_books("Megan")
	print rec.recommend_books("Tiffany")
	print rec.recommend_books("Moose")
	print rec.recommend_books("Ella")
	
 

if __name__ == "__main__":
    main()

