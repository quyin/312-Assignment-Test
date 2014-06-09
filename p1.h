// Functions required by Problem 1.
//
// In your p1.cpp, you should include basic_functions.h to use the basic gates
// defined there.
//
// Note that all implementations MUST NOT use C++ provided logical and
// arithmetic operators, control structures, and so on.
//
// ONLY THE BASIC GATES AND WHAT YOU CONSTRUCTED FROM BASIC GATES CAN BE USED.

#ifndef P1_H
#define P1_H

bool XOR(bool a, bool b);

bool Mux(bool operation, bool output_if_true, bool output_if_false);

bool Sum(bool a, bool b);

bool Sum(bool a, bool b, bool c);

bool CarryOut(bool a, bool b, bool c);

bool Equal(bool a, bool b);

#endif // P1_H

