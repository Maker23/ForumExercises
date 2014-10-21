#include <iostream>
#include <cstdlib>
#include <iterator>

int test_this(int test_number, int low_number, int high_number) {
  if ( (test_number == low_number) || (( test_number / low_number ) && ! (test_number / high_number)) ){
    return (1);
  }
  return(0);
}

int main()
{
  int nums[15] = {2, 4, 6, 19, 22, 25, 31, 33, 34, 46, 47, 50, 55, 58, 59};

  for (int i=0; i < 15; ++i) {
    std::cout << nums[i] << ", ";
  }
  std::cout << "\n";
  for (int i=0; i < 15; ++i) {
    int testnum = nums[i];
    int lownum,hinum;

    lownum = 50;
    hinum = 60;
    if ( test_this(testnum, lownum, hinum) ) {
      std::cout << nums[i] << " is between " << lownum << " and " << hinum << "\n";
    }
  }
}
