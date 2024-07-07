class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Linked_List:
    def __init__(self):
        self.head = None

    def insertion(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = Node(data)
    
    def printList(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> " if temp.next else "")
            temp = temp.next

    def removeDuplicates(self):
        temp = self.head
        if temp is None:
            return
        while temp.next is not None:
            if temp.data == temp.next.data:
                new = temp.next.next
                temp.next = None
                temp.next = new
            else:
                temp = temp.next
        return self.head

linked_list = Linked_List()

linked_list.insertion(1)
linked_list.insertion(2)
linked_list.insertion(2)
linked_list.insertion(4)
linked_list.insertion(4)
linked_list.insertion(4)
linked_list.insertion(5)

linked_list.removeDuplicates()
linked_list.printList()