#pragma once

#include <tuple>

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
  static ListNode* reverseKGroup(ListNode* head, int k) {
    if ((nullptr == head) || (k < 2)) {
      return head;
    }
    // Keep track of the head and tail of each k-node group that is reversed.
    // The head of the first reversed group will be the head of the output list.
    ListNode* group_tail = nullptr;
    ListNode* result_head = nullptr;
    std::tie(result_head, group_tail) = reverseListIfKNode(head, k);

    // Keep a record of the current reversed group's head. This will be the next
    // node to link with the previous group.
    auto current_head = result_head;
    // Keep reversing k-nodes at a time while the current group's tail does not
    // mark the end of the output list.
    while (group_tail->next != nullptr) {
      // Mark the current group as the previous group.
      auto prev_group_tail = group_tail;
      // Reverse the next k-nodes (if they are available).
      // Update the current group's head and tail nodes accordingly.
      std::tie(current_head, group_tail) =
          reverseListIfKNode(group_tail->next, k);
      // Link the previous group with the current group's head now that it has
      // been reversed.
      prev_group_tail->next = current_head;
    }
    return result_head;
  }

 private:
  static std::tuple<ListNode*, ListNode*> reverseListIfKNode(ListNode* head,
                                                             int k) {
    if (nullptr == head) {
      return std::make_tuple(head, nullptr);
    }
    auto current_node = head;
    auto current_head = head;

    // Since k is a count and not a zero-based index, initialize to 1.
    int count = 1;
    while (current_node->next != nullptr && count < k) {
      auto next_node = current_node->next;
      current_node->next = next_node->next;
      next_node->next = current_head;
      current_head = next_node;
      ++count;
    }

    if (nullptr == current_node->next && count < k) {
      // Reverse the list once more if not all k nodes were available to
      // reverse.
      return reverseListIfKNode(current_head, count);
    }

    // Return both the head and tail of the list (or sublist) that was reversed.
    return std::make_tuple(current_head, current_node);
  }
};