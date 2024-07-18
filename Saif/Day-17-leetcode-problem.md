[Leetcode Question : 1758](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)

````java

class Solution {
    public int minOperations(String s) {
         int n = s.length();
        int changesForPattern1 = 0; // pattern starting with '0'
        int changesForPattern2 = 0; // pattern starting with '1'

        for (int i = 0; i < n; i++) {
            char expectedCharForPattern1 = (i % 2 == 0) ? '0' : '1';
            char expectedCharForPattern2 = (i % 2 == 0) ? '1' : '0';

            if (s.charAt(i) != expectedCharForPattern1) {
                changesForPattern1++;
            }

            if (s.charAt(i) != expectedCharForPattern2) {
                changesForPattern2++;
            }
        }

        return Math.min(changesForPattern1, changesForPattern2);
    }
}
````