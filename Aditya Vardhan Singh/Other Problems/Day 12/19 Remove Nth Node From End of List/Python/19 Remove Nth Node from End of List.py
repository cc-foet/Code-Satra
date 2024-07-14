# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        size = 0
        temp = head
        while temp:
            size += 1
            temp = temp.next
        
        m = size - n + 1

        if m == 1:
            head = head.next
        else:
            count = m - 2
            temp = head
            while count:
                temp = temp.next
                count -= 1
            temp.next = temp.next.next
        
        return head
