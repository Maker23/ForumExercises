default: current
all: current 01 fortune

current: hello_world.cc
	g++ -Wall -ansi hello_world.cc -o HelloWorld

01: C_hello_world.c
	gcc -Wall -ansi C_hello_world.c -o 01_HelloWorld

fortune: fortune.cc
	g++ -Wall -ansi fortune.cc -o Fortune

Fortune: fortune
  
SortDiv: sort_by_dividing.cc
	g++ -Wall -ansi sort_by_dividing.cc -o SortDiv

clean: 
	rm -f HelloWorld 01_HelloWorld Fortune
