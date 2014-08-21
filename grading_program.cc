/*
  Write a program that allows the user to enter the grade scored in a programming class (0-100).
  If the user scored a 100 then notify the user that they got a perfect score.
  
  = Modify the program so that if the user scored a 90-100 it informs the user that they scored an A

  = Modify the program so that it will notify the user of their letter grade
    0-59 F 60-69 D 70-79 C 80-89 B 90-100 A
*/

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#define DEBUG false

int ConvertNumericGradeToLetterGrade (int numeric_grade) 
{
  if ( ! (numeric_grade / 60 ) ) 
	{
	  std::cout << "You got an F. Time to change your major.\n";
    return(0);
	}
	else if ( ! (numeric_grade / 70 ) )
	{
	  std::cout << "That's a D, as in \"Didn't try\".\n";
    return(0);
	}
	else if ( ! (numeric_grade / 80 ) )
	{
	  std::cout << "You got a C. How does it feel to be average?\n";
    return(0);
	}
	else if ( ! (numeric_grade / 90 ) )
	{
	  std::cout << "That's a B, as in \"Better luck next time.\"\n";
    return(0);
	}
	else if ( (! (numeric_grade / 100 )) || numeric_grade == 100 )
	{
	  std::cout << "Congratulations on your A!\n";
    return(0);
	}
	std::cout << "I dunno why we're here\n";
  return(1);
}


int main()
{
  std::string input_string;
	float  numeric_grade = 0;

	std::cin.exceptions(std::ios::failbit);
	

	while ( 1 ) {
    std::cout << "Input numerical grade[0-100]: ";
	  std::cin >> input_string;
	  std::stringstream ss (input_string);
  	ss.exceptions(std::ios::failbit);

    try 
		{
			ss >> numeric_grade;
	    if ( (numeric_grade < 0 ) || (numeric_grade > 100) ) 
			{
	   		std::cout << "Error: Enter a number between 0 and 100\n";
			}
			else
			{
  			if ( DEBUG ) {std::cout << "Numeric grade = " << numeric_grade << "\n";}
				ConvertNumericGradeToLetterGrade (numeric_grade);
				return(0);
			}
		}
		catch (...) {
	    std::cout << "Dude, that was not an integer\n";
    }
  }

	return(0); // We should never get here
}

