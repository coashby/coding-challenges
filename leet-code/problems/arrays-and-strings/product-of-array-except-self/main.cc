#include <iostream>

#include "solution.h"

void runTest(std::vector<int>& nums, int& test_number) {
  const std::vector product_vector = Solution::productExceptSelf(nums);
  if (product_vector.size() > 0) {
    std::cout << "Test #" << test_number << ": Product vector = " << std::endl;
    std::cout << "[" << product_vector[0];
    for (size_t i = 1; i < product_vector.size(); ++i) {
      std::cout << ", " << product_vector[i];
    }
    std::cout << "]" << std::endl;
  }
  ++test_number;
}

int main() {
  int test_number = 0;
  {
    std::vector<int> nums = {1, -1, 16, 16, 16, 16, 16, 16, 16, 4};
    runTest(nums, test_number);
  }
  {
    std::vector<int> nums = {1, 2, 3};
    runTest(nums, test_number);
  }
  {
    std::vector<int> nums = {1, 2, 3, -4, 5, 3, 4};
    runTest(nums, test_number);
  }
  {
    std::vector<int> nums = {-1, 1, 0, -3, 3};
    runTest(nums, test_number);
  }
  {
    std::vector<int> nums = {1, 2, 3, 4};
    runTest(nums, test_number);
  }
  return EXIT_SUCCESS;
}