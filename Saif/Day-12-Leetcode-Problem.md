[Leetcode Problem Number : 754 ](https://leetcode.com/problems/reach-a-number/)

# Approach
First Making the target value to be absolute using `Math.abs(target)`
Initializing two variable
ans = 0 ;
pos = 0 ;

Running while Loop while pos <  new Target
adding pos which ans++;
again running a while loop with the condition (pos-newTarget) % 2 == 1;
then again running pos += ++ans;
At   the end returning ans

```` java
class Solution {
  public int reachNumber(int target) {
     int newTarget = Math.abs(target);
    int ans = 0;
    int pos = 0;

    while (pos < newTarget)
      pos += ++ans;
    while ((pos - newTarget) % 2 == 1)
      pos += ++ans;

    return ans;
  }
}
````