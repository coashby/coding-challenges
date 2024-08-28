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
  static ListNode* reverseList(ListNode* head) {
    if (nullptr == head) {
      return nullptr;
    }

    auto current_head = head;
    auto current_node = head;

    while (current_node->next != nullptr) {
      // Update the links between the current head node, the next node, and node
      // beyond the next node.
      auto next_node = current_node->next;
      // Update the current node.
      current_node->next = next_node->next;
      // Move the next node to the front of the list.
      next_node->next = current_head;
      current_head = next_node;
    }

    return current_head;
  }

  static ListNode* reverseListRecursive(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
      return head;
    }
    auto new_head = reverseListRecursive(head->next);
    // After recursing, the old head will be at the tail.
    // Update the node to reflects it's position at the end of the list (i.e.
    // _.next == ).
    head->next->next = head;
    head->next = nullptr;

    return new_head;
  }
};
