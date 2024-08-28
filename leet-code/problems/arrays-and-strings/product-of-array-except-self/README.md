# Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

**Example 1:**
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

**Example 2:**
```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

**Constraints:**
```
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
```

**Follow up:** Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

## Initial Approach
In the problem description, division is not allowed. However, division can be substituted for bitwise operations.
1. Compute the total product of the array.
1. For each index, perform a bitwise division with the total product and compute the *except-self* result.

## Preferred Approach
Implementing bitwise division takes time to write and verify correctness. A subjectively simpler approach is to traverse the array such that the exact product is computed for each index *i*.
1. Define variables `prefix_product` and `suffix_product`.
1. &forall; *i* &isin; {0, N-1}:
    1. Compute the *i-th prefix product*:
        ```
        prefix_product[i] = input[0] * input[1] * ... * input[i-1];
        ```
    1. Compute the *i-th suffix product*:
        ```
        suffix_product[i] = input[i+1] * input[i+2] * ... * input[N-1];
        ```
    1. Store the result as:
        ```
        result[i] = prefix_product[i] * suffix_product[i];
        ```
This can be implemented by keeping a running product for both the prefix and suffix products &forall; i &isin; {1, 2, ..., N-1}.
- The *prefix product* is calculated going from left to right in the array: `prefix_product *= input[i]`.
- The *suffix product* is calculated going from right to left in the array: `suffix_product *= input[N-1-i]`.

Both partial products must be used to update the result array before they are updated with a new product from the input.
The final solution is as follows:
```c++
for (size_t i = 0, j = kNumberInputs - 1; i < kNumberInputs; ++i, --j) {
      // Accumulate the product going towards the tail of the array.
      result[i] *= prefix_product;
      prefix_product *= nums[i];
      // Accumulate the product going towards the head of the array.
      result[j] *= suffix_product;
      suffix_product *= nums[j];
    }
```
## Complexity Analysis
### Time Complexity
The solution requires one pass to compute the product and store the result. The total complexity is *__O(n)__*.

### Space Complexity
The solution only relies upon the input vector and output vector for storage. Therefore, the space complexity is *__O(1)__*.
