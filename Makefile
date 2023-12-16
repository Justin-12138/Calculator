CC=g++
CFLAGS=-I.
OBJDIR=bin

ifeq ($(OS),Windows_NT)
    PYTHON=python
    SCRIPT=src/main.py
else
    PYTHON=python3
    SCRIPT=src/linux_main.py
endif

_OBJS = main.o Calculator.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

all: directories calculator run-python

directories: $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

calculator: $(OBJS)
	$(CC) -o calculator $(OBJS)

$(OBJDIR)/main.o: src/main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/Calculator.o: src/Calculator.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

run-python:
	$(PYTHON) $(SCRIPT)

clean:
	rm -f $(OBJDIR)/*.o calculator
