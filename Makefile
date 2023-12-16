CC=g++
CFLAGS=-I.

ifeq ($(OS),Windows_NT)
    PYTHON=python
    SCRIPT=src/main.py
else
    PYTHON=python3
    SCRIPT=/src/linux_main.py
endif

all: calculator run-python

calculator: main.o Calculator.o
	$(CC) -o calculator main.o Calculator.o

main.o: src/main.cpp
	$(CC) -c src/main.cpp

Calculator.o: src/Calculator.cpp
	$(CC) -c src/Calculator.cpp

run-python:
	$(PYTHON) $(SCRIPT)

clean:
	rm -f *.o calculator
