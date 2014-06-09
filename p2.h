// Functions required by Problem 2.
//
// In your p2.cpp, you should include basic_functions.h to use the basic gates
// defined there.
//
// You can use what you built in Problem 1, by including p1.h in your p2.cpp.
//
// Note that all implementations MUST NOT use C++ provided logical and
// arithmetic operators, control structures, and so on.
//
// ONLY THE BASIC GATES AND WHAT YOU CONSTRUCTED FROM BASIC GATES CAN BE USED.

#ifndef P2_H
#define P2_H

bool* mux(bool* output, bool operation, bool input1[8], bool input2[8]);
bool* addu(bool* output, bool input1[8], bool input2[8]);
bool* negate(bool* output, bool input[8]);
bool* subu(bool* output, bool input1[8], bool input2[8]);

bool equal(bool input1[8], bool input2[8]);
bool lessthan(bool input1[8], bool input2[8]);
bool greaterthan(bool input1[8], bool input2[8]);
bool* equal(bool* output, bool input1[8], bool input2[8]);
bool* lessthan(bool* output, bool input1[8], bool input2[8]);
bool* greaterthan(bool* output, bool input1[8], bool input2[8]);

bool* and8(bool* output, bool input1[8], bool input2[8]);
bool* or8(bool* output, bool input1[8], bool input2[8]);

bool* shiftLeft(bool* output, bool input[8]);
bool* shiftRight(bool* output, bool input[8]);

#endif // P2_H

