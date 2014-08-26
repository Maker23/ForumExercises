default: all
all: GradingProgram ColaMachine UserPatience PancakeBreakfast Sizeof Guess

CC = g++
CCFLAGS = -Wall -ansi 

UserPatience: user_patience.cc
	$(CC) $(CCFLAGS) user_patience.cc -o UserPatience

GradingProgram: grading_program.cc
	$(CC) $(CCFLAGS) grading_program.cc -o GradingProgram

ColaMachine: cola_machine.cc
	$(CC) $(CCFLAGS) cola_machine.cc -o ColaMachine

PancakeBreakfast: pancake_breakfast.cc
	$(CC) $(CCFLAGS) pancake_breakfast.cc -o PancakeBreakfast

Sizeof: sizeof_test.cc
	$(CC) $(CCFLAGS) sizeof_test.cc -o Sizeof

Guess: guess_a_number.cc
	$(CC) $(CCFLAGS) guess_a_number.cc -o Guess

Test: test.cc
	$(CC) $(CCFLAGS) test.cc -o Test

clean: 
	rm -f GradingProgram ColaMachine UserPatience PancakeBreakfast Sizeof Guess Test
