[Leetcode Problem : 754 Reach a Number](https://leetcode.com/problems/reach-a-number/)



````java
class Solution {
  public int reachNumber(int target) {
    final int newTarget = Math.abs(target);
    int ans = 0;
    int pos = 0;

    while (pos < newTarget)
    // Checking is the current Position of the pointer is less than the newTarget or not if yes
    // Changing the value of Position = position + (1+ans);
      pos += ++ans;
    while ((pos - newTarget) % 2 == 1) // checking if the difference between the position and the newTarget is odd
      pos += ++ans;

    return ans; // Returning the answer
  }
}
````