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

#include "validate_numeric_input.cc"

int main()
{
	int unused_value = 0;
	int max_tries = 0;
	int min_range = 10;
	int max_range = 100;

  unused_value = validate_numeric_input(min_range,max_range, max_tries);
	std::cout << "\n2nd try\n";
  unused_value = validate_numeric_input(min_range,max_range);

}
