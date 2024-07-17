# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l3 = ListNode()
        t1, t2, t3 = l1, l2, l3
        carry = 0

        while t1 and t2:
            sum = t1.val + t2.val + carry
            if carry:
                carry = 0 
            if sum > 9:
                carry = 1
                sum -= 10
            
            t3.val = sum
            
            t1 = t1.next
            t2 = t2.next
            t3.next = ListNode()
            t3 = t3.next
        
        while t1:
            sum = t1.val + carry
            if carry:
                carry = 0
            if sum > 9:
                carry = 1
                sum -= 10
            
            t3.val = sum
            t1 = t1.next
            t3.next = ListNode()
            t3 = t3.next
        
        while t2:
            sum = t2.val + carry
            if carry:
                carry = 0
            if sum > 9:
                carry = 1
                sum -= 10
            
            t3.val = sum
            t2 = t2.next
            t3.next = ListNode()
            t3 = t3.next
        
        if carry:
            t3.val = 1
            carry = 0
        
        t3 = l3
        while t3.next.next:
            t3 = t3.next
        if t3.next.val == 0:
            t3.next = None
        
        return l3