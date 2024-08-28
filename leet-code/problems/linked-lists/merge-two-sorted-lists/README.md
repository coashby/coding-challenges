# Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


**Example 1:**
```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:**
```
Input: list1 = [], list2 = []
Output: []
```

**Example 3:**
```
Input: list1 = [], list2 = [0]
Output: [0]
```

**Constraints:**
```
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
```

## Initial Approach
Create a new anchor point from which to begin merging elements from both lists. Then, push the lesser of either list 1 or list 2 onto the back of the merged list anchor.
> *__NOTE__: One pitfall regarding implementation complexity is to use either list as an anchor point for merging. This creates a situation where look-ahead and comparisons become more complicated.*
1. Create a new list anchor.
1. While the head of list 1 is not `NULL`, and the head list 2 is not `NULL`:
    1. If the head of list 1 is <= the head of list 2, push the head of list 1 to the back of the merged list and remove it from list 1.
    1. Otherwise, push the head of list 2 to the back of the merged list and remove it from list 2.
    1. Update the current merged list pointer to the most recent back element.
1. Merge any remaining, non `NULL` nodes onto the back of the merged list.



## Complexity Analysis

### Time Complexity
Each input list is traversed, or partially traversed, once. The shorter of the two lists *N*, is the number of iterations required to merge the two sorted lists. Therefore, the time complexity is *__O(N)__*.

### Spatial Complexity
No additional containers are needed for merging the two lists. Nodes are reused and only next pointers are updated. Therefore, the time complexity is *__O(1)__*.
