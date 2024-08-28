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
  static ListNode* detectCycle(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    // Find the intersection point of p_slow a p_fast on the cycle if it exists.
    auto p_1 = head;
    auto p_2 = head;
    size_t number_of_steps = 2;
    bool has_cycle = false;
    while (p_2 != nullptr) {
      p_1 = p_1->next;
      p_2 = advancePointer(p_2, number_of_steps);
      if (p_2 == p_1) {
        has_cycle = true;
        break;
      }
    }
    ListNode* cycle_entrance_node = nullptr;
    if (has_cycle) {
      // The fast pointer is at the intersection point on the cycle. Reset
      // p_1 to head and traverse the list once more until the intersect at
      // the cycle entrance.
      p_1 = head;
      number_of_steps = 1;
      while (p_2 != p_1) {
        p_1 = p_1->next;
        p_2 = advancePointer(p_2, number_of_steps);
      }
      cycle_entrance_node = p_2;
    }

    return cycle_entrance_node;
  }

 private:
  static ListNode* advancePointer(ListNode* node, const size_t step_size) {
    for (size_t i = 0; (i < step_size) && (node != nullptr); ++i) {
      node = node->next;
    }

    return node;
  }
};
