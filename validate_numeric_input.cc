/*

  validate_numeric_input (MinimumValue, MaximumValue, MaximumNumberOfTries, Prompt);


*/
#ifndef NUMERIC_INPUT		
#define NUMERIC_INPUT

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstdio>
#define NI_DEBUG false

#endif // NUMERIC_INPUT


#ifndef DEBUG  // External DEBUG, if set, overrides internal NI_DEBUG setting
#define DEBUG NI_DEBUG 
#endif

/* ***************************************************************************
 *
 *  Validate that the string is an integer number
 *  	* Can begin with a minus sign (negative)
 *  	* Can not have any characters other than [0-9] and "."
 *  		* If "." appears, test the string as a float. It may be a number.00
 *
 * ***************************************************************************/

int validate_numeric_input(
	int MinRange=INT_MIN, 
	int MaxRange=INT_MAX, 
	int MaxTries=0, 
	std::string Prompt="")
{
  std::string input_string;		// Users's input from the terminal
	std::string test_string;		// Int value converted to string for comparison
	int  length_of_input;				// Length of the users's input string
	int  length_of_test_string; // Length of the test string  TODO do we need this?
	int  numeric_value = 0;			// The numeric value, return if successful
	int  number_of_tries = 0;		// Number of times user has tried to enter data
	char buffer[256];

	std::cin.exceptions(std::ios::failbit); // TODO do we need this?

	if ( Prompt == "" )
	{
		sprintf(buffer, "Enter an integer between %d and %d: ", MinRange, MaxRange);
		Prompt = buffer;
	}
	
	do {
	  number_of_tries++;
		//std::cout << "Enter an integer between " << MinRange << " and " << MaxRange << ": ";
		std::cout << Prompt;
	  std::cin >> input_string;
		length_of_input = input_string.length();
	  std::stringstream ss (input_string);
 		ss.exceptions(std::ios::failbit);

    try 
		{
			ss >> numeric_value;
	    if ( (numeric_value < MinRange ) || (numeric_value > MaxRange) ) 
			{
  			if ( DEBUG || NI_DEBUG ) {std::cout << "Numeric value l.49 = " << numeric_value << "num_tries = " << number_of_tries << "\n";}
	   		std::cout << "Error: Value is outside permitted range.\n";
				//TODO: this error is encounter first if the user enters an 
				// out-of-range integer followed by junk, eg, "123456879test"
			}
			else
			{
  			if ( DEBUG || NI_DEBUG ) {std::cout << "Numeric value l.54 = " << numeric_value << "num_tries = " << number_of_tries << "\n";}

				std::stringstream st;
				st << numeric_value;
				test_string = st.str();
				length_of_test_string = test_string.length();


  			if ( DEBUG || NI_DEBUG ) 
				{
					std::cout << "input length: " <<  length_of_input << "\ntest_string: " 
						<< test_string << "\nlength: " << length_of_test_string << "\n";
				}
				if ( length_of_input != length_of_test_string ) 
				{
					std::cout << "ERROR: Part of your input was not an integer\n";
				}
				else
				{
					return(numeric_value);
				}

			}
		}
		catch (...) {
			// TODO: This can occur when the user enters an integer with leading zeroes; fix
	    std::cout << "Dude, that was not an integer\n";
  		if ( DEBUG || NI_DEBUG ) {std::cout << "Debug l.54 intut: " << input_string; }
    }
			  std::cin.clear();
			  std::cin.ignore(10000,'\n');
	}
	while ( !number_of_tries || (number_of_tries < MaxTries) );

	std::cout << "Sorry, you've reached the maximum number of attempts (" << MaxTries << ")\n";
	return(0); // Hard to return an error code.

}

/* ***************************************************************************
 *
 * ***************************************************************************/
int validate_integer_input(int MinRange=INT_MIN, int MaxRange=INT_MAX, int MaxTries=0, std::string Prompt="")
{
	validate_numeric_input(MinRange, MaxRange, MaxTries, Prompt);
}
#ifndef Library
int main() {
  /* standalone test mode */
	//validate_numeric_input(10,99,3,"Standalone test mode. Enter an integer: ");
	validate_numeric_input(-20,99,3,"");
}
#endif
