#pragma once

#include <vector>

class Solution {
 public:
  static int trap(std::vector<int>& height) {
    const size_t kNumberOfHeights = height.size();
    const size_t kMinNumberOfHeights = 3;
    if (kNumberOfHeights < kMinNumberOfHeights) {
      return 0;
    }

    // Use iterators to reduce the number of supporting variables needed to
    // reference values.
    auto l_max_iter = height.cbegin();
    auto r_max_iter = height.cend() - 1;

    int amount_of_trapped_water = 0;
    auto l_iter = l_max_iter + 1;
    auto r_iter = r_max_iter - 1;

    while (l_iter <= r_iter) {
      // Determine which side is the limiting factor for holding water.
      if (*l_max_iter < *r_max_iter) {
        // The left side will determine the water level until a new max height
        // is found on the left side that is GT the right side max height.
        if (*l_iter < *l_max_iter) {
          amount_of_trapped_water += *l_max_iter - *l_iter;
        } else {
          l_max_iter = l_iter;
        }
        ++l_iter;
      } else {
        // The right side will determine the water level until a new max height
        // is found on the right side that is GTE the left side max height.
        if (*r_iter < *r_max_iter) {
          amount_of_trapped_water += *r_max_iter - *r_iter;
        } else {
          r_max_iter = r_iter;
        }
        --r_iter;
      }
    }

    return amount_of_trapped_water;
  }
};