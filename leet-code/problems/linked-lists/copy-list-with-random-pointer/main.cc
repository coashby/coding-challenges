#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "solution.h"

void printList(Node* head) {
  std::unordered_map<Node*, int> node_pos_map;
  auto current_node = head;
  int pos = 0;
  node_pos_map[nullptr] = -1;
  while (current_node != nullptr) {
    node_pos_map[current_node] = pos++;
    current_node = current_node->next;
  }
  if (head != nullptr) {
    std::cout << "\t[[" << head->val << ", " << node_pos_map[head->random]
              << "]";
    current_node = head->next;
    while (current_node != nullptr) {
      std::cout << ", [" << current_node->val << ", "
                << node_pos_map[current_node->random] << "]";
      current_node = current_node->next;
    }
    std::cout << "]" << std::endl;
  } else {
    std::cout << "\t{}" << std::endl;
  }
}

void runTest(const std::vector<std::array<int, 2>>& inputs, int& test_number) {
  auto pre_head = new Node(-1);
  auto prev_node = pre_head;
  std::vector<Node*> pos_node_map;
  for (const auto& val : inputs) {
    auto current_node = new Node(val[0]);
    pos_node_map.push_back(current_node);
    prev_node->next = current_node;
    prev_node = current_node;
  }
  auto head = pre_head->next;
  auto current_node = head;
  for (const auto& val : inputs) {
    if (val[1] >= 0) {
      current_node->random = pos_node_map[val[1]];
    }
    current_node = current_node->next;
  }

  std::cout << "Test #" << test_number << ":" << std::endl;
  printList(head);
  auto copied_list = Solution::copyRandomList(head);
  printList(copied_list);
  ++test_number;
}

int main() {
  int test_number = 0;
  {
    std::vector<std::array<int, 2>> inputs = {
        {7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
    int k = 1;
    runTest(inputs, test_number);
  }
  return EXIT_SUCCESS;
}