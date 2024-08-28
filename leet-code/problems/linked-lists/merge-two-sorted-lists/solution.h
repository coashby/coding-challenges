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
  static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if ((nullptr == list1) || (nullptr == list2)) {
      return (list1 == nullptr) ? list2 : list1;
    }
    // Create an anchor for the merged list.
    auto merge_list = new ListNode(-1);
    auto prev_node = merge_list;
    auto node_1 = list1;
    auto node_2 = list2;
    while ((node_1 != nullptr) && (node_2 != nullptr)) {
      // The prev_node next pointer does not need to be null terminated during
      // the updates.
      if (node_1->val <= node_2->val) {
        // Merge the current node from list 1 into the result.
        prev_node->next = node_1;
        node_1 = node_1->next;
      } else {
        // Merge the current node from list 2 into the result.
        prev_node->next = node_2;
        node_2 = node_2->next;
      }
      // Advance the previous node pointer to the currently assigned node.
      prev_node = prev_node->next;
    }

    // At this point, the current node from either list1 or list2 can still have
    // un-merged values remaining.
    prev_node->next = (node_1 == nullptr) ? node_2 : node_1;

    auto return_list = merge_list->next;
    // Delete the head (anchor node) of the merge list.
    delete merge_list;
    return return_list;
  }
};