#User function Template for python3
'''
# Node Class
    class Node:
        def __init__(self, data):   # data -> value stored in node
            self.data = data
            self.next = None
            self.prev = None
'''
class Solution:
    #Function to delete all the occurances of a key from the linked list.
    def deleteAllOccurOfX(self, head, x):
        # code here
        while head.data == x:
            head = head.next
        temp = head
        while temp.next:
            if temp.next.data == key:
                temp.next = temp.next.next
            else:
                temp = temp.next
        return head
        # edit the linked list