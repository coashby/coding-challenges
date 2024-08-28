#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  static void rotate(std::vector<std::vector<int>>& matrix) {
    // Flip each row in the matrix.
    size_t kMaxIndex = matrix.size() - 1;
    for (auto& row : matrix) {
      size_t l_idx = 0;
      size_t r_idx = kMaxIndex;
      while (l_idx < r_idx) {
        std::swap(row[l_idx], row[r_idx]);
        ++l_idx;
        --r_idx;
      }
    }
    // Operate within the upper left triangle.
    for (int i = 0; i < kMaxIndex; ++i) {
      int j = kMaxIndex;
      while (j > i) {
        std::swap(matrix[i][kMaxIndex - j], matrix[j][kMaxIndex - i]);
        --j;
      }
    }
  }
};