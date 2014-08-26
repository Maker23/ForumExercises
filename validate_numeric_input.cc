/*

  validate_numeric_input (MinimumValue, MaximumValue, MaximumNumberOfTries);


*/
#ifndef NUMERIC_INPUT
#define NUMERIC_INPUT

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#define NI_DEBUG false

#endif // NUMERIC_INPUT


#ifndef DEBUG
#define DEBUG NI_DEBUG
#endif


int validate_numeric_input(int MinRange, int MaxRange, int MaxTries=0)
{
  std::string input_string;
	int  numeric_value = 0;
	int  number_of_tries = 0;

	std::cin.exceptions(std::ios::failbit);
	
	do {
	  number_of_tries++;
		std::cout << "Enter a number between " << MinRange << " and " << MaxRange << "\n";
	  std::cin >> input_string;
	  std::stringstream ss (input_string);
  	ss.exceptions(std::ios::failbit);

    try 
		{
			ss >> numeric_value;
	    if ( (numeric_value < MinRange ) || (numeric_value > MaxRange) ) 
			{
	   		std::cout << "Error: Enter a number between " << MinRange << " and " << MaxRange << "\n";
			}
			else
			{
  			if ( DEBUG || NI_DEBUG ) {std::cout << "Numeric value = " << numeric_value << "\n";}
				return(numeric_value);
			}
		}
		catch (...) {
	    std::cout << "Dude, that was not an integer\n";
    }
	}
	while ( !MaxTries || (number_of_tries < MaxTries) );

	std::cout << "Sorry, you've reached the maximum number of attempts (" << MaxTries << ")\n";
	return(0); // Fail, but hard to return an error code.

}
