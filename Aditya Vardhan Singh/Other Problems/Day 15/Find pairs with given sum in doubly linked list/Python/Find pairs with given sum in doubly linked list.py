from typing import Optional


from typing import List

"""

Definition for singly Link List Node
class Node:
    def __init__(self,x):
        self.data=x
        self.next=None
        self.prev=None

You can also use the following for printing the link list.
displayList(node)
"""

class Solution:
    def findPairsWithGivenSum(self, target : int, head : Optional['Node']) -> List[List[int]]:
        # code here
        ans = []
        if head.next is None:
            return ans
        
        p1 = head
        p2 = head
        
        while p2.next:
            p2 = p2.next
        
        while p1 is not p2 and p2.next is not p1:
            d1, d2 = p1.data, p2.data
            
            if (d1 + d2) == target:
                ans.append([d1, d2])
                p1 = p1.next
                p2 = p2.prev
            elif (d1 + d2) < target:
                p1 = p1.next
            else:
                p2 = p2.prev
        
        return ans


