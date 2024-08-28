# Reverse a Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

**Example 1:**
```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

**Example 2:**
```
Input: head = [1,2]
Output: [2,1]
```

**Example 3:**
```
Input: head = []
Output: []
```

**Constraints:**
```
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
```

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

## Initial Approach
The problem involves moving successive nodes to the front of the list. Use two pointers:
- One to keep track of the current node position, as it advances towards the end of the list.
- Another pointer to the current head node position, as it is continuously updated.

1. Initialize two pointers to the current value of `head`: `current_node` and `current_head`.
1. While `current_node->next` is not `NULL`:
    1. Place the `next_node` from the current_node to the front of the list.
    1. Update the next pointers for `current_node` and `next_node`.
    1. Update the `current_head` to point to this new node as the head.

## Complexity Analysis
### Time Complexity
The list is traversed only once. The time complexity is then: *__O(N)__*.

### Spatial Complexity
No additional containers are needed for the solution. The complexity is *__O(1)__*.

