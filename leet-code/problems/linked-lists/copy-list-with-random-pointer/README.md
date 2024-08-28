# Copy List With Random Pointer
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

**Example 1:**
```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**Example 2:**
```
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```

**Example 3:**
```
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```

**Constraints:**
```
0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
```

## Initial Approach
This problem presents several solutions, each with their own pros and cons.

### Using a Hashmap
There are two ways to solve this problem with a hashmap. In one approach, all nodes are traversed and a mapping is established between the original node and the respective copy: `node_to_copy_node_map`.
On the second pass, the random links are connected. Since each node has a mapping to its copy, a random node link can also be retrieved, and its copy given as a random link to the current copy node. This process is done for all node/copy-node pairs.

In an alternate hashmap approach, random nodes are created and linked during the same loop iteration. Since random nodes are just references to nodes existing in the list, their mapping to a copy is also consistent with nodes created for the nodes themselves. If a node has already been created and a key exists in the hashmap, no new nodes are created. Otherwise, a new copy is made before inserting into the map. Now when the key appears as either a random link, or next pointer, the correct copy node can be found and used. This method requires more branching condition checks per loop.

### Node Interleaving
This approach requires 3 traversal of the original list:
1. Creates copies of each node adjacent to the node.
1. Random nodes are now linked. Since each copied nodes location is known (`current_node->next` due to the adjacent property), the address of the random copy node can be retrieved as: `current_node->random->next`
1. Lastly, the copied nodes are removed from the original list and returned.


## Complexity Analysis

### Time Complexity
Each implementation requires *__O(N)__* time to complete.
1. Single traversal hashmap: *__O(N)__*
1. Dual pass hashmap: *__O(N)__<sub>create_copies</sub>* + *__O(N)__<sub>assign_random_pointers</sub>* = *__O(N)__*
1. Interleaved method: *__O(N)__<sub>create_copies</sub>* + *__O(N)__<sub>assign_random_pointers</sub>* + *__O(N)__<sub>deinterleave_copies</sub>* = *__O(N)__*

### Spatial Complexity
Each hashmap approach requires *__O(N)__* space since a key/value pair is created for each node. The interleaving approach requires *__O(1)__* space, however the original lists are modified in the process.
