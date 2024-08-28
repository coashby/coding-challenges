#pragma once

#include <leet-code/common-libs/linked-list.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  static bool hasCycle(ListNode* head) {
    // For empty lists, return false.
    if (head == nullptr) {
      return false;
    }
    auto step_ptr = head;
    size_t kNumberSteps = 2;
    auto n_step_ptr = Solution::advancePointer(head, kNumberSteps);

    // First check if the n-step pointer has reached the end of the list. If
    // not, check if the n-step pointer has found it's way back to the single
    // step pointer.
    while ((n_step_ptr != nullptr) && (n_step_ptr != step_ptr)) {
      step_ptr = step_ptr->next;
      n_step_ptr = Solution::advancePointer(n_step_ptr, kNumberSteps);
    }
    return (n_step_ptr == step_ptr);
  }

  static ListNode* advancePointer(ListNode* node, const size_t number_steps) {
    for (size_t i = 0; (i < number_steps) && (node != nullptr); ++i) {
      node = node->next;
    }

    return node;
  }
};
