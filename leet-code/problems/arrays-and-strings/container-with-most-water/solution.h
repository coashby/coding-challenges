#pragma once

#include <algorithm>
#include <vector>

class Solution {
 public:
  static int maxArea(std::vector<int>& height) {
    int left_idx = 0;
    int right_idx = height.size() - 1;
    int max_area = -1;
    while (left_idx < right_idx) {
      max_area = std::max(
          max_area, (right_idx - left_idx) *
                        std::min((height[left_idx]), (height[right_idx])));
      if (height[left_idx] < height[right_idx]) {
        ++left_idx;
      } else {  // height[right_idx] > height[left_idx]
        --right_idx;
      }
    }
    return max_area;
  }
};
