# Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**
```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**
```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

**Constraints:**
```
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
```

## Initial Approach
Perform standard addition.
For each digit represented by nodes within the linked-list, perform addition.
1. Initialize a result node to zero.
1. Initialize a carry value to zero.
1. Place the modulo of sum of the the two input nodes as the value of the result node.
1. Place the integer division result of the sum into a carry.
1. Advance relevant nodes while at least one input node is not equal to `NULL`.

## Complexity Analysis
### Time Complexity
Each array is traversed exactly once. The total complexity is then *__O(N)__*, where *N* is the length of the longest input list.

### Spatial Complexity
A new list is needed for the result. Therefore, the space complexity is *__O(N)__*, where *N* is the length of the longest input list.

