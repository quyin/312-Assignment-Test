// Implementations of test related functions.
// TA: Yin Qu (me.yin.qu@gmail.com)

#include "simple_test.h"

using namespace std;

void assert_true_helper(bool cond,
                        const char* cond_text,
                        const char* file,
                        const int line) {
  if (!cond) {
    cout << endl << "Failed: " << cond_text
         << ", in " << file << ", line " << line << endl;
    cout << "    Expected to be true." << endl;
  }
}

void assert_false_helper(bool cond,
                         const char* cond_text,
                         const char* file,
                         const int line) {
  if (cond) {
    cout << endl << "Failed: " << cond_text
         << ", in " << file << ", line " << line << endl;
    cout << "    Expected to be false." << endl;
  }
}

void assert_bitwise_eq_helper(bool* v1, bool* v2, int len,
                              const char* v1_text, const char* v2_text,
                              const char* file, const int line) {
  if (!bitwise_eq(v1, v2, len)) {
    cout << endl << "Failed: " << v1_text << " == " << v2_text
              << ", in " << file << ", line " << line << endl;
    cout << "    Expected: " << to_str(v1, len) << endl;
    cout << "    Actual:   " << to_str(v2, len) << endl;
  }
}

vector<TestCase> TestCaseRegisterer::test_cases;

