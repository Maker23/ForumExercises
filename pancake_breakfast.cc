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

#define DEBUG false

std::string People[] = {
	"Sam",
	"Dale",
	"Pat",
	"Alex",
	"Kim",
};

int Pancakes[5];

int validate_input(std::string Name)
{
  std::string input_string;
	int  numeric_value = 0;

	std::cin.exceptions(std::ios::failbit);
	
	while ( 1 ) {
		std::cout << "How many pancakes did " << Name << " eat?[1-20]: ";
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
	  //std::cout << "  [" << i+1 << "]" << People[i] << "\n";
	  Pancakes[i] = validate_input(People[i]);
	}
}

void BubbleSort(int Data[], int DataLen)
{
  /* This is not yet optimized, see http://en.wikipedia.org/wiki/Bubble_sort */
	bool swapped;
  int valone,valtwo;
	std::string strone,strtwo;

	do
	{
		swapped = false;
		for (int i=1; i < DataLen; i++) {
			if (Data[i-1] > Data[i] ){
				if (DEBUG) 
				{
					std::cout << "swapping " << Data[i-1] << 
					"  and " << Data[i] << "\n";
				}
				valone=Data[i-1];
				valtwo=Data[i];
				Data[i-1]=valtwo;
				Data[i]=valone;
				strone=People[i-1];
				strtwo=People[i];
				People[i-1]=strtwo;
				People[i]=strone;
				swapped = true;
			}
		}
	} while ( swapped);

}

int main()
{
	collect_data();
	BubbleSort(Pancakes, 5);
	for (int i=0; i < 5; i++) {
		std::cout << People[i] << " ate " << Pancakes[i] << " pancakes\n";
	}
}
