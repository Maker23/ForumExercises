/*
	Write a program that creates a linked list of bunny objects.

	Each bunny object must have
		Sex: Male, Female (random at creation 50/50)
		color: white, brown, black, spotted
		age : 0-10 (years old)
		Name : randomly chosen at creation from a list of bunny names.
		radioactive_mutant_vampire_bunny: true/false (decided at time of bunny creation 2% chance of true)

	[x] At program initialization 5 bunnies must be created and given random colors.
	[x] Each turn afterwards the bunnies age 1 year.
	[m] So long as there is at least one male age 2 or older, for each female bunny 
			in the list age 2 or older; a new bunny is created each turn. (i.e. if there 
			was 1 adult male and 3 adult female bunnies, three new bunnies would be born each turn)
	[ ] New bunnies born should be the same color as their mother.
	[ ] If a bunny becomes older than 10 years old, it dies.
	[x] If a radioactive mutant vampire bunny is born then each turn it will change 
			exactly one non radioactive bunny into a radioactive vampire bunny.
			(if there are two radioactive mutant vampire bunnies two bunnies will be changed each turn and so on...)
	[x] Radioactive vampire bunnies are excluded from regular breeding and do not count as adult bunnies.
	[ ] Radioactive vampire bunnies do not die until they reach age 50.
	[m] The program should print a list of all the bunnies in the colony each turn along w/ all the bunnies details, sorted by age.
	[x] The program should also output each turns events such as
			"Bunny Thumper was born!
			Bunny Fufu was born!
			Radioactive Mutant Vampire Bunny Darth Maul was born!
			Bunny Julius Caesar died!
	[ ] The program should write all screen output to a file.

	When all the bunnies have died the program terminates.
	If the bunny population exceeds 1000 a food shortage must occur killing exactly half of the bunnies (randomly chosen)

	= Modify the program to run in real time, with each turn lasting 2 seconds, and a one second pause between each announement.

	== Allow the user to hit the 'k' key to initiate a mass rabbit cull! which causes half of all the rabbits to be killed (randomly chosen).

	=== Modify the program to place the rabits in an 80x80 grid. Have the rabits move one space each turn randomly.
		Mark juvenile males with m, adult males w/ M,
		juvenile females w/ f, adult femails w/ F
		radioactive mutant vampire bunnies with X

	==== Modify the program so that radioactive mutant vampire bunnies only convert bunnies that end a turn on an adjacent square.
	  Modify the program so that new babies are born in an empty random adjacent square next to the mother bunny. (if no empty square 
	  exists then the baby bunny isn't born)

	======  Modify the program so that it saves each turn to a file and can play back at accelearted speed all subsequent turns.
*/
#include <cstdlib>
#include <cstddef>
#include <sstream>
#include <iostream>
#include <string>
#include <new>
#include <iomanip>

#define DEBUG true
#include "name.cc"

#define StartWith 15
#define PercentFemale 50
#define PercentRadioactive 6
#define NumGenerations 20
#define Lifespan 10


static std::string Colors[] = {"brown", "white", "black", "spotted"};
static int ColorsLen = 4;
int NumMales;
int NumRadioactives;

class Rabbit 
{
  public:
		bool Female;
		std::string Color;
		int Age;
		std::string Name;
		bool Radioactive;
		Rabbit * Next;  // linked-list pointer

		Rabbit();				// constructor

		void Print();		// print
};

Rabbit::Rabbit(){
	int P = rand()%101;
	int C = rand()%ColorsLen;

	// sex
	// if (DEBUG) {std::cout << "Debugging P is " << P << "\n";}
	if (P < PercentFemale){ Female = true; }
	else { Female = false; }

	// radioactive?
	if ( (abs ( P - PercentFemale)) < (PercentRadioactive/2)) {
		Radioactive = true; 
	}
	else { Radioactive = false; }

	// color
	Color = Colors[C];

	Age = 0;

	// name
	Name = ReturnAName();
	Next = NULL;
}

void Rabbit::Print(){
	std::cout << std::setw(4) << std::left << Female ;
	std::cout << std::setw(8) << std::left << Color ;
	std::cout << std::setw(4) << std::left << Age ;
	std::cout << std::setw(3) << std::left << Radioactive ;
	if (DEBUG) { std::cout << std::setw(12) << std::left << Next;}
	std::cout << std::left << Name << "\n";
}

void PrintHeader(){
	std::cout << std::setw(4) << std::left << "\nF?" ;
	std::cout << std::setw(8) << std::left << "Color" ;
	std::cout << std::setw(4) << std::left << "Age" ;
	std::cout << std::setw(3) << std::left << "R?";
	if (DEBUG) { std::cout << std::setw(12) << std::left << "Next ptr";}
	std::cout << std::left << "Name" << "\n";
}

void PrintAllRabbits(Rabbit * AllRabbits) {
	Rabbit * CurrentPtr = AllRabbits; 

	if ( ! AllRabbits == NULL ) {
  	PrintHeader(); 
	}
	while ( CurrentPtr != NULL) {
		(*CurrentPtr).Print();
		CurrentPtr = (*CurrentPtr).Next;
	}

}

