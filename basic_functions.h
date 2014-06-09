// Basic gates and helper functions that you will use in your program.

#ifndef BASIC_FUNCTIONS_H
#define BASIC_FUNCTIONS_H

// The counter of basic gates.
// In your basic_functions.cpp, you should define the functionCount like this:
//   int functionCount;
extern int functionCount;

bool And(bool a, bool b);
bool Or(bool a, bool b);
bool Not(bool a);

void printFunctionCount();
void print(bool a);
void resetFunctionCount();

bool getValue(bool byte[8], int offset);
void writeValue(bool* byte, int offset, bool value);
void printValue(bool byte[8]);
void printValueInDecimal(bool byte[8]);
  
#endif // BASIC_FUNCTIONS_H

