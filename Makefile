CC=g++
CFLAGS=-I.

all: calculator

calculator: main.o Calculator.o
	$(CC) -o calculator main.o Calculator.o

main.o: src/main.cpp
	$(CC) -c src/main.cpp

Calculator.o: src/Calculator.cpp
	$(CC) -c src/Calculator.cpp

clean:
	rm -f *.o calculator
