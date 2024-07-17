#leetcode problem 1823
#finding the winner of the circle game where circular array is used to reach the first index again

#space and time optimum solution 
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        re = 0
        for player_no in range(2, n+1):
            re: int = (re +k) % player_no
        return re + 1