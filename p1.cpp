#include "basic_functions.h"
#include "p1.h"

bool XOR(bool a, bool b) {
  return  Or(And(a, Not(b)), And(b, Not(a)));
}

bool Mux(bool operation, bool output_if_true, bool output_if_false) {
  return Or(And(operation, output_if_true),
            And(Not(operation), output_if_false));
}

bool Sum(bool a, bool b) {
  return XOR(a, b);
}

bool Sum(bool a, bool b, bool c) {
  return Sum(Sum(a, b), c);
}

bool Or(bool a, bool b, bool c) {
  return Or(Or(a, b), c);
}

bool CarryOut(bool a, bool b, bool c) {
  return Or(And(a, b), And(b, c), And(c, a));
}

bool Equal(bool a, bool b) {
  return Not(XOR(a, b));
}

