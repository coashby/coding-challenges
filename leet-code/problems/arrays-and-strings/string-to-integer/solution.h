#pragma once

#include <algorithm>
#include <cstring>
#include <string>

class Solution {
 public:
  static int myAtoi(std::string s) {
    // Create an array for storing the valid numeric values from the string.
    // Initialize all the values to zero.
    const size_t kMaxNumberOfDigits = 10;
    const size_t kMaxStrLen = 200;
    int numeric_values_list[kMaxStrLen] = {0};

    // Create a lookup table (LUT) for the characters of interest, i.e., those
    // representing the integers [0-9].
    const size_t kLookupTableSize = 2 << 8;
    int atoi_lut[kLookupTableSize];
    std::memset(atoi_lut, -1, sizeof(int) * kLookupTableSize);
    // Initialize the LUT.
    atoi_lut['0'] = 0;
    atoi_lut['1'] = 1;
    atoi_lut['2'] = 2;
    atoi_lut['3'] = 3;
    atoi_lut['4'] = 4;
    atoi_lut['5'] = 5;
    atoi_lut['6'] = 6;
    atoi_lut['7'] = 7;
    atoi_lut['8'] = 8;
    atoi_lut['9'] = 9;

    bool is_negative = false;
    bool leading_zero = false;
    bool signed_value = false;
    size_t number_of_digits = 0;
    const size_t kStrLen = s.length();
    for (size_t i = 0; i < kStrLen; ++i) {
      auto& char_i = s[i];
      // All strings are guaranteed to be NULL terminated. Therefore, the next
      // character beyond the last character in the string is addressable.
      auto& char_i_plus_1 = s[i + 1];
      // Check if a '-' or '+' precedes any numeric values.
      // Make sure to short circuit the check on the most critical trait.
      if ((number_of_digits == 0) && !signed_value) {
        if (!leading_zero && char_i == ' ') {  // Ignore leading spaces
          continue;
        } else if (char_i == '0') {
          leading_zero = true;
          continue;
        } else if (atoi_lut[char_i] > 0) {
          numeric_values_list[number_of_digits++] = atoi_lut[char_i];
          continue;
        } else if (leading_zero && (atoi_lut[char_i] < 0)) {
          // If a leading zero is not proceeded by a number then break.
          break;
        } else if (((char_i == '-') || (char_i == '+')) &&
                   (atoi_lut[char_i_plus_1] >= 0)) {
          is_negative = (char_i == '-');
          signed_value = true;
          continue;
        } else {
          break;
        }
      } else if ((number_of_digits == 0) && (char_i == '0')) {
        continue;
      } else if ((number_of_digits <= kMaxNumberOfDigits) &&
                 (atoi_lut[char_i] >= 0)) {
        numeric_values_list[number_of_digits++] = atoi_lut[char_i];
        continue;
      } else {
        break;
      }
    }

    long integer_value = 0;
    // Don't rely on overflow math for the result. Write the values for the
    // min and max integer values using long types.
    const long kMaxAbsoluteValue = (long(1) << 31);
    bool clip_value = false;

    if (number_of_digits > kMaxNumberOfDigits) {
      integer_value = kMaxAbsoluteValue;
    } else if (number_of_digits <= kMaxNumberOfDigits) {
      // Create the integer form of the number in the input string.
      int decimal_offset = number_of_digits - 1;
      long multiplier = 1;
      for (int i = decimal_offset; i >= 0; --i) {
        integer_value += numeric_values_list[i] * multiplier;
        multiplier *= 10;
      }
    }
    // Make sure values are in the range: [-2^31, 2^31 - 1]
    if (is_negative) {
      integer_value *= -1;
      integer_value = std::max(integer_value, (-1 * kMaxAbsoluteValue));
    } else {
      integer_value = std::min(integer_value, (kMaxAbsoluteValue - 1));
    }
    return static_cast<int>(integer_value);
  }
};
