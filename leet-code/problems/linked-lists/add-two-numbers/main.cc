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

void runTest(const std::vector<int>& lhs, const std::vector<int>& rhs,
             int& test_number) {
  auto lhs_list = LinkedList();
  auto rhs_list = LinkedList();
  for (const auto& val : lhs) {
    lhs_list.addAtTail(val);
  }
  for (const auto& val : rhs) {
    rhs_list.addAtTail(val);
  }
  auto lhs_head = lhs_list.getHead();
  auto rhs_head = rhs_list.getHead();

  std::cout << "Test #" << test_number << ":"
            << "List sum = " << std::endl;
  auto result_head = Solution::addTwoNumbers(lhs_head, rhs_head);
  printList(result_head);

  ++test_number;
}

int main() {
  int test_number = 0;
  {
    std::vector<int> lhs = {2, 4, 3};
    std::vector<int> rhs = {5, 6, 4};
    runTest(lhs, rhs, test_number);
  }
  return EXIT_SUCCESS;
}
