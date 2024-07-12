# Define data structure

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Find middle of list

def find_middle_of_list(head):
    prev_ptr = None
    slow_ptr = head
    fast_ptr = head

    while fast_ptr and fast_ptr.next:
        prev_ptr = slow_ptr
        slow_ptr = slow_ptr.next
        fast_ptr = fast_ptr.next.next

    if prev_ptr:
        prev_ptr.next = None

    return slow_ptr

# Convert list to BST

def sorted_list_to_bst(head):
    if head is None:
        return None
    
    mid = find_middle_of_list(head)

    node = TreeNode(mid.val)
    
    if head == mid:
        return node
    
    node.left = sorted_list_to_bst(head)
    node.right = sorted_list_to_bst(mid.next)

    return node

def preorder_traversal(root):
    if root is None:
        return []
    
    return [root.val] + preorder_traversal(root.left) + preorder_traversal(root.right)

def create_list(arr):
    if not arr:
        return None
    
    head = ListNode(arr[0])
    current = head
    for value in arr[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

list = create_list([1, 2, 3, 4, 5, 6, 7])
bst = sorted_list_to_bst(list)
#pre-order traversal result in array
pot_arr = preorder_traversal(bst)
print(pot_arr)
