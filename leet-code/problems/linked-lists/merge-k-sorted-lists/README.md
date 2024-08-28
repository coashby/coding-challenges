# Merge K Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

**Example 1:**
```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

**Example 2:**
```
Input: lists = []
Output: []
```

**Example 3:**
```
Input: lists = [[]]
Output: []
```

**Constraints:**
```
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
```

## Initial Approach
For this solution perform *N-1* merge operations.
1. Write a function to merge two lists (see [Merge Two Sorted Lists](../merge-two-sorted-lists/README.md#initial-approach)).
1. Assign the first list in the vector as the result head.
1. For each remaining list *i* in the vector:
    1. Merge the result head with the *i-th* list.
    1. Assign the merged values to the result head.

## Optimization
The solution in the initial approach operates in *__O(mN)__* time complexity.
This can be reduced to *__O(log(m) * N)__* if a divide and conquer approach is taken.

1. Write a function to merge two lists (see [Merge Two Sorted Lists](../merge-two-sorted-lists/README.md#initial-approach)).
1. Initialize a step size to 1. The step size will be used to determine a pair of lists to merge.
1. While step size < the size of the set of lists to merge:
    1. For each pair *i* and *i + step*:
        1. Merge the two lists that are *step size* apart.
        1. Place the result in the *i-th* index of the list.
    1. Update size: size = size * 2.

## Complexity Analysis

### Time Complexity
### Initial Approach
For each list in the input vector of size m, the merge operation requires *__O(N)__* time to complete. This results in *__O(mN)__* complexity.
### Optimized Approach
The implementation of divide and conquer results in a reduction of merge-loop iterations.
The merge results of the previous iterations are merged. At each stage the number of merges to perform is halved.
This results in *log(m)* iterations rather than *m* iterations. The overall time complexity is now *__O(log(m) * N)__*.

### Spatial Complexity
No additional space is required for either solution. Therefore the space complexity is *__O(1)__*.
