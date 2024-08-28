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

void runTest(const std::vector<std::vector<int>>& lists, int& test_number) {
  std::vector<ListNode*> node_list;
  for (const auto list : lists) {
    auto new_list = LinkedList();
    for (const auto& val : list) {
      new_list.addAtTail(val);
    }
    new_list.invalidate();
    node_list.push_back(new_list.getHead());
  }

  std::cout << "Test #" << test_number << ":"
            << "Merged lists = " << std::endl;
  auto result_head = Solution::mergeKListsDivideAndConquer(node_list);
  // Invalidate the two lists after the function call.
  printList(result_head);

  // Delete the result list.
  LinkedList::deleteList(result_head);
  ++test_number;
}

int main() {
  int test_number = 0;
  {
    std::vector<std::vector<int>> lists = {{}, {}, {}, {}, {}, {},
                                           {}, {}, {}, {}, {}};
    runTest(lists, test_number);
  }
  {
    std::vector<std::vector<int>> lists = {{}, {-1, 5, 11}, {}, {6, 10}};
    runTest(lists, test_number);
  }
  {
    std::vector<std::vector<int>> lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    runTest(lists, test_number);
  }

  return EXIT_SUCCESS;
}
