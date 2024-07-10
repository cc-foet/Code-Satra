#passing the pillow problem from leetcode using python
#problem number 2582

#non time optimized solution
class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        current, d = 1, 1
        while time:
            current +=d
            if current ==n:
                d*=-1
            time-=1
        return current
        
#time optimized solution

class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        round = time // (n-1)
        rem = time % (n-1)

        if round % 2 ==0:
            return rem + 1
        return n - rem