/*
	V2 : Now with structs

*/
/*
  Write a program that asks the user to enter the number of pancakes eaten 
	for breakfast by 10 different people (Person 1, Person 2, ..., Person 10)
	Once the data has been entered the program must analyze the data and output 
	which person ate the most pancakes for breakfast.

	= Modify the program so that it also outputs which person ate the least 
	  number of pancakes for breakfast.

	== Modify the program so that it outputs a list in order of number of 
		 pancakes eaten of all 10 people.
		i.e.
		Person 4: ate 10 pancakes
		Person 3: ate 7 pancakes
		Person 8: ate 4 pancakes
		...
		Person 5: ate 0 pancakes
*/

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#define DEBUG true

struct persondata {
	std::string	Name;
	int 				NumPancakes;
};

persondata People[] = {
	{"Sam", },
	{"Dale", },
	{"Pat", },
	{"Alex", },
	{"Kim", },
};

/* ************************************************************************ */

int validate_input(std::string Name)
{
  std::string input_string;
	int  numeric_value = 0;

	std::cin.exceptions(std::ios::failbit);
	
	while ( 1 ) {
		std::cout << "How many pancakes did " << Name << " eat? [0-20]: ";
	  std::cin >> input_string;
	  std::stringstream ss (input_string);
  	ss.exceptions(std::ios::failbit);

    try 
		{
			ss >> numeric_value;
	    if ( (numeric_value < 0 ) || (numeric_value > 20) ) 
			{
	   		std::cout << "Error: Enter a number between 0 and 20\n";
			}
			else
			{
  			if ( DEBUG ) {std::cout << "Numeric value = " << numeric_value << "\n";}
				return(numeric_value);
			}
		}
		catch (...) {
	    std::cout << "Dude, that was not an integer\n";
    }
  }

}


void collect_data()
{	
  for (int i = 0; i<5; i++) 
	{
	  People[i].NumPancakes = validate_input(People[i].Name);
	}
}

void BubbleSort(persondata Data[], int DataLen)
{
  /* This is not yet optimized, see http://en.wikipedia.org/wiki/Bubble_sort */
	bool swapped;
  persondata tmpdata;

	do
	{
		swapped = false;
		for (int i=1; i < DataLen; i++) {
			if (Data[i-1].NumPancakes > Data[i].NumPancakes ){
				if (DEBUG) 
				{
					std::cout << "swapping " << Data[i-1].Name << ":" << Data[i-1].NumPancakes << 
					"  and " << Data[i].Name << ":" << Data[i].NumPancakes << "\n";
				}
				tmpdata.Name=Data[i-1].Name;
				tmpdata.NumPancakes=Data[i-1].NumPancakes;
				Data[i-1].Name=Data[i].Name;
				Data[i-1].NumPancakes=Data[i].NumPancakes;
				Data[i].Name = tmpdata.Name;
				Data[i].NumPancakes = tmpdata.NumPancakes;
				swapped = true;
			}
		}
	} while ( swapped);

}

/* ************************************************************************ */
int main()
{
	collect_data();
	BubbleSort(People, 5);
	for (int i=0; i < 5; i++) {
		std::cout << People[i].Name << " ate " << People[i].NumPancakes << " pancakes\n";
	}
}
