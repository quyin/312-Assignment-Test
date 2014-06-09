# Makefile to build test programs for 312 assignments.

CC=g++
CFLAGS=-g

all: a1

basic_functions.o: basic_functions.h basic_functions.cpp
	$(CC) $(CFLAGS) -c basic_functions.cpp

a1: simple_test.h basic_functions.o p1.h p1.cpp p2.h p2.cpp
	$(CC) $(CFLAGS) -o a1_test basic_functions.o p1.cpp p2.cpp 312_a1_test.cpp

