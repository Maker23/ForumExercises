/*
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
*/

#define DEBUG true

#define Library
#include "validate_numeric_input.cc"

int main()
{
	int unused_value = 0;
	int max_tries = 0;
	int min_range = 10;
	int max_range = 100;

  unused_value = validate_numeric_input(min_range,max_range, max_tries);
  unused_value = validate_numeric_input(0,10,3);
}
