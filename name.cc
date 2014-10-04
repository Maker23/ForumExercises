/* A comment
*/

#ifndef NAMESH
#define NAMESH

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#endif

#define NAMEFILE "Names"

#ifndef DEBUG
#define DEBUG true
#endif

uint NumNames;
std::vector <std::string> allNames;


std::string ReturnAName(){
	int Number = rand() % NumNames;
	// if (DEBUG) { std::cout << "Number = " << Number << "\n";}
	return(allNames[Number]);
}

void InitializeNames()
{
	std::string line = "";
	std::ifstream inFile (NAMEFILE);

	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			allNames.push_back(line);
			NumNames++;
		}
	}
	if (DEBUG) { std::cout << "In InitializeNames, NumNames = " << NumNames << "\n";}
	inFile.close();
}

void TestName(){
	std::string Namel = "";
	InitializeNames();

	srand(time(NULL));

  Namel = ReturnAName();
	if (DEBUG){ std::cout << "Namel is " << Namel << "\n";}

}
