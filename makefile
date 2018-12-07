# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary.

final: main.o hash.o
	g++ -o plagiarismCatcher main.o hash.o

main.o: main.cpp hash.cpp hash.h
		g++ -c main.cpp

hash.o: hash.cpp hash.h
		g++ -c hash.cpp