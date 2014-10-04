/*

  validate_numeric_input (MinimumValue, MaximumValue, MaximumNumberOfTries);


*/
#ifndef NUMERIC_INPUT
#define NUMERIC_INPUT

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#define NI_DEBUG false

#endif // NUMERIC_INPUT


#ifndef DEBUG
#define DEBUG NI_DEBUG
#endif


int validate_numeric_input(int MinRange=INT_MIN, int MaxRange=INT_MAX, int MaxTries=0)
{
  std::string input_string;
	std::string test_string;
	int  length_of_input;
	int  length_of_test_string;
	int  numeric_value = 0;
	int  number_of_tries = 0;

	std::cin.exceptions(std::ios::failbit);
	
	do {
	  number_of_tries++;
		std::cout << "Enter an integer between " << MinRange << " and " << MaxRange << ": ";
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
	   		std::cout << "Error: ";
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
	    std::cout << "Dude, that was not an integer\n";
  		if ( DEBUG || NI_DEBUG ) {std::cout << "Debug l.54 saw " << input_string; }
    }
			  std::cin.clear();
			  std::cin.ignore(10000,'\n');
	}
	while ( !number_of_tries || (number_of_tries < MaxTries) );

	std::cout << "Sorry, you've reached the maximum number of attempts (" << MaxTries << ")\n";
	return(0); // Fail, but hard to return an error code.

}

#ifndef Library
int main() {
  /* standalone test mode */
	validate_numeric_input(10,99,2);
}
#endif
