#pragma once
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LinkedList {
 public:
  LinkedList() { _head = nullptr; }

  LinkedList(ListNode* head) : _head(head) {}

  static void deleteList(ListNode* head) {
    // Detect any existing cycle and break it.
    auto cycle_start = detectCycle(head);
    auto current_node = cycle_start;
    if (cycle_start != nullptr) {
      while (current_node->next != cycle_start) {
        current_node = current_node->next;
      }
      current_node->next = nullptr;
    }
    current_node = head;
    while (current_node != nullptr) {
      auto next_head = current_node->next;
      delete current_node;
      current_node = next_head;
    }
  }

  ~LinkedList() {
    if (_invalidated) {
      return;
    }
    deleteList(_head);
  }

  void invalidate() { _invalidated = true; }

  int get(int index) {
    int val = -1;
    auto node = getNode(index);
    if (node != nullptr) {
      val = node->val;
    }
    return val;
  }

  void addAtHead(int val) {
    auto new_node = new ListNode(val);
    new_node->next = _head;
    _head = new_node;
  }

  void addAtTail(int val) {
    auto tail_node = getTail();
    if (tail_node == nullptr) {
      addAtHead(val);
    } else {
      tail_node->next = new ListNode(val);
    }
  }

  void addAtIndex(int index, int val) {
    if (index == 0) {
      addAtHead(val);
      return;
    }
    auto prev_node = getNode(index - 1);
    if (prev_node != nullptr) {
      auto current_node = prev_node->next;
      auto new_node = new ListNode(val);
      prev_node->next = new_node;
      new_node->next = current_node;
    }
  }

  void deleteAtIndex(int index) {
    if ((index == 0) && (_head != nullptr)) {
      auto next_node = _head->next;
      delete _head;
      _head = next_node;
      return;
    }
    auto prev_node = getNode(index - 1);
    if (prev_node != nullptr) {
      auto current_node = prev_node->next;
      if (current_node != nullptr) {
        auto next_node = current_node->next;
        delete current_node;
        prev_node->next = next_node;
      }
    }
  }

  // Returns a non-const pointer.
  ListNode* getHead() { return _head; }

  void addLoop(int index) {
    auto node = getNode(index);
    auto tail = getTail();
    if ((node != nullptr) && (tail != nullptr)) {
      tail->next = node;
    }
  }

  static ListNode* detectCycle(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    // Find the intersection point of p_slow a p_fast on the cycle if it exists.
    auto p_1 = head;
    auto p_2 = head;
    size_t number_of_steps = 2;
    bool has_cycle = false;
    while (p_2 != nullptr) {
      p_1 = p_1->next;
      p_2 = advancePointer(p_2, number_of_steps);
      if (p_2 == p_1) {
        has_cycle = true;
        break;
      }
    }
    ListNode* cycle_entrance_node = nullptr;
    if (has_cycle) {
      // The fast pointer is at the intersection point on the cycle. Reset
      // p_1 to head and traverse the list once more until the intersect at
      // the cycle entrance.
      p_1 = head;
      number_of_steps = 1;
      while (p_2 != p_1) {
        p_1 = p_1->next;
        p_2 = advancePointer(p_2, number_of_steps);
      }
      cycle_entrance_node = p_2;
    }

    return cycle_entrance_node;
  }

  void intersectListAt(LinkedList& linkedList, const int index) {
    auto intersecting_tail = linkedList.getTail();
    if (intersecting_tail != nullptr) {
      // Set the tail of the intersecting list to the intersection point of the
      // (this) current list. If the intersection point does not exist, the
      // intersecting tail will still be a null terminating ListNode.
      intersecting_tail->next = this->getNode(index);
    }
  }

 private:
  static ListNode* advancePointer(ListNode* node, const size_t step_size) {
    for (size_t i = 0; (i < step_size) && (node != nullptr); ++i) {
      node = node->next;
    }

    return node;
  }

  ListNode* getNode(int index) {
    auto current_node = _head;
    for (size_t i = 0; (i < index) && (current_node != nullptr); ++i) {
      current_node = current_node->next;
    }
    return current_node;
  }

  ListNode* getTail() {
    auto current_node = _head;
    while ((current_node != nullptr) && (current_node->next != nullptr)) {
      current_node = current_node->next;
    }
    return current_node;
  }

  ListNode* _head;
  bool _invalidated;
};