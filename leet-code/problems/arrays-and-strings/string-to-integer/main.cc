#include <iostream>

#include "solution.h"

void runTest(const std::string& s, int& test_number) {
  int int_value = Solution::myAtoi(s);
  std::cout << "Test #" << test_number << ": " << s << " => " << int_value
            << std::endl;
  ++test_number;
}

int main() {
  int test_number = 0;
  { runTest(" 000000000000000-0000000012345678", test_number); }
  return EXIT_SUCCESS;
}
