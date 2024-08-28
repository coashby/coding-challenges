#include <iostream>

#include "solution.h"

void runTest(const std::string& s, int& test_number) {
  const int kLengthOfLongestSubstr = Solution::lengthOfLongestSubstring(s);
  std::cout << "Test #" << test_number
            << ": Length of longest substring: " << kLengthOfLongestSubstr
            << std::endl;
  ++test_number;
}

int main() {
  int test_number = 0;
  { runTest("abcabcb", test_number); }

  return EXIT_SUCCESS;
}