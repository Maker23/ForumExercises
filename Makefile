default: all
all: GradingProgram ColaMachine

CC = g++
CCFLAGS = -Wall -ansi

GradingProgram: grading_program.cc
	$(CC) $(CFLAGS) grading_program.cc -o GradingProgram

ColaMachine: cola_machine.cc
	$(CC) $(CFLAGS) cola_machine.cc -o ColaMachine

clean: 
	rm -f GradingProgram ColaMachine
