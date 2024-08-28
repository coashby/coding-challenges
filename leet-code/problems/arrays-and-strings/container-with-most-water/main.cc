#include <iostream>

#include "solution.h"

void runTest(std::vector<int>& heights, int& test_number) {
  const int kMaxArea = Solution::maxArea(heights);
  std::cout << "Test #" << test_number << ": max area = " << kMaxArea
            << std::endl;
  ++test_number;
}

int main() {
  int test_number = 1;
  {
    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    runTest(heights, test_number);
  }
  {
    std::vector<int> heights = {1, 1};
    runTest(heights, test_number);
  }
  {
    std::vector<int> heights = {1, 8, 6, 28, 3, 7, 0, 0, 1};
    runTest(heights, test_number);
  }
  {
    std::vector<int> heights = {1, 1, 1};
    runTest(heights, test_number);
  }
  {
    std::vector<int> heights = {6, 3, 7, 43, 5, 3};
    runTest(heights, test_number);
  }
  {
    std::vector<int> heights = {6, 3, 7, 43, 3};
    runTest(heights, test_number);
  }
  {
    std::vector<int> heights = {1, 0, 0, 0, 0, 0, 0, 2, 2};
    runTest(heights, test_number);
  }
  return EXIT_SUCCESS;
}