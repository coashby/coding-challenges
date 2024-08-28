# Remove Nth Node From End of a List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

**Example 1:**
```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Example 2:**
```
Input: head = [1], n = 1
Output: []
```

**Example 3:**
```
Input: head = [1,2], n = 1
Output: [1]
```

**Constraints:**
```
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
```

Follow up: Could you do this in one pass?

## Initial Approach
In this approach two pointers are used. The first pointer advances until the desired gap, *N*, is achieved. Both pointers continue to advance until the first pointer reaches the end of the list.

1. Initialize two pointers `node0` and `node1`.
1. While the distance between `node0` and `node1` < *N*, advance `node0`.
1. While `node0 != NULL`, advance `node0` and `node1`.
1. If `node1 != NULL`, remove node1.
1. Return the head of the list.

## Complexity Analysis
### Time Complexity
The list if only traversed once and the solution is found once the first pointer reaches the end of the list. Therefore, the complexity is *__O(N)__*
### Spatial Complexity
No additional storage is needed. The spatial complexity is *__O(1)__*.

