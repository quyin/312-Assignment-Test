// 312 Assignment 1 Test Program.
// TA: Yin Qu (me.yin.qu@gmail.com)
//
// Please re-organize your code into three CPP files:
//   basic_functions.cpp
//   p1.cpp
//   p2.cpp
//
// For each CPP file, see the corresponding header file for function bodies you
// need to include.
//
// This program tests all required functions with test cases.
//
// To compile it, under commandline, type in:
//   $ make
// Or integrate the files into your IDE, if you use any.
//
// To run it, under commandline, type in:
//   $ ./312_a1_test
//
// The program will print test cases that were failed, and print Done before
// exit.

#include <iostream>
#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "simple_test.h"
#include "test_utils.h"

extern int functionCount;

#define T true
#define F false

test_case(basic_functions, And) {
  assert_eq(F, And(F, F));
  assert_eq(F, And(T, F));
  assert_eq(F, And(F, T));
  assert_eq(T, And(T, T));
}

test_case(basic_functions, Or) {
  assert_eq(F, Or(F, F));
  assert_eq(T, Or(T, F));
  assert_eq(T, Or(F, T));
  assert_eq(T, Or(T, T));
}

test_case(basic_functions, Not) {
  assert_eq(F, Not(T));
  assert_eq(T, Not(F));
}

test_case(p1, XOR) {
  assert_eq(F, XOR(F, F));
  assert_eq(T, XOR(T, F));
  assert_eq(T, XOR(F, T));
  assert_eq(F, XOR(T, T));
}

test_case(p1, Mux) {
  assert_eq(F, Mux(T, F, F));
  assert_eq(T, Mux(T, T, F));
  assert_eq(F, Mux(T, F, T));
  assert_eq(T, Mux(T, T, T));
  assert_eq(F, Mux(F, F, F));
  assert_eq(F, Mux(F, T, F));
  assert_eq(T, Mux(F, F, T));
  assert_eq(T, Mux(F, T, T));
}

test_case(p1, Sum2) {
  assert_eq(F, Sum(F, F));
  assert_eq(T, Sum(T, F));
  assert_eq(T, Sum(F, T));
  assert_eq(F, Sum(T, T));
}

test_case(p1, Sum3) {
  assert_eq(F, Sum(F, F, F));
  assert_eq(T, Sum(T, F, F));
  assert_eq(T, Sum(F, T, F));
  assert_eq(F, Sum(T, T, F));
  assert_eq(T, Sum(F, F, T));
  assert_eq(F, Sum(T, F, T));
  assert_eq(F, Sum(F, T, T));
  assert_eq(T, Sum(T, T, T));
}

test_case(p1, CarryOut) {
  assert_eq(F, CarryOut(F, F, F));
  assert_eq(F, CarryOut(T, F, F));
  assert_eq(F, CarryOut(F, T, F));
  assert_eq(T, CarryOut(T, T, F));
  assert_eq(F, CarryOut(F, F, T));
  assert_eq(T, CarryOut(T, F, T));
  assert_eq(T, CarryOut(F, T, T));
  assert_eq(T, CarryOut(T, T, T));
}

test_case(p1, Equal) {
  assert_eq(T, Equal(F, F));
  assert_eq(F, Equal(T, F));
  assert_eq(F, Equal(F, T));
  assert_eq(T, Equal(T, T));
}

test_case(p2, getValue) {
  bool a[8];
  str_to_bits8(a, "10101010");
  assert_eq(F, getValue(a, 0));
  assert_eq(T, getValue(a, 1));
}

test_case(p2, writeValue) {
  bool a[8], b[8], c[8];

  str_to_bits8(a, "00000000");
  str_to_bits8(b, "00010000");
  str_to_bits8(c, "00000000");
  writeValue(c, 4, T);
  assert_eq8(b, c);
  writeValue(c, 4, F);
  assert_eq8(a, c);
}

test_case(p2, mux) {
  bool a[8], b[8], c[8];

  str_to_bits8(a, "00000000");
  str_to_bits8(b, "11111111");
  mux(c, T, a, b);
  assert_eq8(a, c);
  mux(c, F, a, b);
  assert_eq8(b, c);
}

test_case(p2, addu) {
  bool a[8], b[8], c[8];
  bool output[8];

  to_bits8(a, 11);
  to_bits8(b, 7);
  to_bits8(c, 18);
  addu(output, a, b);
  assert_eq8(c, output);
}

test_case(p2, negate) {
  bool a[8], c[8];
  bool output[8];

  str_to_bits8(a, "00001011");
  str_to_bits8(c, "11110101");
  negate(output, a);
  assert_eq8(c, output);

  str_to_bits8(a, "11111001");
  str_to_bits8(c, "00000111");
  negate(output, a);
  assert_eq8(c, output);
}

test_case(p2, subu) {
  bool a[8], b[8], c[8];
  bool output[8];

  to_bits8(a, 11);
  to_bits8(b, 7);
  to_bits8(c, 4);
  subu(output, a, b);
  assert_eq8(c, output);
}

test_case(p2, equal) {
  bool a[8], b[8];

  to_bits8(a, 11);
  to_bits8(b, 7);
  assert_true(equal(a, a));
  assert_true(equal(b, b));
  assert_false(equal(a, b));
  assert_false(equal(b, a));
}

test_case(p2, lessthan) {
  bool a[8], b[8];

  to_bits8(a, 11);
  to_bits8(b, 24);
  assert_true(lessthan(a, b));
  assert_false(lessthan(b, a));
  assert_false(lessthan(a, a));
}

test_case(p2, greaterthan) {
  bool a[8], b[8];

  to_bits8(a, 11);
  to_bits8(b, 24);
  assert_false(greaterthan(a, b));
  assert_true(greaterthan(b, a));
  assert_false(greaterthan(a, a));
}

test_case(p2, and8) {
  bool a[8], b[8], c[8];
  bool output[8];

  str_to_bits8(a, "00001011");
  str_to_bits8(b, "00011000");
  str_to_bits8(c, "00001000");
  and8(output, a, b);
  assert_eq8(c, output);
}

test_case(p2, or8) {
  bool a[8], b[8], c[8];
  bool output[8];

  str_to_bits8(a, "00001011");
  str_to_bits8(b, "00011000");
  str_to_bits8(c, "00011011");
  or8(output, a, b);
  assert_eq8(c, output);
}

test_case(p2, shiftLeft) {
  bool a[8], c[8];
  bool output[8];

  str_to_bits8(a, "00001011");
  str_to_bits8(c, "00010110");
  shiftLeft(output, a);
  assert_eq8(c, output);
}

test_case(p2, shiftRight) {
  bool a[8], c[8];
  bool output[8];

  str_to_bits8(a, "00001011");
  str_to_bits8(c, "00000101");
  shiftRight(output, a);
  assert_eq8(c, output);
}

int main(int argc, char** argv) {
  TestCaseRegisterer::run_test_cases();
  std::cout << "Done." << std::endl;
  return 0;
}

