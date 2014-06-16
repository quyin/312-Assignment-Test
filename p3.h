// Functions required by Problem 3.
//
// In your p3.cpp, you should include basic_functions.h, p1.h, and so on, if you
// want to use previously built functions.
//
// Note that you can only use functions you have built so far.

#ifndef P3_H
#define P3_H

// An ALU. An pointer to output should be returned as the return value.
bool* alu(bool op_code[8], bool* output, bool input1[8], bool input2[8]);

#endif // P3_H

