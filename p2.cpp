// A cheating version of p2 answers, for testing.

#include "p2.h"
#include "test_utils.h"

bool* assign8(bool* output, bool input[8]) {
  for (int i = 0; i < 8; ++i) {
    output[i] = input[i];
  }
  return output;
}

bool* mux(bool* output, bool operation, bool input1[8], bool input2[8]) {
  if (operation) {
    return assign8(output, input1);
  } else {
    return assign8(output, input2);
  }
}

bool* addu(bool* output, bool input1[8], bool input2[8]) {
  int a = to_int8(input1);
  int b = to_int8(input2);
  int c = a + b;
  to_bits8(output, c);
  return output;
}

bool* negate(bool* output, bool input[8]) {
  int a = to_int8(input);
  int c = -a;
  to_bits8(output, c);
  return output;
}

bool* subu(bool* output, bool input1[8], bool input2[8]) {
  int a = to_int8(input1);
  int b = to_int8(input2);
  int c = a - b;
  to_bits8(output, c);
  return output;
}

bool equal(bool input1[8], bool input2[8]) {
  int a = to_int8(input1);
  int b = to_int8(input2);
  return a == b;
}

bool lessthan(bool input1[8], bool input2[8]) {
  int a = to_int8(input1);
  int b = to_int8(input2);
  return a < b;
}

bool greaterthan(bool input1[8], bool input2[8]) {
  int a = to_int8(input1);
  int b = to_int8(input2);
  return a > b;
}

bool* equal(bool* output, bool input1[8], bool input2[8]) {
  return 0;
}

bool* lessthan(bool* output, bool input1[8], bool input2[8]) {
  return 0;
}

bool* greaterthan(bool* output, bool input1[8], bool input2[8]) {
  return 0;
}

bool* and8(bool* output, bool input1[8], bool input2[8]) {
  for (int i = 0; i < 8; ++i) {
    output[i] = input1[i] && input2[i];
  }
  return output;
}

bool* or8(bool* output, bool input1[8], bool input2[8]) {
  for (int i = 0; i < 8; ++i) {
    output[i] = input1[i] || input2[i];
  }
  return output;
}

bool* shiftLeft(bool* output, bool input[8]) {
  for (int i = 7; i >=1; --i) {
    output[i] = input[i-1];
  }
  output[0] = 0;
  return output;
}

bool* shiftRight(bool* output, bool input[8]) {
  for (int i = 0; i < 7; ++i) {
    output[i] = input[i+1];
  }
  output[7] = output[6];
  return output;
}

