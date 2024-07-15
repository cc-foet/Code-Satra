[Longest SubString without repeating characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)



### Solution

````java
class Solution {
    public int lengthOfLongestSubstring(String s) {
      if(s==null) // Checking that string is  null
            return 0;
	boolean[] flag = new boolean[256]; // Boolean array to store

	int result = 0;
	int start = 0;
	char[] arr = s.toCharArray();   // Char Array to store the characters

	for (int i = 0; i < arr.length; i++) {
		char current = arr[i]; // Setting current to the charater at index =  i ;

		if (flag[current]) { // Checking if the current flag is true
			result = Math.max(result, i - start);

			for (int k = start; k < i; k++) {
				if (arr[k] == current) {
					start = k + 1;
					break;
				}
				flag[arr[k]] = false;
			}
		} else {
			flag[current] = true;
		}
	}

	result = Math.max(arr.length - start, result);

	return result;
    }

}
````