#include <iostream>
#include <vector>

#include "solution.h"

void runTest(const std::vector<int>& inputA, size_t skipA,
             const std::vector<int>& inputB, size_t skipB, int test_number) {
  auto listA = LinkedList();
  auto listB = LinkedList();
  for (size_t i = 0; i < inputA.size(); ++i) {
    listA.addAtTail(inputA[i]);
  }
  for (size_t i = 0; i < skipB; ++i) {
    listB.addAtTail(inputB[i]);
  }

  listA.intersectListAt(listB, skipA);
  auto headA = listA.getHead();
  auto headB = listB.getHead();
  auto intersecting_node = Solution::getIntersectionNode(headA, headB);
  std::cout << "Test #" << test_number << ": ";
  if (intersecting_node != nullptr) {
    std::cout << "Intersection found! Intersection value = "
              << intersecting_node->val << std::endl;
    // Break the intersection
    auto current_node = (inputA.size() > inputB.size()) ? headA : headB;
    while (current_node != nullptr) {
      if (current_node->next == intersecting_node) {
        current_node->next = nullptr;
        break;
      }
      current_node = current_node->next;
    }
  } else {
    std::cout << "No intersection found." << std::endl;
  }
}

int main() {
  int test_number = 0;
  {
    std::vector<int> inputA = {3};
    std::vector<int> inputB = {2, 3};
    size_t skipA = 0;
    size_t skipB = 1;
    runTest(inputA, skipA, inputB, skipB, test_number);
  }
  {
    std::vector<int> inputA = {2, 6, 4};
    std::vector<int> inputB = {1, 5};
    size_t skipA = 3;
    size_t skipB = 2;
    runTest(inputA, skipA, inputB, skipB, test_number);
  }
  {
    std::vector<int> inputA = {1, 9, 1, 2, 4};
    std::vector<int> inputB = {3, 2, 4};
    size_t skipA = 3;
    size_t skipB = 1;
    runTest(inputA, skipA, inputB, skipB, test_number);
  }
  {
    std::vector<int> inputA = {4, 1, 8, 4, 5};
    std::vector<int> inputB = {5, 6, 1, 8, 4, 5};
    size_t skipA = 2;
    size_t skipB = 3;
    runTest(inputA, skipA, inputB, skipB, test_number);
  }
  return EXIT_SUCCESS;
}
