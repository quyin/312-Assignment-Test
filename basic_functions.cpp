// A set of possible implementations for basic functions.

#include <iostream>
#include "basic_functions.h"

using namespace std;

int functionCount;

bool And(bool a, bool b) {
  functionCount++;
  return a && b;
}

bool Or(bool a, bool b) {
  functionCount++;
  return a || b;
}

bool Not(bool a) {
  functionCount++;
  return !a;
}

void printFunctionCount() {
  cout << functionCount << endl;
}

void print(bool a) {
  cout << a << endl;
}

void resetFunctionCount() {
  functionCount = 0;
}

bool getValue(bool byte[8], int offset) {
  return byte[offset];
}

void writeValue(bool* byte, int offset, bool value) {
  byte[offset] = value;
}

void printValue(bool byte[8]) {
  for (int i = 0; i < 8; ++i) {
    cout << byte[i];
  }
  cout << endl;
}

void printValueInDecimal(bool byte[8]) {
  unsigned char n = 0;
  for (int i = 0; i < 8; ++i) {
    n = n << 1;
    n += byte[i] ? 1 : 0;
  }
  signed char s = static_cast<signed char>(n);
  cout << s << endl;
}

