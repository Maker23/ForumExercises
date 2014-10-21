#include <iostream>
#include <cstdlib>
#include <string>
#define pi 3.14159;
using namespace std;

int strings()
{
	string myString;
	myString = "This is a string. (!!)\n";
	cout << myString;

	myString = "This is a " "long multi-" 
	  "part string\n";
	cout << myString;

	return 0;
}

int types() 
{

	char oneByte = 'a';
	char twoByte ('b');
	char threeByte {'c'};

	signed int anInteger = 2047;
	unsigned int brokenInteger;
	signed long aLongInteger = 4294967296 + 10;
	float aFloat = 1.2345;

	bool aBoolean = true;
	
	cout << "Here's a list of my variables: " << endl;

	cout << "char = " << oneByte << twoByte << threeByte << endl;
	cout << "int = " << anInteger << endl;
	cout << "long = " << aLongInteger << endl;
	cout << "float = " << aFloat << endl;
	cout << "bool = " << aBoolean << endl;

	cout << "This should break" << endl;
 	brokenInteger = 4294967296 + 10;
	cout << "broken int = " << brokenInteger << endl;

	cout << "Can we math with chars? Yes" << endl;
	cout << threeByte - oneByte << endl;

	cout << ++anInteger  << endl;
	cout << anInteger++  << endl;
	cout << anInteger  << endl;
	return 0;

}

int randomnum() 
{
  int OneNum = 0,TwoNum = 0;
  float FNumber = rand();
  int INumber = rand();

  TwoNum = INumber %  7;

  cout << "Float random " << FNumber << " mod: " << OneNum << "\n";
  cout << "Int   random " << INumber << " mod: " << TwoNum  << "\n";
  
  return 0;
}

int main(){
	cout << "Hello world! (C++)" << endl;
	strings();
  randomnum();
	// types();
	return 0;
}

