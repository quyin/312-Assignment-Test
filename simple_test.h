// A simple set of tools for testing.
// This file may change in the future.

#ifndef SIMPLE_TEST_H
#define SIMPLE_TEST_H

#include <iostream>

void assert_true_helper(bool cond, const char* cond_text,
                        const char* file, const int line) {
  if (!cond) {
    std::cout << "Failed: " << cond_text
              << ", in " << file << ", line " << line << std::endl;
    std::cout << "    Expected to be true." << std::endl;
  }
}

void assert_false_helper(bool cond, const char* cond_text,
                         const char* file, const int line) {
  if (cond) {
    std::cout << "Failed: " << cond_text
              << ", in " << file << ", line " << line << std::endl;
    std::cout << "    Expected to be false." << std::endl;
  }
}

template<class T>
void assert_eq_helper(T v1, T v2, const char* v1_text, const char* v2_text,
                      const char* file, const int line) {
  if (v1 != v2) {
    std::cout << "Failed: " << v1_text << " == " << v2_text
              << ", in " << file << ", line " << line << std::endl;
    std::cout << "    Expected: " << v1 << std::endl;
    std::cout << "    Actual: " << v2 << std::endl;
  }
}

#define assert_true(cond) \
  assert_true_helper(cond, #cond, __FILE__, __LINE__)
#define assert_false(cond) \
  assert_false_helper(cond, #cond, __FILE__, __LINE__)
#define assert_eq(v1, v2) \
  assert_eq_helper(v1, v2, #v1, #v2, __FILE__, __LINE__)

#define test_case(suite_name, case_name) \
  void test_case_ ## suite_name ## _ ## case_name()

#define run_test_case(suite_name, case_name) \
  test_case_ ## suite_name ## _ ## case_name()

#endif // SIMPLE_TEST_H

