/*
    Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

    Example 1:
    Input: x = 123
    Output: 321
    LINK: https://leetcode.com/problems/reverse-integer/solutions/6925169/c-mathematical-approach-by-twiine-lq9m/
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x);

int main() {
    int x = 1234;
    int result = reverse(x);
    printf("Reversed integer: %d\n", result);
    return 0;
}

int reverse(int x) {
    //if reversed is greater than 2^31 - 1 or less than -2^31, return 0
    if (x > 2147483647 || x < -2147483647) {
        return 0;
    }
    //store a boolean to check if x is negative
    int isNegative = 0;

    //if x is negative, make it positive
    if (x < 0) {
        x = -x;
        isNegative = 1;
    }

    int digit = x;
    int reversed = 0;
    int n = -1;

    do {
        if (n == -1) {
            n = digit / 10;
            digit = digit % 10;
        } else {
            digit = n % 10;
            n = n / 10;
        }
        // Check for overflow
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) return 0;

        reversed = reversed * 10 + digit;
    } while (n != 0);

    if (isNegative) {
        reversed = -reversed;
    }

    return reversed;
}
