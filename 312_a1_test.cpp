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
  bool byte[8] = { T, F, T, F, T, F, T, F };
  assert_eq(T, getValue(byte, 0));
  assert_eq(F, getValue(byte, 1));
}

test_case(p2, writeValue) {
  bool a[8] = { F, F, F, F, F, F, F, F };
  bool b[8] = { F, F, F, F, T, F, F, F };
  bool byte[8] = { F, F, F, F, F, F, F, F };
  writeValue(byte, 4, T);
  assert_eq8(b, byte);
  writeValue(byte, 4, F);
  assert_eq8(a, byte);
}

test_case(p2, mux) {
  bool a[8] = { F, F, F, F, F, F, F, F };
  bool b[8] = { T, T, T, T, T, T, T, T };
  bool output[8];
  mux(output, T, a, b);
  assert_eq8(a, output);
  mux(output, F, a, b);
  assert_eq8(b, output);
}

test_case(p2, addu) {
  bool a[8] = { T, T, F, T, F, F, F, F };
  bool b[8] = { T, F, F, T, T, T, T, T };
  bool s[8] = { F, F, T, F, F, F, F, F };

  bool output[8];
  addu(output, a, b);
  assert_eq8(s, output);
}

test_case(p2, negate) {
  bool a1[8] = { T, T, F, T, F, F, F, F };
  bool b1[8] = { T, F, T, F, T, T, T, T };
  bool output1[8]; 
  negate(output1, a1);
  assert_eq8(b1, output1);

  bool a2[8] = { T, F, F, T, T, T, T, T };
  bool b2[8] = { T, T, T, F, F, F, F, F };
  bool output2[8]; 
  negate(output2, a2);
  assert_eq8(b2, output2);
}

test_case(p2, subu) {
  bool a[8] = { T, T, F, T, F, F, F, F }; // 11
  bool b[8] = { T, F, F, T, T, T, T, T }; // -7
  bool d[8] = { F, T, F, F, T, F, F, F }; // 18

  bool output[8];
  subu(output, a, b);
  assert_eq8(d, output);
}

test_case(p2, equal) {
  bool a[8] = { T, T, F, T, F, F, F, F }; // 11
  bool b[8] = { T, F, F, T, T, T, T, T }; // -7

  assert_true(equal(a, a));
  assert_true(equal(b, b));
  assert_false(equal(a, b));
  assert_false(equal(b, a));
}

test_case(p2, lessthan) {
  bool a[8] = { T, T, F, T, F, F, F, F }; // 11
  bool b[8] = { F, F, F, T, T, F, F, F }; // 24

  assert_true(lessthan(a, b));
  assert_false(lessthan(b, a));
  assert_false(lessthan(a, a));
}

test_case(p2, greaterthan) {
  bool a[8] = { T, T, F, T, F, F, F, F }; // 11
  bool b[8] = { F, F, F, T, T, F, F, F }; // 24

  assert_false(greaterthan(a, b));
  assert_true(greaterthan(b, a));
  assert_false(greaterthan(a, a));
}

test_case(p2, and8) {
  bool a[8] = { T, T, F, T, F, F, F, F };
  bool b[8] = { F, F, F, T, T, F, F, F };
  bool result[8] = { F, F, F, T, F, F, F, F };

  bool output[8];
  and8(output, a, b);
  assert_eq8(result, output);
}

test_case(p2, or8) {
  bool a[8] = { T, T, F, T, F, F, F, F };
  bool b[8] = { F, F, F, T, T, F, F, F };
  bool result[8] = { T, T, F, T, T, F, F, F };

  bool output[8];
  or8(output, a, b);
  assert_eq8(result, output);
}

test_case(p2, shiftLeft) {
  bool a[8] = { T, T, F, T, F, F, F, F };
  bool b[8] = { F, T, T, F, T, F, F, F };

  bool output[8];
  shiftLeft(output, a);
  assert_eq8(b, output);
}

test_case(p2, shiftRight) {
  bool a[8] = { T, T, F, T, F, F, F, F };
  bool b[8] = { T, F, T, F, F, F, F, F };

  bool output[8];
  shiftRight(output, a);
  assert_eq8(b, output);
}

int main(int argc, char** argv) {
  run_test_case(basic_functions, And);
  run_test_case(basic_functions, Or);
  run_test_case(basic_functions, Not);
  run_test_case(p1, XOR);
  run_test_case(p1, Mux);
  run_test_case(p1, Sum2);
  run_test_case(p1, Sum3);
  run_test_case(p1, CarryOut);
  run_test_case(p1, Equal);
  run_test_case(p2, getValue);
  run_test_case(p2, writeValue);
  run_test_case(p2, mux);
  run_test_case(p2, addu);
  run_test_case(p2, negate);
  run_test_case(p2, subu);
  run_test_case(p2, equal);
  run_test_case(p2, lessthan);
  run_test_case(p2, greaterthan);
  run_test_case(p2, and8);
  run_test_case(p2, or8);
  run_test_case(p2, shiftLeft);
  run_test_case(p2, shiftRight);

  std::cout << "Done." << std::endl;
  return 0;
}

