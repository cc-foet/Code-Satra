# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        st = set()
        temp = headA
        while temp:
            st.add(temp)
            temp = temp.next
        temp = headB
        while temp:
            if temp in st:
                return temp
            temp = temp.next
        return None