# Makefile to build test programs for 312 assignments.

CC=g++
CFLAGS=-g

OBJS=test_utils.o simple_test.o basic_functions.o

A1_OBJS=p1.o p2.o
A2_OBJS=p1.o p2.o p3.o p4.o p5.o
A3_OBJS=p1.o p2.o p3.o p4.o p5.o p6.o p7.o

all: a1 a2 a3

clean:
	rm -rf *.o *.dSYM a1_test a2_test a3_test

test_utils.o: test_utils.h test_utils.cpp
	$(CC) $(CFLAGS) -c test_utils.cpp

simple_test.o: simple_test.h simple_test.cpp
	$(CC) $(CFLAGS) -c simple_test.cpp

basic_functions.o: basic_functions.h basic_functions.cpp
	$(CC) $(CFLAGS) -c basic_functions.cpp

p1.o: p1.h p1.cpp
	$(CC) $(CFLAGS) -c p1.cpp

p2.o: p2.h p2.cpp
	$(CC) $(CFLAGS) -c p2.cpp

p3.o: p3.h p3.cpp
	$(CC) $(CFLAGS) -c p3.cpp

p4.o: p4.h p4.cpp
	$(CC) $(CFLAGS) -c p4.cpp

p5.o: p5.h p5.cpp
	$(CC) $(CFLAGS) -c p5.cpp

p6.o: p6.h p6.cpp
	$(CC) $(CFLAGS) -c p6.cpp

p7.o: p7.h p7.cpp
	$(CC) $(CFLAGS) -c p7.cpp

a1: simple_test.h $(OBJS) $(A1_OBJS) 312_a1_test.cpp
	$(CC) $(CFLAGS) -o a1_test $(OBJS) $(A1_OBJS) 312_a1_test.cpp

a2: simple_test.h $(OBJS) $(A2_OBJS) 312_a2_test.cpp
	$(CC) $(CFLAGS) -o a2_test $(OBJS) $(A2_OBJS) 312_a2_test.cpp

a3: simple_test.h $(OBJS) $(A3_OBJS) 312_a3_test.cpp
	$(CC) $(CFLAGS) -o a3_test $(OBJS) $(A3_OBJS) 312_a3_test.cpp

