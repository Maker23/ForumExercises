#ifndef  FORTUNE_H_
#define  FORTUNE_H_

#include <cstdlib>
#include <iostream>
#include <iterator> 
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#define FILE "fortunes.txt"

#define DEBUG false


#endif // FORTUNE_H_

using namespace std;

int main() {
  string line;
  string OneFortune = "";
  int NumFortunes = 0;
  int RandomFortune = 0;
  ifstream inFile (FILE);
  //bool DEBUG = True;
  
  vector <string> allFortunes;

  if (inFile.is_open()) {
    while (getline (inFile, line)) {
      if (line.empty()) {
        /* A blank line in the file is the fortune separator */
        allFortunes.push_back(OneFortune);
        NumFortunes++;
        OneFortune = "";
      }
      else {
        /* Concatenate lines from the file to create a single fortune */
        OneFortune = OneFortune + line + " "; 
      }
    }
    if ( OneFortune != "" ) {
      /* The file probably doesn't end with a blank line; this will
         capture the last fortune */
      allFortunes.push_back(OneFortune);
      NumFortunes++;
    }
    inFile.close();
  }
  else {
    cout << "Count not open file " << FILE << "\n";
  }

  srand(time(NULL));
  RandomFortune =  rand() % NumFortunes;

  if ( DEBUG ) {
    cout << "DEBUG: rand_max = " << RAND_MAX << "\n";
    cout << "DEBUG: RandomFortune = " << RandomFortune << "\n";
    cout << "DEBUG: Number of fortunes found = " << NumFortunes << "\n\n";
  }
  
  /*  Print out one random fortune */
  cout << allFortunes[RandomFortune] << "\n";
  /*  Print out all the fortunes */
  // copy(allFortunes.begin(), allFortunes.end(), ostream_iterator<string>(cout, "\n"));

/*

  STRETCH GOAL:
  Read quotes from web pages instead of a file

*/
  
  return 0;
}


/*  
  Found on the web, haven't tried this yet:
  const char delimeter = '|'; 

  while(getline(inFile, input, delimeter)) 
*/
