#include <iostream>

#include "solution.h"

void runTest(std::vector<int>& height, int& test_number) {
  const int kTrappedWaterAmount = Solution::trap(height);
  std::cout << "Test #" << test_number
            << ": Trapped water amount = " << kTrappedWaterAmount << std::endl;
  ++test_number;
}

int main() {
  int test_number = 0;
  {
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    runTest(height, test_number);
  }
  {
    std::vector<int> height = {0, 5, 4, 0, 1, 0, 3, 0};
    runTest(height, test_number);
  }
  return EXIT_SUCCESS;
}
