CC=g++
CFLAGS=-I.

all: calculator run-python

calculator: main.o Calculator.o
	$(CC) -o calculator main.o Calculator.o

main.o: src/main.cpp
	$(CC) -c src/main.cpp

Calculator.o: src/Calculator.cpp
	$(CC) -c src/Calculator.cpp

run-python:
	python3 src/main.py

clean:
	rm -f *.o calculator

