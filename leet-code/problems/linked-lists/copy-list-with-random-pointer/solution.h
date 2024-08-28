#pragma once

#include <unordered_map>

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
 public:
  static Node* copyRandomList(Node* head) {
    if (nullptr == head) {
      return nullptr;
    }
    // Create a new node head to maintain the copy.
    auto pre_copy_head = new Node(-1);
    auto prev_copy_node = pre_copy_head;
    auto current_node = head;
    int node_pos = 0;
    // Map all current nodes to their respective copies.
    std::unordered_map<Node*, Node*> node_copy_node_map;
    node_copy_node_map[nullptr] = nullptr;
    while (current_node != nullptr) {
      auto new_copy_node = new Node(current_node->val);
      node_copy_node_map[current_node] = new_copy_node;
      // Update the nodes
      prev_copy_node->next = new_copy_node;
      prev_copy_node = new_copy_node;
      current_node = current_node->next;
    }

    // Assign the random pointers accordingly.
    auto current_copy_node = pre_copy_head->next;
    current_node = head;
    while (current_node != nullptr) {
      // For each random node link, look up the corresponding copy node and
      // assign it to the copy nodes random link pointer.
      current_copy_node->random = node_copy_node_map[current_node->random];
      // Update the nodes
      current_copy_node = current_copy_node->next;
      current_node = current_node->next;
    }

    // Return the list head and deallocate any memory not part of the expected
    // return value.
    auto copy_head = pre_copy_head->next;
    delete pre_copy_head;
    return copy_head;
  }
};