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
  static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if ((nullptr == l1) && (nullptr == l2)) {
      return nullptr;
    }
    // Initialize the result list.
    auto result_head = new ListNode(0);
    auto l1_node = l1;
    auto l2_node = l2;
    ListNode* prev_node = nullptr;
    auto result_node = result_head;
    int carry = 0;
    while ((l1_node != nullptr) || (l2_node != nullptr)) {
      int sum = carry;
      if (l1_node != nullptr) {
        sum += l1_node->val;
        l1_node = l1_node->next;
      }
      if (l2_node != nullptr) {
        sum += l2_node->val;
        l2_node = l2_node->next;
      }
      result_node->val = sum % 10;
      carry = sum / 10;
      result_node->next = new ListNode(0);
      prev_node = result_node;
      result_node = result_node->next;
    }
    if (carry > 0) {
      result_node->val += carry;
    } else if (0 == result_node->val) {
      // Remove the leading zero.
      prev_node->next = nullptr;
      delete result_node;
      result_node = nullptr;
    }
    return result_head;
  }
};