// A cheating implementation of the ALU, for testing.

#include "test_utils.h"

bool* alu(bool op_code[8], bool* output, bool input1[8], bool input2[8]) {
  int op = to_uint8(op_code);
  int a = to_uint8(input1);
  int b = to_uint8(input2);
  int ia = to_int8(input1);
  int ib = to_int8(input2);
  int c = 0;
  int c_num_bits = 8;
  int q, r;
  switch (op) {
    case 16: c = a + b; break;
    case 17: c = a - b; break;
    case 2: c= -a; break;
    case 3:
      c = 1;
      for (int i = 0; i < 8; ++i) {
        if (input1[i] != input2[i]) {
          c = 0;
          break;
        }
      }
      break;
    case 4: c = (a < b) ? 1 : 0; break;
    case 5: c = (a > b) ? 1 : 0; break;
    case 6:
      c = a & b;
      break;
    case 7: c = a | b; break;
    case 8: c = a << b; break;
    case 9: c = a >> b; break;
    case 0:
      c = ia + ib;
      if (c < -128 or c > 127) {
        throw "overflow";
      }
      break;
    case 1:
      c = ia - ib;
      if (c < -128 or c > 127) {
        throw "overflow";
      }
      break;
    case 10:
      c = a * b;
      c_num_bits = 16;
      break;
    case 11:
      c = ia * ib;
      c_num_bits = 16;
      break;
    case 12:
      q = a / b;
      r = a % b;
      c = (r << 8) + q;
      c_num_bits = 16;
      break;
    case 13:
      q = ia / ib;
      r = ia % ib;
      c = (r << 8) + q;
      c_num_bits = 16;
      break;
  }

  return to_bits(output, c, c_num_bits);
}

