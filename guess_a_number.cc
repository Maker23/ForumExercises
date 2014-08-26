/* 
	Write a program that calculates a random number 1 through 100. The program then asks the user to guess the number.
	If the user guesses too high or too low then the program should output "too high" or "too low" accordingly.
	The program must let the user continue to guess until the user correctly guesses the number.

	★ Modify the program to output how many guesses it took the user to correctly guess the right number.

	★★ Modify the program so that instead of the user guessing a number the computer came up with, the computer guesses the number that the user has secretely decided. The user must tell the computer whether it guesed too high or too low.
	
	★★★★ Modify the program so that no matter what number the user thinks of (1-100) the computer can guess it in 7 or less guesses.
*/

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#define DEBUG false
#define MINRANGE 0
#define MAXRANGE 100



int validate_numeric_input(int Minin, int Maxin)
{
  std::string input_string;
	int  numeric_value = 0;

	std::cin.exceptions(std::ios::failbit);
	
	while ( 1 ) {
		std::cout << "Enter a number between " << Minin << " and " << Maxin << "\n";
	  std::cin >> input_string;
	  std::stringstream ss (input_string);
  	ss.exceptions(std::ios::failbit);

    try 
		{
			ss >> numeric_value;
	    if ( (numeric_value < Minin ) || (numeric_value > Maxin) ) 
			{
	   		std::cout << "Error: Enter a number between " << Minin << " and " << Maxin << "\n";
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
	return(0); // This should never happen

}

int main() {
	std::string Answer = "";
  int CurrentMin = MINRANGE;
  int CurrentMax = MAXRANGE;
	int NumGuesses = 0;
	int Guess = 0;
  
	std::cout << "You're thinking of a number ........\n\n";

	std::cout << "I will now guess your number.  Watch my brilliant number movez.\n";
	std::cout << "Enter h if my guess is high, l if my guess is low.\n";

  do 
	{
	  NumGuesses++;
		Guess = (((CurrentMax - CurrentMin) / 2) + CurrentMin);
		if (DEBUG) { std::cout << "Guess = " << Guess << "   CurMin = " << CurrentMin << "  CurMax = " << CurrentMax << "\n";}
  	std::cout << "Is your number " << Guess << "? [y|h|l] \n";
	  std::cin >> Answer;
		if ( Answer == "h" ) 
		{
			CurrentMax = Guess - 1;
	  }
		else if ( Answer == "l" ) 
		{
			CurrentMin = Guess + 1;
		}
		else if ( Answer == "y" ) 
		{}
		else 
		{
			std::cout << "Didn't understand that, try again.\n";
		}

	}
	while ( Answer != "y") ;

  std::cout << "HA.  I am like a numberz jeanyus. booyeah.\n";
  std::cout << "I guessed your number in " << NumGuesses << " tries\n";

  return 0;
}