Rabbit * StartOffWithSomeRabbits () {

  Rabbit * HeadPtr = NULL;
  Rabbit * CurrentPtr = NULL;

  for (int i=0; i< StartWith; i++) {
		Rabbit * TmpItem = new Rabbit;
		if ( HeadPtr == NULL ) {
			HeadPtr = TmpItem;
			CurrentPtr = HeadPtr;
		}
		else {
			(*CurrentPtr).Next = TmpItem;
		  CurrentPtr = TmpItem;
		}
		if ((*CurrentPtr).Radioactive) {
			NumRadioactives++;
			std::cout << "First generation radioactive bunny " << (*CurrentPtr).Name << " is born\n";
		}
		else if ( (*CurrentPtr).Female == false ) {
			NumMales++;
			std::cout << "First generation male bunny " << (*CurrentPtr).Name << " is born\n";
		}
		else {
			std::cout << "First generation female bunny " << (*CurrentPtr).Name << " is born\n";
		}
	}

	return (HeadPtr);
}

Rabbit * Generation(int Cycles, Rabbit * AllRabbits) 
{  
	Rabbit * ThisRabbit;
	Rabbit * NextRabbit;
	Rabbit * PrevRabbit;
	Rabbit * TmpRabbit;
	int TmpMales = NumMales;
	int TmpRadioactives = NumRadioactives;

  // All the work happens here
	for (int i = 0; i<Cycles; i++) {
	  if ( DEBUG ) {std::cout << "---- Cycle " << i << "\n";}
  	ThisRabbit = AllRabbits;
		PrevRabbit = NULL;

		while ( ThisRabbit != NULL ) {
	    if ( DEBUG ) {std::cout << "\t" << ThisRabbit << " " ; (*ThisRabbit).Print();}
			NextRabbit = (*ThisRabbit).Next;


			if ((*ThisRabbit).Age >= Lifespan) {
				std::cout << "Bunny " << (*ThisRabbit).Name << " dies at age " << (*ThisRabbit).Age << "\n";
				// remove a rabbit
				if ((*ThisRabbit).Radioactive) {
					TmpRadioactives--;
				}
				if ( (*ThisRabbit).Female == false ) {
					TmpMales--;
				}
				// remove a rabbit
				if ( PrevRabbit == NULL ) {
					if (NextRabbit == NULL ) {
						std::cout << "List is empty. All rabbits are dead\n";
						ThisRabbit = NULL;
						AllRabbits = NULL;
					}
					else
					{
						// This is the first element in the list
						if (DEBUG) {std::cout << "Shuffling dead rabbit " << (*ThisRabbit).Name << " from head of list\n";}
						delete(ThisRabbit);
						ThisRabbit = NextRabbit;
						AllRabbits = NextRabbit;
					}
				}
				else {
					// This element is in the middle of the list
					if (DEBUG) {
						if (NextRabbit == NULL ) {
							std::cout << "Shuffling dead rabbit " << (*ThisRabbit).Name << " with end of list NULL\n";
						}
						else {
							std::cout << "Shuffling dead rabbit " << (*ThisRabbit).Name << " with next rabbit " << (*NextRabbit).Name <<"\n";
						}
					}
					delete(ThisRabbit);
					ThisRabbit = NextRabbit;
					(*PrevRabbit).Next = NextRabbit;
				}
			}
			else {
				if ((*ThisRabbit).Radioactive ) {
					// Do nothing, radioactive rabbits do not breed
				}
				else {
					if (((*ThisRabbit).Female == true) && ((*ThisRabbit).Age >= 2) && (NumMales > 0)){
						// add a rabbit
						TmpRabbit = new Rabbit;
		  			(*TmpRabbit).Next = NextRabbit;
						(*ThisRabbit).Next = TmpRabbit;
		
						if ((*TmpRabbit).Radioactive) {
							TmpRadioactives++;
							std::cout << "Radioactive b";
						}
						else { 
							std::cout << "B";
						}
						std::cout << "unny " << (*TmpRabbit).Name << " is born to mom " << (*ThisRabbit).Name << "\n";
					}
					else if ( (*ThisRabbit).Female == false ) {
						TmpMales++;
					}
					if ( NumRadioactives > 0 ) {
						(*ThisRabbit).Radioactive = true;
						NumRadioactives--;
						std::cout << "Bunny " << (*ThisRabbit).Name << " is now radioactive!!\n";
						TmpRadioactives++;
					}
				}
				(*ThisRabbit).Age +=1;
				PrevRabbit = ThisRabbit;
	 			ThisRabbit = NextRabbit;
			}
		}
		// After a full cycle, re-set these numbers with changes that occurred
		NumRadioactives = TmpRadioactives;
		NumMales = TmpMales;
	}
	return (AllRabbits);
}

int main() 
{

	Rabbit * RabbitListPtr = NULL; // Start with a null pointer
  srand(time(NULL));

	InitializeNames(); // TODO: automate this as part of the library

  /* Start with a certain number of rabbits */
	RabbitListPtr = StartOffWithSomeRabbits();

	/* Now, run forward some generations */
	RabbitListPtr = Generation(NumGenerations, RabbitListPtr);

	/* Print out the rabbit family */
	PrintAllRabbits(RabbitListPtr);
}
