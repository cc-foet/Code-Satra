# [Problem Number : 29 ](https://leetcode.com/problems/divide-two-integers/description/)

```java
class Solution {
    public int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // Determine the sign of the result
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        // Convert dividend and divisor to positive
        long dvd = Math.abs((long) dividend);
        long dvs = Math.abs((long) divisor);

        int quotient = 0;
        while (dvd >= dvs) {
            long temp = dvs;
            int multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return sign * quotient;
    }
}

```

## code Explaination :

`if (dividend == Integer.MIN_VALUE && divisor == -1)
                return Integer.MAX_VALUE;`
This block of code checks for specific edge case where the dividend is `Integer.MIN_VALUE` which is (-2 ^ 31) and the divison is -1,
In this case the result would overflow if we perfomed divison therefore we return the `Integer.MAX_VALUE` instead;

`final int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;`
In this line of code we are checking the sign of the result using (XOR) operator if teh sign of the dividend and the divisor are different, the result will be negative, so we set the `sign` to -1. Otherwise the `sign` is set to 1;

```java
int quotient = 0;
while (dvd >= dvs) {
    long temp = dvs;
    int multiple = 1;
    while (dvd >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
    }
    dvd -= temp;
    quotient += multiple;
}
```

The main division loop uses a while loop to repeatedly subtract the divisor from the dividend until the dividend is less than the divisor. The loop maintains the following invariants:

dvd (dividend) is the remaining value to be divided.
dvs (divisor) is the absolute value of the divisor.
quotient is the accumulated result.
The inner while loop uses a binary search approach to find the largest multiple of the divisor that is less than or equal to the remaining dividend. We start with temp = dvs and multiple = 1, and repeatedly double temp and multiple until temp exceeds dvd. This is done using the left shift operator (<<).

At the end return the result == quotient by multiplying it by sign;

