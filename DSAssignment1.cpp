#include <iostream>
#include <fstream> //file stream
#include <sstream>

using namespace std;

struct Sale
{
	string name;
	string listing;
	int price;

	Sale()
	{
		//default constructor
	}

	Sale(string n, string l, int cost)
	{
		name=n;
		listing=l;
		price=cost;
	}
};

bool conversion(string item)
{
    bool x = 1;
    if(item==" wanted")
    {
        x = 1;
        cout<<x<<endl;
    }
    else
    {
        x=0;
        cout<<x<<endl;
    }
}


int main()
{
	string filename;
	cout<<"Enter Filename ";
	cin>>filename;
	Sale allItems[100];
	/*for(int i=0; i<100; i++)
    {
        allItems[i]=0;
    */
	//inputfile.open(filename.c_str())
	ifstream myfile(filename);
	/*Sale allItems[100];
	ifstream myfile("garageSale.txt");*/
	if(myfile.is_open())
	{
		string line;
		int counter=0;

		while(getline(myfile, line))
		{

			//cout<<line<<std::endl; //to see if getline is working
			//string stream - incldue sstream (for strings)

			stringstream ss;
			//write line string into string stream
			ss<<line;
			string item;
			getline(ss, item, ',');
			allItems[counter].name=item;

			getline(ss,item,',');
			allItems[counter].listing=conversion(item);
            for(int i=0; i<100; i++)
            {
                if(item==wanted)
                {

                }
            }

			getline(ss,item);
			allItems[counter].price=stoi(item);

			counter++;
		}
	}
	else
	{
		cout<<"error";
	}
	for(int i=0; i<100; i++)
	{
		cout<<allItems[i].name<<" "<<allItems[i].listing<<" "<<allItems[i].price<<" "<<endl;
	}
}

