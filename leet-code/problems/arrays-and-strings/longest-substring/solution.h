#pragma once

#include <string>

class Solution {
 public:
  static int lengthOfLongestSubstring(std::string s) {
    int input_string_length = s.length();
    int max_substr_len = 0;
    // The array size is set to twice the size of a standard char set.
    const int kMapArraySize = (2 << 8) * 2;
    // Use a simple array to hash character indicies from the string.
    // Initialize the char index map to zero.
    int char_index_map[kMapArraySize] = {0};
    // Use one-based indexing when inserting new keys into the map. This allows
    // you to use zero for the unassigned state.
    // Note: Zero is the default value returned when a key has not been set.
    for (int l_idx = 0, r_idx = 0; r_idx < input_string_length; ++r_idx) {
      // If the index is greater than zero, then it has already been set.
      // Obtain the hash-key's vaule by reference. This will reduce the cost of
      // lookups during loop iterations.
      auto& current_char_idx = char_index_map[s[r_idx]];
      if (current_char_idx > 0) {
        // Only update the left index if the previous index of the current
        // character is greater than the current value of the left index.
        l_idx = std::max(current_char_idx, l_idx);
      }
      current_char_idx = r_idx + 1;
      max_substr_len = std::max(max_substr_len, r_idx - l_idx + 1);
    }
    return max_substr_len;
  }
};
