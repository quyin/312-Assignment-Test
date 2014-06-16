// Util functions used by the tests.
// TA: Yin Qu (me.yin.qu@gmail.com)

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <string>



// (Only for testing) Convert numbers to bool arrays.
int to_uint(bool* a, int len);
int to_int(bool* a, int len);
int to_uint8(bool* a);
int to_uint16(bool* a);
int to_int8(bool* a);
int to_int16(bool* a);



// (Only for testing) Number to bool arrays. Converts a number into
// bool[num_bits], where num_bits can be 8 or 16. This should work for both
// signed and unsigned numbers, since int has 32bit on modern systems.
bool* to_bits(bool* output, int num, int len = 8);

// (Only for testing) Number to Byte. Converts a number into bool[8]. This
// should work for both signed and unsigned numbers, since int has 32bit on
// modern systems.
bool* to_bits8(bool* output, int num);

// (Only for testing) Number to Half-word. Converts a number into bool[16]. This
// should work for both signed and unsigned numbers, since int has 32bit on
// modern systems.
bool* to_bits16(bool* output, int num);

// (Only for testing) String to Byte. Converts a string of 0's and 1's into
// bool[8].
bool* str_to_bits8(bool* output, const char* num);



bool bitwise_eq(bool* v1, bool* v2, int len);
std::string to_str(bool* v, int len);



#endif // TEST_UTILS_H

