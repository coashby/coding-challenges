#pragma once

#include <vector>

class Solution {
 public:
  static std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int prefix_product = 1;
    int suffix_product = 1;
    const size_t kNumberInputs = nums.size();
    // Initialize the output vector to all ones.
    std::vector<int> result(kNumberInputs, 1);
    for (size_t i = 0, j = kNumberInputs - 1; i < kNumberInputs; ++i, --j) {
      // Accumulate the product going towards the tail of the array.
      result[i] *= prefix_product;
      prefix_product *= nums[i];
      // Accumulate the product going towards the head of the array.
      result[j] *= suffix_product;
      suffix_product *= nums[j];
    }
    return result;
  }
};
