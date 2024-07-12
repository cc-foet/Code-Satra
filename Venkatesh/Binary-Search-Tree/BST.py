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

def convert_to_bst(linked_list):
    if linked_list.head is None:
        return []

    temp = linked_list.head
    arr = []
    while temp:
        arr.append(temp.data)
        temp = temp.next

    def build_bst(arr):
        if not arr:
            return None

        mid = len(arr) // 2
        root = Node(arr[mid])
        root.left = build_bst(arr[:mid])
        root.right = build_bst(arr[mid+1:])
        return root

    bst = build_bst(arr)

    def preorder(root):
        if root is None:
            return []

        result = []
        result.append(root.data)
        result.extend(preorder(root.left))
        result.extend(preorder(root.right))
        return result

    return preorder(bst)

linked_list = Linked_List()
linked_list.insertion(1)
linked_list.insertion(2)
linked_list.insertion(3)
linked_list.insertion(4)
linked_list.insertion(5)
linked_list.insertion(6)
linked_list.insertion(7)

print(convert_to_bst(linked_list))