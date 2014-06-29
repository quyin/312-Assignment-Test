// Implementation for P6.

#include <algorithm>
#include <cstdio>
#include "p6.h"
#include "test_utils.h"

using namespace std;

bool registry[16][8];
bool instructionMemory[256][8];
bool dataMemory[16][8];
bool PC[8];
bool IR[32];

void set_to_false(bool mat[][8], int len) {
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < 8; ++j ) {
      mat[i][j] = false;
    }
  }
}

void initialize() {
  set_to_false(registry, 16);
  set_to_false(instructionMemory, 256);
  set_to_false(dataMemory, 16);
  fill_n(PC, 8, false);
  fill_n(IR, 32, false);
}

bool* getRegistryValue(bool* output, bool registerNum[8]) {
  int rn = to_uint8(registerNum);
  if (rn == 0) {
    fill_n(output, 8, false);
  }
  copy(registry[rn], registry[rn]+8, output);
  return output;
}

void setRegistryValue(bool registerNum[8], bool value[8]) {
  int rn = to_uint8(registerNum);
  if (rn != 0) {
    copy(value, value + 8, registry[rn]);
  }
}

// You may use any C++ provided features to implement this function.
int toDecimal(bool registerNum[8]) {
  int rn = to_uint8(registerNum);
  return rn == 0 ? 0 : to_int8(registry[rn]);
}

void incrementPC() {
  int pc = to_uint8(PC);
  to_bits8(PC, pc + 4);
}

void addPC(bool addressOffset[8]) {
  int pc = to_uint8(PC);
  int offset = to_uint8(addressOffset);
  to_bits8(PC, pc + offset);
}

void instructionFetch() {
  int pc = to_uint8(PC);
  copy(instructionMemory[pc], instructionMemory[pc]+8, IR+24);
  copy(instructionMemory[pc+1], instructionMemory[pc+1]+8, IR+16);
  copy(instructionMemory[pc+2], instructionMemory[pc+2]+8, IR+8);
  copy(instructionMemory[pc+3], instructionMemory[pc+3]+8, IR);
}

void parseInstructionInIR(bool* name,
                          bool* reg_out,
                          bool* reg_in1,
                          bool* reg_in2,
                          bool* imm16) {
  copy(IR + 24, IR + 32, name);
  int op = to_uint8(name);
  if (op == 14 || op == 15 || op == 30) {
    // I-format
    copy(IR + 16, IR + 24, reg_out);
	 	copy(IR, IR + 16, imm16);
  } else {
    // R-format
    copy(IR + 16, IR + 24, reg_out);
    copy(IR + 8, IR + 16, reg_in1);
    copy(IR, IR + 8, reg_in2);
  }
}

void initializeInstructionMemory(ifstream& fp) {
  char line[256], name_buf[8];
  string name;
  int rd, rs, rt, imm;

  int pc = 0;
  while (true) {
    fp.getline(line, 256);
    if (fp.eof()) {
      break;
    }
    sscanf(line, "%s", name_buf);
    name = name_buf;
    if (name == "LW" || name == "SW" || name == "LI") {
      sscanf(line + name.size(), "%d,%d", &rd, &imm);
    } else {
      sscanf(line + name.size(), "%d,%d,%d", &rd, &rs, &rt);
    }
    
    if (name == "ADDU") {
      to_bits8(instructionMemory[pc], 16);
      to_bits8(instructionMemory[pc+1], rd);
      to_bits8(instructionMemory[pc+2], rs);
      to_bits8(instructionMemory[pc+3], rt);
    } else if (name == "SW") {
      to_bits8(instructionMemory[pc], 15);
      to_bits8(instructionMemory[pc+1], rd);
      to_bits8(instructionMemory[pc+2], imm >> 8);
      to_bits8(instructionMemory[pc+3], imm & 0xff);
    } // TODO other instructions.

    pc += 4;
  }
}

bool* getInstructionValue(bool* output, const std::string& instructionName) {
  if (instructionName == "ADDU") {
    to_bits8(output, 16);
  } else if (instructionName == "SUBU") {
    to_bits8(output, 17);
  } else if (instructionName == "LW") {
    to_bits8(output, 14);
  } else if (instructionName == "SW") {
    to_bits8(output, 15);
  } else if (instructionName == "LI") {
    to_bits8(output, 30);
  } // TODO other instructions.
  return output;
}

void mem(bool registerNum[8], bool memlocation[16], bool read, bool write) {
  if (read) {
    lw(registerNum, memlocation);
  } else if (write) {
    sw(registerNum, memlocation);
  }
}

void lw(bool registerNum[8], bool memlocation[16]) {
  int rn = to_uint8(registerNum);
  readMem(registry[rn], memlocation);
}

void sw(bool registerNum[8], bool memlocation[16]) {
  int rn = to_uint8(registerNum);
  writeMem(registry[rn], memlocation);
}

void readOrWriteMem(bool value[8], bool memlocation[8], bool read, bool write) {
  if (read) {
    readMem(value, memlocation);
  } else if (write) {
    writeMem(value, memlocation);
  }
}

void readMem(bool value[8], bool memlocation[16]) {
  int addr = to_uint16(memlocation);
  copy(dataMemory[addr], dataMemory[addr] + 8, value);
}

void writeMem(bool value[8], bool memlocation[16]) {
  int addr = to_uint16(memlocation);
  copy(value, value + 8, dataMemory[addr]);
}
