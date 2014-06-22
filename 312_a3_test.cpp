// 312 Assignment 3 Test Program.
// TA: Yin Qu (me.yin.qu@gmail.com)
//
// Please re-organize your code into two CPP files:
//   p6.cpp
//   p7.cpp
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
//   $ ./312_a3_test
//
// The program will print test cases that were failed, and print Done before
// exit.

#include <iostream>
#include <fstream>
#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p3.h"
#include "p4.h"
#include "p5.h"
#include "p6.h"
#include "p7.h"
#include "simple_test.h"
#include "test_utils.h"

using namespace std;

test_case(p6, read_write_register) {
  bool r[8], v[8], t[8];

  to_bits8(r, 8);
  to_bits8(v, 47);
  setRegistryValue(r, v);  // $8 = 47
  getRegistryValue(t, r);  // read $8
  assert_eq8(v, t);

  to_bits8(r, 0);
  to_bits8(v, 1);
  setRegistryValue(r, v);  // $0 = 1
  getRegistryValue(t, r);  // read $0
  assert_false(t[0]);      // $0 should always be 0
}

test_case(p6, increment_pc) {
  to_bits8(PC, 100);
  incrementPC();
  assert_eq(104, to_uint8(PC));
}

test_case(p6, add_pc) {
  to_bits8(PC, 104);
  addPC(16);
  assert_eq(120, to_uint8(PC));
}

test_case(p6, instruction_fetch) {
  to_bits8(instructionMemory[100], 16); // ADDU
  to_bits8(instructionMemory[101], 4);  // $4
  to_bits8(instructionMemory[102], 8);  // $8
  to_bits8(instructionMemory[103], 9);  // $9
  to_bits8(PC, 100);

  instructionFetch();

  // assuming that the byte layout is: op-code followed by destination register
  // followed by source register 1 followed by source register 2.
  assert_eq(16, to_uint8(IR));
  assert_eq(4, to_uint8(IR + 8));
  assert_eq(8, to_uint8(IR + 16));
  assert_eq(9, to_uint8(IR + 24));
}

test_case(p6, load_program) {
  ifstream ifs_test_program("test_program.s");
  initializeInstructionMemory(ifs_test_program);

  // ADDU 4, 8, 9
  assert_eq(16, to_uint8(instructionMemory[0]));
  assert_eq(4, to_uint8(instructionMemory[1]));
  assert_eq(8, to_uint8(instructionMemory[2]));
  assert_eq(9, to_uint8(instructionMemory[3]));

  // SW 4, 10
  // assuming that for the 16bit immediate operand, the lower byte is stored
  // before the higher byte.
  assert_eq(15, to_uint8(instructionMemory[4]));
  assert_eq(4, to_uint8(instructionMemory[5]));
  assert_eq(10, to_uint16(instructionMemory[6]));
}

test_case(p6, get_instruction_name) {
  bool op_code[8];
  getInstructionValue(op_code, "SUBU");
  assert_eq(17, to_uint8(op_code));
  getInstructionValue(op_code, "LW");
  assert_eq(14, to_uint8(op_code));
}

test_case(p6, parse_instruction) {
  bool op_code[8], rd[8], rs1[8], rs2[8], imm[16];

  // ADDU 4, 8, 9  ==>  16, 4, 8, 9
  to_bits8(IR, 16);
  to_bits8(IR + 8, 4);
  to_bits8(IR + 16, 8);
  to_bits8(IR + 24, 9);
  parseInstructionInIR(op_code, rd, rs1, rs2, imm);
  assert_eq(16, to_uint8(op_code));
  assert_eq(4, to_uint8(rd));
  assert_eq(8, to_uint8(rs1));
  assert_eq(9, to_uint8(rs2));

  // SW 4, 10  ==>  15, 4, 0, 10 
  to_bits8(IR, 15);
  to_bits8(IR + 8, 4);
  to_bits16(IR + 16, 10);
  parseInstructionInIR(op_code, rd, rs1, rs2, imm);
  assert_eq(15, to_uint8(op_code));
  assert_eq(4, to_uint8(rd));
  assert_eq(10, to_int16(imm));
}

test_case(p6, read_write_data_memory) {
  bool r1[8], r2[8], mem_addr[8];

  to_bits8(r1, 3);
  to_bits8(registry[3], 19);      // $3 = 19
  to_bits8(mem_addr, 8);
  mem(r1, mem_addr, false, true); // save $3 (= 19) to mem[8]

  to_bits8(r2, 4);
  mem(r2, mem_addr, true, false); // load mem[8] to $4
  assert_eq(19, to_uint8(r2));    // check if $4 == 19
}

test_case(p7, run_program) {
  // LI 4, 11
  to_bits8(instructionMemory[0], 12);
  to_bits8(instructionMemory[1], 4);
  to_bits16(instructionMemory[2], 11);
  // LI 5, 13
  to_bits8(instructionMemory[4], 12);
  to_bits8(instructionMemory[5], 5);
  to_bits16(instructionMemory[6], 13);
  // ADDU 6, 4, 5
  to_bits8(instructionMemory[8], 16);
  to_bits8(instructionMemory[9], 6);
  to_bits8(instructionMemory[10], 4);
  to_bits8(instructionMemory[11], 5);
  // SW 6, 10
  to_bits8(instructionMemory[12], 15);
  to_bits8(instructionMemory[13], 6);
  to_bits16(instructionMemory[14], 10);
  
  to_bits8(PC, 0);
  tick();
  assert_eq(11, to_int8(registry[4]));
  tick();
  assert_eq(13, to_int8(registry[5]));
  tick();
  assert_eq(24, to_int8(registry[6]));
  tick();
  assert_eq(24, to_int8(dataMemory[10]));
}

int main(int argc, char** argv) {
  TestCaseRegisterer::run_test_cases();
  cout << "Done." << endl;
  return 0;
}

