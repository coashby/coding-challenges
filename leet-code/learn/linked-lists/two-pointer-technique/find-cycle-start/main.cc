#include <iostream>
#include <string>
#include <vector>

#include "solution.h"

void runTest(const std::vector<int>& inputs, int loop_back_index,
             int test_number) {
  auto list = LinkedList();
  for (const auto& val : inputs) {
    list.addAtTail(val);
  }
  list.addLoop(loop_back_index);
  auto head = list.getHead();
  auto cycle_entrance = Solution::detectCycle(head);
  int cycle_entrance_index = -1;
  if (cycle_entrance != nullptr) {
    auto current_node = list.getHead();
    cycle_entrance_index = 0;
    while (current_node != cycle_entrance) {
      current_node = current_node->next;
      ++cycle_entrance_index;
    }
    std::cout << "Test #" << test_number << ": Cycle entrance at node index "
              << cycle_entrance_index << std::endl;
  } else {
    std::cout << "Test #" << test_number << ": No cycle found." << std::endl;
  }
}

int main() {
  int test_number = 0;
  {
    std::vector<int> inputs = {3, 2, 0, -4};
    int pos = 2;
    runTest(inputs, pos, test_number);
  }
  {
    std::vector<int> inputs = {3, 2, 0, -4};
    int pos = 1;
    runTest(inputs, pos, test_number);
  }
  {
    std::vector<int> inputs = {3, 2, 0, -4};
    int pos = -1;
    runTest(inputs, pos, test_number);
  }
  return EXIT_SUCCESS;
}
