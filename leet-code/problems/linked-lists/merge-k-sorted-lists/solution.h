#pragma once

#include <vector>

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
  static ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }

    auto result_head = lists[0];
    for (size_t i = 1; i < lists.size(); ++i) {
      result_head = mergeLists(result_head, lists[i]);
    }

    return result_head;
  }

  static ListNode* mergeKListsDivideAndConquer(std::vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }

    // Successively merge two sets of lists throughout the input list.
    size_t step = 1;
    const size_t kListSize = lists.size();
    while (step < kListSize) {
      // Store results on even indicies.
      // Make sure to handle increments of size *step* properly!
      // The loop should end when i < kListSize - step.
      for (size_t i = 0; i < kListSize - step; i += (2 * step)) {
        lists[i] = mergeLists(lists[i], lists[i + step]);
      }
      step *= 2;
    }
    return lists[0];
  }

 private:
  static ListNode* mergeLists(ListNode* lhs, ListNode* rhs) {
    // Create a new node to hold the output.
    auto pre_head = ListNode(-1);
    auto prev_result_node = &pre_head;
    auto current_lhs_node = lhs;
    auto current_rhs_node = rhs;
    while ((current_lhs_node != nullptr) && (current_rhs_node != nullptr)) {
      if (current_lhs_node->val < current_rhs_node->val) {
        prev_result_node->next = current_lhs_node;
        current_lhs_node = current_lhs_node->next;
      } else {
        prev_result_node->next = current_rhs_node;
        current_rhs_node = current_rhs_node->next;
      }
      prev_result_node = prev_result_node->next;
    }

    prev_result_node->next =
        (current_lhs_node == nullptr) ? current_rhs_node : current_lhs_node;

    return pre_head.next;
  }
};