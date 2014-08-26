/*
	From http://www.cplusplus.com/faq/sequences/arrays/sizeof-array/

	I can't believe this will work... OMG IT WORKS

*/

#include <cstdlib>
#include <iostream>
#include <string>


template <typename T, size_t N>
inline
size_t SizeOfArray( const T(&)[ N ] )
{
  return N;
}

int main () {
  size_t value=0;

	int ArrayThing[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  value = SizeOfArray(ArrayThing);
	std::cout << "Size = " << value << " ints\n";

	std::string ArrayTwo[3] = { "What really", "How does this", "work"};
  value = SizeOfArray(ArrayTwo);
	std::cout << "Size = " << value << " strings\n";

}
