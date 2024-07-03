[Question No. 350](https://leetcode.com/problems/intersection-of-two-arrays-ii/description/)

# Problem Description

Given two Integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must appear as may times as it shows in both arrays as you may return in the result in any order

### Example 1 ;

`Input : nums1 = [1,2,2,1] , nums2 = [2,2]`
`Output: [2,2]`

### Example 2;
` Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]`
`Output: [4,9]`


## Solution
```js
let intersect = function(nums1, nums2) {
    let result = [];
    let i = 0, j =0 ;
    nums1.sort((a, b) => a - b );
    nums2.sort((a,b) => a - b);
    while(  i < nums1.length && j < nums2.length){
        if(nums1[i] == nums2[j]){
            result.push(nums1[i]);
            i++;
            j++
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return result;
};
```
