/*
  Strings are your friends, until they betray you.
	Requires:
	variables, data types, and numerical operators
	basic input/output
	logic (if statements, switch statements)
	loops (for, while, do-while)
	functions
	strings & string functions


	Write a program that asks for a user first name and last name separately.
	The program must then store the users full name inside a single string and out put it to the string.
	i.e.
	Input:
	John
	Smith
	Output:
	John Smith

	★ Modify the program so that it then replaces every a, e, i , o, u w/ the letter z.
	i.e.
	John Smith -> Jzhn Smzth

	★★ Modify the Program so that it reverses the users name
	i.e.
	John Smith -> htimS nhoJ

*/

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

class Name {
	char SubChar;

	public:
		std::string	Firstname;
		std::string	Lastname;
		std::string Fullname;
		std::string Revname;
		std::string Repname;
		Name ();
		Name (std::string, std::string);

		void	Reverse();
		void  Print();
		void  ReplaceVowels(char);

};

Name::Name() {
  Firstname = "";
	Lastname = "";
	Fullname = "";
	Revname = "";
	Repname = "";
	SubChar = 'z';
};

Name::Name(std::string Fn, std::string Ln) {
  Firstname = Fn;
	Lastname = Ln;
	Fullname = Fn + " " + Ln;
	this->Reverse();
	(*this).ReplaceVowels('z');
};

void Name::Reverse() {
	std::size_t Len = Fullname.length();

	for (int i=Len; i >= 0; i--)
	{
		Revname += Fullname[i];
	}
};

void Name::Print() {
  std::cout << "First name name is " << Firstname << ", Last name is " << Lastname << ", ";
  std::cout << "Full name is " << Fullname << "\n";
  std::cout << "Revr name is " << Revname << "\n";
  std::cout << "Repl name is " << Repname << "\n";
}

void Name::ReplaceVowels(char SC){
	SubChar = SC;  
								/* Need to fix this - look for the default value first */
  const std::string Vowels = "aeiou";
  Repname = Fullname;


  std::size_t Found = Repname.find_first_of(Vowels);
	while ( Found != std::string::npos) {
		Repname[Found] = SubChar;
  	Found = Repname.find_first_of(Vowels, Found+1);
	}

};

int main() {

  std::string SOne = "Testly";
	std::string STwo = "McSnaffle";

	Name WorkingTitle (SOne, STwo);
	WorkingTitle.Print();
	
	return(0);
};
