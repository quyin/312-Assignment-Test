#include "basic_functions.h"
#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p6.h"

bool registry[16][8];
bool instructionMemory[256][8];
bool dataMemory[16][8];
bool PC[8];
bool IR[32];

void initialize() {
  // TODO
}

bool* getRegistryValue(bool* output, bool registerNum[8]) {
  // TODO
  return 0;
}

void setRegistryValue(bool registerNum[8], bool value[8]) {
  // TODO
  return 0;
}

int toDecimal(bool registerNum[8]) {
  // TODO
  return 0;
}

void incrementPC() {
  // TODO
}

void addPC(bool addressOffset[8]) {
  // TODO
}

void instructionFetch() {
  // TODO
}

void parseInstructionInIR(bool* name,
                          bool* reg_out,
                          bool* reg_in1,
                          bool* reg_in2,
                          bool* imm16) {
  // TODO
}

void initializeInstructionMemory(std::ifstream& fp) {
  // TODO
}

bool* getInstructionValue(bool* output, const std::string& instructionName) {
  // TODO
  return 0;
}

void mem(bool registerNum[8], bool memlocation[16], bool read, bool write) {
  // TODO
}

void lw(bool registerNum[8], bool memlocation[16]) {
  // TODO
}

void sw(bool registerNum[8], bool memlocation[16]) {
  // TODO
}

void readOrWriteMem(bool value[8], bool memlocation[8], bool read, bool write) {
  // TODO
}

void readMem(bool value[8], bool memlocation[16]) {
  // TODO
}

void writeMem(bool value[8], bool memlocation[16]) {
  // TODO
}

