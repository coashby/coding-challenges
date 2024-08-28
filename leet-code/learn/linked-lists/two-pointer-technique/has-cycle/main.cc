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
  auto has_cycle = Solution::hasCycle(head);
  std::string has_cycle_text_result = has_cycle ? "TRUE" : "FALSE";
  std::cout << "Test #" << test_number
            << ": Cycle found = " << has_cycle_text_result << std::endl;
}

int main() {
  int test_number = 0;
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
