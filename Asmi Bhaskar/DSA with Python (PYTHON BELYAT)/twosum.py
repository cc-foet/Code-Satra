#problem number 1 from leetcode
#two sum

from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for index, val in enumerate(nums):
            rem = target - val
            if rem in d:
                return [d[rem], index]
            d[val] = index