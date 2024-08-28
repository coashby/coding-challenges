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
  static ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // Do not process any empty lists.
    if ((headA == nullptr) || (headB == nullptr)) {
      return nullptr;
    }
    // Otherwise...
    // Let node_0 = headA and node_1 = headB on the initial assignment.
    // The re-initialization of node_0 and node_1 within the loop are dependent
    // on the initial assignments made here.
    auto node_0 = headA;
    auto node_1 = headB;
    // During the second traversal of each list, the pointers will align an
    // either terminate on the intersecting node, or their respective list ends.
    while (node_0 != node_1) {
      // Check for the end of each list.
      // If a list reaches its end, point it to the head of the opposite list.
      // Otherwise, advance the pointer.
      node_0 = (node_0 == nullptr) ? headB : node_0->next;
      node_1 = (node_1 == nullptr) ? headA : node_1->next;
    }
    // If (node_0 != nullptr) AND (node_0 == node_1), then node_0 is the
    // intersecting node.
    return node_0;
  }
};
