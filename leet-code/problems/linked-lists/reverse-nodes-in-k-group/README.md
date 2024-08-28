# Reverse Nodes In K Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

**Example 1:**
```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

**Example 2:**
```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

**Constraints:**
```
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
```

Follow-up: Can you solve the problem in O(1) extra memory space?


## Initial Approach
The problem can be solved as a series of *k-length* list reverse operations.
The procedure then is to:
1. Develop a list reversal algorithm that works on lists of at least *k* nodes. If the list contains fewer than *k*
nodes, then leave the nodes in their original order.
1. Develop an algorithm to partition a list into groups of size *k* and reverse them.

The top level procedure is as follows:
1. Initialize pointers to store the return list's head, the current group's head, and the current group's tail.
1. Reverse the fist set of k nodes. Keep the head of this group as the return list's head and the tail as the current
group's tail.
1. While the current group's tail is not the last node of the input list:
    1. Define a pointer the store the current group's tail as the previous groups tail.
    1. Reverse the next group of *k* nodes using the current group's next node as the start of the next group.
    1. Update the current group's tail the the tail of the reversed group.
    1. Update the next point of previous group's tail to the head of the reversed group.

The modified reverse list procedure is as follows:
1. Initialize a pointer for the reverse list head and current node to the input list head.
1. Initialize the count of reversed nodes to 1.
1. While the current node does not the last available node, and the number of reversed nodes < *k*:
    1. Initialize a pointer to the next node of the current node.
    1. Set the next pointer of the current node to the next node's next pointer (remove the next node from it's position
    in the list).
    1. Set the next pointer of the next node current node (making it the new head node).
    1. Update the count of reversed nodes.
1. Once all applicable nodes have been processed, if the current node is the last node in the input list and less than
*k* nodes have been reversed, undo the last k node reversals.
1. Return the head node and the current node &mdash; the tail node.
> *__NOTE__: The reversal of a list can be undone by calling the reverse algorithm again and setting k to the value of
count after all applicable nodes have been reversed.*

## Complexity Analysis
### Time Complexity
The above implementation does not search for the length of each subgroup. In worst case scenarios, the last partial
group *m* will be processed twice (once to reverse the list, and another iteration to undo the reversal. This results in
*__O(N + m)__* processing time which simplified to *__O(N)__*.

### Spatial Complexity
No additional storage containers are need. Therefore the complexity is *__0(1)__*.
