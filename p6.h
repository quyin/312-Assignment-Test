// Functions required by Problem 6.
//
// In your p6.cpp, you should include basic_functions.h, p1.h, and so on, if you
// want to use previously built functions.
//
// Note that you can only use functions you have built so far, unless explicitly
// indicated.

#ifndef P6_H
#define P6_H

#include <fstream>
#include <string>

// Registry, memory, and counters.
// You should define these global data structures in your p6.cpp.
extern bool registry[16][8];
extern bool instructionMemory[256][8];
extern bool dataMemory[16][8];
extern bool PC[8];
extern bool IR[32];

// You should initialize the registry, PC, and other necessary data stores to
// zero when the program starts, by calling this function. The test program will
// call it, too.
void initialize();

// Reading and writing registers.
bool* getRegistryValue(bool* output, bool registerNum[8]);
void setRegistryValue(bool registerNum[8], bool value[8]);

// You may use any C++ provided features to implement this function.
int toDecimal(bool registerNum[8]);

// PC = PC + 4.
void incrementPC();
// PC = PC + addressOffset; addressOffset must be multiple of 4.
void addPC(bool addressOffset[8]);

// Fetch 32 bits from instructionMemory[PC] to IR.
void instructionFetch();

// Parse a 32-bit instruction in IR to 4 or 3 parts.
//
// For R-format instructions, this will parse the instruction into name,
// reg_out, reg_in1, and reg_in2, and leave imm16 untouched.
//
// For I-format instructions, this will parse the instruction into name,
// reg_out, and imm16, and leave reg_in1 and reg_in2 untouched.
//
// Arguments:
// - name:    8bit for the name (op code) of the instruction.
// - reg_out: 8bit for the register that will be used to place the result.
// - reg_in1: 8bit for the register from which the 1st operand will be loaded.
// - reg_in2: 8bit for the register from which the 2nd operand will be loaded.
// - imm16:   16bit for the immediate number from the instruction.
void parseInstructionInIR(bool* name,
                          bool* reg_out,
                          bool* reg_in1,
                          bool* reg_in2,
                          bool* imm16);

// Load instructions from an input file stream.
// You may use any C++ provided features to implement this function.
void initializeInstructionMemory(std::ifstream& fp);
// Convert the name of an instruction (e.g. addu, lw) into its 8bit op code.
// You may use any C++ provided features to implement this function.
bool* getInstructionValue(bool* output, const std::string& instructionName);

// Read or write memory.
//
// When read is true and write is false, read the byte at the indicated memory
// location to the register indexed by registerNum.
//
// When write is true and read is false, write the content of the register
// indexed by registerNum to the indicated memory location.
//
// read and write should never be the same value.
//
// You may use if..else.. in mem() to choose from calling lw() or sw().
void mem(bool registerNum[8], bool memlocation[16], bool read, bool write);
void lw(bool registerNum[8], bool memlocation[16]);
void sw(bool registerNum[8], bool memlocation[16]);

// The following functions are helpers to mem(), lw(), and sw(). They will also
// make P7 easier.
//
// You may use if..else.. in readOrWriteMem() to choose from calling readMem()
// or writeMem().
void readOrWriteMem(bool value[8], bool memlocation[8], bool read, bool write);
void readMem(bool value[8], bool memlocation[16]);
void writeMem(bool value[8], bool memlocation[16]);

#endif // P6_H

