## Binary Search

We first need to find if it is possible to make the required number of bouquets. To do this we simply count the number of flowers that will bloom and compare it to the number of flowers required to make the given number of bouquets. If not return -1.

Next we use binary search to find the minimum number of days, with the left pointer being for the smallest number of days in the array, and right pointer for the largest number of days.

We return the final value of left pointer.