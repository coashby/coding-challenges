#include <iostream>

#include "solution.h"

void printMatrix(std::vector<std::vector<int>>& matrix) {
  for (auto& row : matrix) {
    for (auto e : row) {
      std::cout << e << " ";
    }
    std::cout << std::endl;
  }
}

void runTest(std::vector<std::vector<int>>& matrix, int& test_number) {
  auto rotated_matrix = matrix;
  Solution::rotate(rotated_matrix);
  std::cout << "Test #" << test_number << ": Transformation =" << std::endl;
  std::cout << "Input Matrix" << std::endl;
  printMatrix(matrix);
  std::cout << "Rotated Matrix (90 degrees clockwise)" << std::endl;
  printMatrix(rotated_matrix);

  ++test_number;
}

int main() {
  int test_number = 0;
  {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    runTest(matrix, test_number);
  }
  {
    std::vector<std::vector<int>> matrix = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    runTest(matrix, test_number);
  }
}