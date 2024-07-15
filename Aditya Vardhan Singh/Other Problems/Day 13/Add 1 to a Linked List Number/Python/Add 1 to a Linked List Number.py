#User function Template for python3

'''

class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None
'''

class Solution:
    def reverseList(self,head):
        if head is None or head.next is None:
            return head
        ptr = None
        
        while head:
            temp = head.next
            head.next = ptr
            ptr = head
            head = temp
        
        return ptr
    def addOne(self,head):
        #Returns new head of linked List.
        head = Solution.reverseList(self,head)
        temp = head
        carry = True
        while carry and temp:
            if temp.next is None and temp.data == 9:
                temp.data = 0
                temp.next = Node(1)
                return Solution.reverseList(self,head)
            elif temp.data == 9:
                temp.data = 0
            else:
                temp.data += 1
                carry = False
            temp = temp.next
        return Solution.reverseList(self,head)
