# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sizeof(self, head):
        ''' Return size of list '''
        size = 0
        temp = head
        while temp:
            size += 1
            temp = temp.next
        return size
    
    def reverseList(self, head):
        if head is None or head.next is None:
            return head
        
        prev = None
        while head:
            temp = head.next
            head.next = prev
            prev = head
            head = temp
        
        return prev

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # edge case
        if k == 1:
            return head
        
        # set head of our final ans
        count = k - 1
        permanent_head = head
        while count:
            permanent_head = permanent_head.next
            count -= 1
        
        # rev k nodes n times
        n = Solution.sizeof(self, head) // k        # 2
        prev_temp_back = None
        while n:
            # set pointers at their respective positions
            if prev_temp_back is None:
                temp_front = head
            else:
                temp_front = prev_temp_back.next
            
            temp_back = temp_front
            count = k - 1
            while count:
                temp_back = temp_back.next
                count -= 1

            # detach list from tf to tb
            if prev_temp_back: # don't do for first case
                prev_temp_back.next = None
            next_temp_front = temp_back.next
            temp_back.next = None
            
            # rev list from tf to tb
            temp_back = temp_front
            temp_front = Solution.reverseList(self, temp_front)

            # attach reversed list
            if prev_temp_back: # don't do for first case
                prev_temp_back.next = temp_front
            temp_back.next = next_temp_front

            prev_temp_back = temp_back
            n -= 1
        
        return permanent_head