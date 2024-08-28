#pragma once

#include <leet-code/common-libs/linked-list.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  static ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (nullptr == head) {
      return nullptr;
    }
    auto node0 = head;
    // Initialize a reference to head. This way, if head needs to be removed,
    auto nth_node_from_end = head;
    size_t node0_to_node1_gap = 0;

    // Create the required gap between node0 and the nth_node_from_end.
    while (node0 != nullptr && (node0_to_node1_gap < n)) {
      node0 = node0->next;
      ++node0_to_node1_gap;
    }

    // Find the n-th node from the end.
    ListNode* node_prev = nullptr;
    if (node0 != nullptr) {
      node0 = node0->next;
      nth_node_from_end = nth_node_from_end->next;
      node_prev = head;
      while (node0 != nullptr) {
        node_prev = node_prev->next;
        node0 = node0->next;
        nth_node_from_end = nth_node_from_end->next;
      }
    }

    // Remove the n-th node from the end.
    if (nth_node_from_end != nullptr) {
      if (nullptr == node_prev) {
        // The nth node is the head.
        // Don't delete the head of the ListNode since this function doesn't own
        // the memory
        head = nth_node_from_end->next;
      } else {
        node_prev->next = nth_node_from_end->next;
        delete nth_node_from_end;
        nth_node_from_end = nullptr;
      }
    }
    return head;
  }
};
