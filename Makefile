default: all
all: GradingProgram

GradingProgram: grading_program.cc
	g++ -Wall -ansi grading_program.cc -o GradingProgram

clean: 
	rm -f GradingProgram
