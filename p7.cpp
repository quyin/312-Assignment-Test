// Implementations for Problem 7.

#include <algorithm>
#include "p3.h"
#include "p6.h"
#include "p7.h"
#include "test_utils.h"

using namespace std;

void tick() {
  bool op[8], rd[8], rs[8], rt[8], imm[16];
  bool rs_value[8], rt_value[8], rd_value[8];
  bool read = false, write = false, is_li = false, is_alu = false;
  bool alu_result[8], final_result[8];

  // IF
  instructionFetch();

  // ID
  parseInstructionInIR(op, rd, rs, rt, imm);
  getRegistryValue(rs_value, rs);
  getRegistryValue(rt_value, rt);
  getRegistryValue(rd_value, rd);

  int op_code = to_uint8(op);
  if (op_code == 14) {
    // LW
    read = true;
  } else if (op_code == 15) {
    // SW
    write = true;
  } else if (op_code == 30) {
    // LI
    is_li = true;
  } else {
    // (alu operations)
    is_alu = true;
  }

  // EX
  alu(op, alu_result, rs_value, rt_value);

  // MEM
  readOrWriteMem(rd_value, imm, read, write);

  // WB
  if (is_li) {
    copy_n(imm, 8, final_result);
  } else if (is_alu) {
    copy_n(alu_result, 8, final_result);
  } else {
    copy_n(rd_value, 8, final_result);
  }
  setRegistryValue(rd, final_result);

  incrementPC();
}

