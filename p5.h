// Functions required by Problem 5.
//
// In your p5.cpp, you should include basic_functions.h, p1.h, and so on, if you
// want to use previously built functions.
//
// Note that you can only use functions you have built so far.

#ifndef P5_H
#define P5_H

// Unsigned and signed versions of multiplier and divider.
// Note that you should integrate them into the ALU you built in p3.

bool* multu(bool* output, bool input1[8], bool input2[8]);
bool* mult(bool* output, bool input1[8], bool input2[8]);

bool* divu(bool* output, bool input1[8], bool input2[8]);
bool* div(bool* output, bool input1[8], bool input2[8]);

#endif // P5_H

