# String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi
function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is
either. This determines if the final result is negative or positive respectively. Assume the result is positive if
neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the
string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0.
Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in
the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be
clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

**Example 1:**
```
Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
```

**Example 2:**
```
Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
```

**Example 3:**
```
Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
 ```

**Constraints:**

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

## Implementation Notes
## Initial Approach
1. Use a look up table (LUT) to convert characters to decimal values.
1. Use a combination of *check cases* to meet the parsing constraints.
1. Convert the final string to its integer value.
1. Use `long` typed values to avoid overflow.

### Parsing Constraints
The constraints are handled by individual `if` statements.
```c++
// Check if a '-' or '+' precedes any numeric values.
      // Make sure to short circuit the check on the most critical trait.
      if ((number_of_digits == 0) && !signed_value) {
        if (!leading_zero && char_i == ' ') {  // Ignore leading spaces
          continue;
        } else if (char_i == '0') {
          leading_zero = true;
          continue;
        } else if (atoi_lut[char_i] > 0) {
          numeric_values_list[number_of_digits++] = atoi_lut[char_i];
          continue;
        } else if (leading_zero && (atoi_lut[char_i] < 0)) {
          // If a leading zero is not proceeded by a number then break.
          break;
        } else if (((char_i == '-') || (char_i == '+')) &&
                   (atoi_lut[char_i_plus_1] >= 0)) {
          is_negative = (char_i == '-');
          signed_value = true;
          continue;
        } else {
          break;
        }
      } else if ((number_of_digits == 0) && (char_i == '0')) {
        continue;
      } else if ((number_of_digits <= kMaxNumberOfDigits) &&
                 (atoi_lut[char_i] >= 0)) {
        numeric_values_list[number_of_digits++] = atoi_lut[char_i];
        continue;
      } else {
        break;
      }
    }
```

#### **The Three Outer Cases**
1. `if ((number_of_digits == 0) && !signed_value)`:</br>
    As the string is parsed, ignore this section if a valid digit has been found, or a sign character *('+' or '-')* has
    been found.

1. `else if ((number_of_digits == 0) && (char_i == '0'))`:</br>
    Process leading zeros that occur after a sign character *('+' or '-')* as been found.
1. `else if ((number_of_digits <= kMaxNumberOfDigits)`:</br>
    Treat all digits found from this point on as valid digits towards the over all conversion.


#### **Ignoring Spaces and Leading Zeros Before a Sign Character**
The important case that is handled in the first `if` statement is breaking from the processing `for`-loop if a leading
zero is followed by a non-numeric character. To accomplish this the state of leading zeros is stored and then used to
evaluate:
`else if (leading_zero && (atoi_lut[char_i] < 0))`.

It differentiates between the cases: "000+001234" and "000001234"
which should result in "0" and "1234" respectively.