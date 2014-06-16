// A simple set of tools for testing.
// TA: Yin Qu (me.yin.qu@gmail.com)
//
// This file may change in the future.

#ifndef SIMPLE_TEST_H
#define SIMPLE_TEST_H

#include <iostream>
#include "test_utils.h"

void assert_true_helper(bool cond,
                        const char* cond_text,
                        const char* file,
                        const int line);

void assert_false_helper(bool cond,
                         const char* cond_text,
                         const char* file,
                         const int line);

template<class T>
void assert_eq_helper(T v1,
                      T v2,
                      const char* v1_text,
                      const char* v2_text,
                      const char* file,
                      const int line) {
  if (v1 != v2) {
    std::cout << std::endl << "Failed: " << v1_text << " == " << v2_text
              << ", in " << file << ", line " << line << std::endl;
    std::cout << "    Expected: " << v1 << std::endl;
    std::cout << "    Actual:   " << v2 << std::endl;
  }
}

void assert_bitwise_eq_helper(bool* v1,
                              bool* v2,
                              int len,
                              const char* v1_text,
                              const char* v2_text,
                              const char* file,
                              const int line);

#define assert_true(cond) \
  assert_true_helper(cond, #cond, __FILE__, __LINE__)

#define assert_false(cond) \
  assert_false_helper(cond, #cond, __FILE__, __LINE__)

#define assert_eq(v1, v2) \
  assert_eq_helper(v1, v2, #v1, #v2, __FILE__, __LINE__)

#define assert_eq8(v1, v2) \
  assert_bitwise_eq_helper(v1, v2, 8, #v1, #v2, __FILE__, __LINE__)

#define assert_eq16(v1, v2) \
  assert_bitwise_eq_helper(v1, v2, 16, #v1, #v2, __FILE__, __LINE__)

#define assert_exception(expr) \
  do { \
    bool no_except = true; \
    try { \
      expr; \
    } catch (...) { \
      no_except = false; \
    } \
    if (no_except) { \
      std::cout << std::endl << "Failed: " << #expr \
                << ", in " << __FILE__ << ", line " << __LINE__ << std::endl; \
      std::cout << "    Expected an exception!" << std::endl; \
    } \
  } \
  while (false);

#define test_case(suite_name, case_name) \
  void test_case_ ## suite_name ## _ ## case_name()

#define run_test_case(suite_name, case_name) \
  test_case_ ## suite_name ## _ ## case_name()

#endif // SIMPLE_TEST_H

