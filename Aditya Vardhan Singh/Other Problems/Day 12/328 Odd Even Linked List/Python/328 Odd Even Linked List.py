# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # If list has not more than 3 nodes, return list
        if not head or not head.next or not head.next.next:
            return head

        # Separate odd and even (index) list
        oddHead = head
        evenHead = head.next

        oddTemp = oddHead
        evenTemp = evenHead

        while oddTemp.next or evenTemp.next:
            if evenTemp.next:
                oddTemp.next = evenTemp.next
                evenTemp.next = None
                oddTemp = oddTemp.next
            if oddTemp.next:
                evenTemp.next = oddTemp.next
                oddTemp.next = None
                evenTemp = evenTemp.next
        
        oddTemp.next = evenHead

        return oddHead
