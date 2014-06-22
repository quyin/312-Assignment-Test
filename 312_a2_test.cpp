// 312 Assignment 2 Test Program.
// TA: Yin Qu (me.yin.qu@gmail.com)
//
// Please re-organize your code into three CPP files:
//   p3.cpp
//   p4.cpp
//   p5.cpp
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
//   $ ./312_a2_test
//
// The program will print test cases that were failed, and print Done before
// exit.

#include <iostream>
#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "simple_test.h"
#include "test_utils.h"

extern int functionCount;

test_case(p3, alu_addu) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 16);
  to_bits8(a, 47);
  to_bits8(b, 127);
  to_bits8(c, 174); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);

  to_bits8(a, 192);
  to_bits8(b, 127);
  to_bits8(c, 63); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);
}

test_case(p3, alu_subu) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 17);
  to_bits8(a, 127);
  to_bits8(b, 47);
  to_bits8(c, 80); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);

  to_bits8(a, 47);
  to_bits8(b, 127);
  to_bits8(c, 176); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);
}

test_case(p3, alu_neg) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 2);
  str_to_bits8(a, "01010111");
  str_to_bits8(c, "10101001"); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);
}

test_case(p3, alu_eq) {
  bool op[8], a[8], b[8];
  bool output[8];

  to_bits8(op, 3);
  to_bits8(a, 19);
  to_bits8(b, 19);
  alu(op, output, a, b);
  assert_true(output[0]); // test only the least bit

  to_bits8(a, 19);
  to_bits8(b, 83);
  alu(op, output, a, b);
  assert_false(output[0]);
}

test_case(p3, alu_lt) {
  bool op[8], a[8], b[8];
  bool output[8];

  to_bits8(op, 4);
  to_bits8(a, 127);
  to_bits8(b, 128);
  alu(op, output, a, b);
  assert_true(output[0]);

  to_bits8(a, 128);
  to_bits8(b, 127);
  alu(op, output, a, b);
  assert_false(output[0]);
}

test_case(p3, alu_gt) {
  bool op[8], a[8], b[8];
  bool output[8];

  to_bits8(op, 5);
  to_bits8(a, 128);
  to_bits8(b, 127);
  alu(op, output, a, b);
  assert_true(output[0]);

  to_bits8(a, 127);
  to_bits8(b, 128);
  alu(op, output, a, b);
  assert_false(output[0]);
}

test_case(p3, alu_and) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 6);
  str_to_bits8(a, "11010010");
  str_to_bits8(b, "00010011");
  str_to_bits8(c, "00010010"); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);
}

test_case(p3, alu_or) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 7);
  str_to_bits8(a, "11010010");
  str_to_bits8(b, "00010011");
  str_to_bits8(c, "11010011"); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);
}

test_case(p3, alu_sll) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 8);
  str_to_bits8(a, "00010011");
  str_to_bits8(b, "00000010");
  str_to_bits8(c, "01001100"); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);
}

test_case(p3, alu_srl) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 9);
  str_to_bits8(a, "00110011");
  str_to_bits8(b, "00000010");
  str_to_bits8(c, "00001100"); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);
}

test_case(p4, alu_add) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 0);
  to_bits8(a, 67);
  to_bits8(b, 47);
  to_bits8(c, 114); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);

  to_bits8(a, 67);
  to_bits8(b, 67);
  assert_exception(alu(op, output, a, b));
}

test_case(p4, alu_sub) {
  bool op[8], a[8], b[8], c[8];
  bool output[8];

  to_bits8(op, 1);
  to_bits8(a, 120);
  to_bits8(b, 113);
  to_bits8(c, 7); // expected
  alu(op, output, a, b);
  assert_eq8(c, output);

  to_bits8(a, 120);
  to_bits8(b, -113);
  assert_exception(alu(op, output, a, b));
}

test_case(p5, alu_multu) {
  bool op[8], a[8], b[8], c[16];
  bool output[16];

  to_bits8(op, 10);
  to_bits8(a, 47);
  to_bits8(b, 113);
  to_bits16(c, 5311); // expected
  alu(op, output, a, b);
  assert_eq16(c, output);
}

test_case(p5, alu_mult) {
  bool op[8], a[8], b[8], c[16];
  bool output[16];

  to_bits8(op, 11);
  to_bits8(a, 47);
  to_bits8(b, 113);
  to_bits16(c, 5311); // expected
  alu(op, output, a, b);
  assert_eq16(c, output);

  to_bits8(a, -47);
  to_bits8(b, 113);
  to_bits16(c, -5311); // expected
  alu(op, output, a, b);
  assert_eq16(c, output);

  to_bits8(a, -47);
  to_bits8(b, -113);
  to_bits16(c, 5311); // expected
  alu(op, output, a, b);
  assert_eq16(c, output);
}

test_case(p5, alu_divu) {
  bool op[8], a[8], b[8], c[16];
  bool output[16];

  to_bits8(op, 12);
  to_bits8(a, 113);
  to_bits8(b, 47);
  to_bits16(c, (19 << 8) + 2); // quotient = 2, remainder = 19
  alu(op, output, a, b);
  assert_eq16(c, output);
}

test_case(p5, alu_div) {
  bool op[8], a[8], b[8], c[16];
  bool output[16];

  to_bits8(op, 13);
  to_bits8(a, -113);
  to_bits8(b, 47);
  to_bits16(c, ((-19) << 8) + (-2)); // quotient = -2, remainder = -19
  alu(op, output, a, b);
  assert_eq16(c, output);
}

int main(int argc, char** argv) {
  TestCaseRegisterer::run_test_cases();
  std::cout << "Done." << std::endl;
  return 0;
}

