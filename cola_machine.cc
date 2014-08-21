/*
  Write a program that presents the user w/ a choice of your 5 favorite 
	beverages (Coke, Water, Sprite, ... , Whatever).
	Then allow the user to choose a beverage by entering a number 1-5.
	Output which beverage they chose.

	= If you program uses if statements instead of a switch statement, 
	  modify it to use a switch statement.
	= If instead your program uses a switch statement, modify it to use 
	  if/else-if statements.

	= Modify the program so that if the user enters a choice other than 1-5 then it will output "Error. choice was not valid, here is your money back."

*/

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#define DEBUG false

const std::string Beverages[] = {
	"Yunnan tea",
	"Assam tea",
	"Mint tea",
	"Roastaroma tea",
	"Hot chocolate",
};

void print_menu()
{	
  for (int i = 0; i<5; i++) 
	{
	  std::cout << "  [" << i+1 << "]" << Beverages[i] << "\n";
	}
}


int validate_input()
{
  std::string input_string;
	int  numeric_value = 0;

	std::cin.exceptions(std::ios::failbit);
	
	while ( 1 ) {
		std::cout << "Your choice [1-5]: ";
	  std::cin >> input_string;
	  std::stringstream ss (input_string);
  	ss.exceptions(std::ios::failbit);

    try 
		{
			ss >> numeric_value;
	    if ( (numeric_value < 1 ) || (numeric_value > 5) ) 
			{
	   		std::cout << "Error: Enter a number between 1 and 5\n";
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


int main()
{
  int bev_value=0;

	print_menu();
  bev_value = validate_input();
  std::cout << "You chose wisely. Enjoy your " << Beverages[bev_value - 1] << "\n";

}
