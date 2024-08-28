# Reorder Log Files
You are given an array of logs. Each log is a space-delimited string of words, where the
first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them
lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

**Example 1:**
```
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
```
*Explanation:*</br>
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".

**Example 2:**
```
Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
```

**Constraints:**
```
1 <= logs.length <= 100
3 <= logs[i].length <= 100
```
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.

## Sorting by Lexicographical Order

## Initial Approach
1. Create a new vector and reserve memory of equal size to the input.
1. Check the first word for the presence of a non-numeric character. If a non-numeric character is found, move the
record into a *letter-logs-only* list.
1. Sort the letter-logs by lexicographical order.
1. Concatenate the *digit-logs-only* list to the back of the *letter-logs-only* list.

### Lexicographical Sorting
Because of the problem's constraints, words can not be compared directly as strings without copying data. Instead, each
character of the string is compared in the following way:
1. Find the start of the first word in each comparison argument.
1. For the minimum word length:
    1. If the *i-th* left-hand argument **LESS THAN** the *j-th* right-hand argument, the left-hand argument is
    lexicographically smaller. Return `true`.
    1. If the *i-th* left-hand argument **GREATER THAN** the *j-th* right-hand argument, the right-hand argument is
    lexicographically smaller. Return `false`.
1. Otherwise, the two arguments share the same base:
    1. If the left-hand argument is smaller, return `true`.
    1. If the right-hand argument is smaller, return `false`
1. Otherwise, the two arguments contain the same word. Find the lexicographically smallest identifier:
    1. Return `true` if the left-hand argument identifier is smaller than the right-hand argument.
    1. Return `false` otherwise.
> *__NOTE__: To avoid copying data, the search for the lexicographically smallest identifier is performed in a similar
> manner to finding the *minimum word length in *step 2* above.*

## Complexity Analysis
The solution has three distinct steps:
1. Separating *letter-logs* from *digit-logs*: *__O(n)__*.
1. Sorting *letter-logs*: *__O(n\*log(n))__*.
1. Concatenating the *letter-logs* and *digit-logs* in the specified manner: *__O(n)__*.
### Best Case: *All logs are digit-logs*
> *Complexity: __O(n)__*

In this scenario, only *step 1* is applicable. The complexity is simply *__O(n)__*.

### Worst Case: *At least half the logs are letter-logs*
> *Complexity: __O(n\*log(n))__*

In this scenario, all steps apply. The complexity is the sum of each stage:</br>
*__O(&bull;)__ = __(O(n)__ + __O(n\*log(n))__ + __O(n)__) = __O(n\*log(n))__*.

However, since the sorting stage is the fastest growing function, for large *n*, the sorting cost will dominate. Thus,
the reported complexity is: *__O(n\*log(n))__*.