[Question 1394](https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/)

Approach ->

Step 1 : Need to sort the given array

Step 2 : We will start taking element from both end, (from start and from end) of the array.
Then we will calculate the sum of the 2 element of the array, and will take the minimum value.

At the end we will return the minimum value divided by 2 as the answer

Time Complexity : O(n logn)
Space complexity : O(logn)
n => length of array

```js
var minimumAverage = function (nums) {
	nums.sort((a, b) => a - b);
	const n = nums.length;
	let ans = Infinity;
	for (let i = 0; i * 2 < n; ++i) {
		ans = Math.min(ans, nums[i] + nums[n - 1 - i]);
	}
	return ans / 2;
};
```
