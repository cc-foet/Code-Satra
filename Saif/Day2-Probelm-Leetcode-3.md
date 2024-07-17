[Question No. 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

### Question Description :

Given a String `s`, find the length of the longest substring without repeating characters.

`Example`
`Input : s = 'abcabcbb'`
`Output : 3 `
`Explanation : The answer is 'abc', with the length of 3.`

## Solution in java

```java
 public int lengthOfLongestSubstring(String s) {
      if(s==null)
      // Checks if the string is empty
            return 0;
            // If yes then it will return 0;
	boolean[] flag = new boolean[256]; // Creating a boolean array named flag;

	int result = 0;
	int start = 0;
	char[] arr = s.toCharArray(); // Converting string into char Array using toCharArray() function.

	for (int i = 0; i < arr.length; i++) { // iterating over the string array;
		char current = arr[i]; // Storing the current charater
		if (flag[current]) // Checks if the current character is already seen in the current substring
                {
			result = Math.max(result, i - start); // Update the result with the length of the current substring, max between previouse result and current length of substring ,

			for (int k = start; k < i; k++)
                         {
				if (arr[k] == current) { // checks if the char at k is == current if yes then move the pointer by one to skip the duplicate character;
					start = k + 1;
					break;
				}
				flag[arr[k]] = false; // This line reset the flag for character at index k;
			}
		} else {
                        // Marks that the character saved in current is seen once in the arr;
			flag[current] = true;
		}
	}
// Store the longest substring into the result and return the result;
	result = Math.max(arr.length - start, result);

	return result;
    }
```
