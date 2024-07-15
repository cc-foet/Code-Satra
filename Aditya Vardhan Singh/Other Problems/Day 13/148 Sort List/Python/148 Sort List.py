# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge_list(self, left, right):
        dummy_head = ListNode(-1)
        temp = dummy_head

        while left and right:
            if left.val < right.val:
                temp.next = left
                left = left.next
            else:
                temp.next = right
                right = right.next
            temp = temp.next
        
        if left:
            temp.next = left
        else:
            temp.next = right

        return dummy_head.next

    def find_middle_of_list(self, head):
        if head is None or head.next is None:
            return head
        
        slow = head
        fast = head.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        
        mid = Solution.find_middle_of_list(self, head)
        left = head
        right = mid.next
        mid.next = None
        left = Solution.sortList(self, left)
        right = Solution.sortList(self, right)
        return Solution.merge_list(self, left, right)
    