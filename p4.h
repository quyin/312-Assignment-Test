// Functions required by Problem 4.
//
// In your p4.cpp, you should include basic_functions.h, p1.h, and so on, if you
// want to use previously built functions.
//
// Note that you can only use functions you have built so far.

#ifndef P4_H
#define P4_H

// The following two functions operate on signed numbers, and throws an
// exception when overflow happens.
// You should also integrate them into the ALU you built in p3.
bool* add(bool* output, bool input1[8], bool input2[8]);
bool* sub(bool* output, bool input1[8], bool input2[8]);

#endif // P4_H

