#include <iostream>
#include <string>
#include <vector>

#include "solution.h"

void printList(ListNode* head) {
  if (head != nullptr) {
    std::cout << "\t[" << head->val;
    auto current_node = head->next;
    while (current_node != nullptr) {
      std::cout << ", " << current_node->val;
      current_node = current_node->next;
    }
    std::cout << "]" << std::endl;
  } else {
    std::cout << "\t{}" << std::endl;
  }
}

void runTest(const std::vector<int>& inputs, int& test_number) {
  auto list = LinkedList();
  for (const auto& val : inputs) {
    list.addAtTail(val);
  }
  auto head = list.getHead();
  std::cout << "Test #" << test_number << ":" << std::endl;
  printList(head);
  head = Solution::reverseList(head);
  printList(head);

  ++test_number;
}

int main() {
  int test_number = 0;
  {
    std::vector<int> inputs = {1, 2};
    runTest(inputs, test_number);
  }
  {
    std::vector<int> inputs = {1};
    runTest(inputs, test_number);
  }
  {
    std::vector<int> inputs = {1, 2, 3, 4, 5};
    runTest(inputs, test_number);
  }
  return EXIT_SUCCESS;
}
