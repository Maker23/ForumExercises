/*

  Write a program that ccontinues to asks the user to enter any number other 
	than 5 until the user enters the number 5.  Then tell the user "Hey! you 
	weren't supposed to enter 5!" and exit the program.

	= Modify the program so that after 10 iterations if the user still hasn't 
	  entered 5 will tell the user "Wow, you're more patient then I am, you win." 
	  and exit.

	== Modify the program so that it asks the user to enter any number other 
	   than the number equal to the number of times they've been asked to 
		 enter a number. (i.e on the first iteration "Please enter any number 
		 other than 0" and on the second iteration "Please enter any number 
		 other than 1" etc. etc. The program must behave accordingly exiting 
		 when the user enters the number they were asked not to.)
*/

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#define DEBUG false
#define CONSTRAINED_NUM 5

int validate_input(int max_tries)
{
  std::string input_string;
	float  numeric_value = 0;
	int num_tries = 0;

	std::cin.exceptions(std::ios::failbit);
	
	while ( 1 ) {
	  num_tries++;
    std::cout << "Enter a number other than " << CONSTRAINED_NUM << ": ";
	  std::cin >> input_string;
	  std::stringstream ss (input_string);
  	ss.exceptions(std::ios::failbit);

    try 
		{
			ss >> numeric_value;
	    if ( numeric_value == CONSTRAINED_NUM ) 
			{
	   		std::cout << "Error: You weren't supposed to enter " << CONSTRAINED_NUM << "\n";
				return(1);
			}
			else
			{
  			if ( DEBUG ) {std::cout << "Numeric value = " << numeric_value << "\n";}
			  if ( max_tries == num_tries ) {
	   			std::cout << "You are more patient than I am.  You win.\n";
					return(0);
				}
			}
		}
		catch (...) {
	    std::cout << "That wasn't a number!!\n";
    }
  }

}


int main()
{
	int unused_value = 0;
	int max_tries = 0;

  unused_value = validate_input(max_tries);

}
