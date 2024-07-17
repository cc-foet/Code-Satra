# this code prints the original linked list .
# and prints a linked list after removing the duplicate elements.



# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        """
        Initialize a new node with a value and a next pointer.
        
        :param val: Value of the node.
        :param next: Reference to the next node in the list.
        """
        self.val = val
        self.next = next

def deleteDuplicates(head: ListNode) -> ListNode:
    """
    Remove duplicates from a sorted linked list.
    
    This function iterates through the linked list and removes all duplicate nodes
    such that each element appears only once.
    
    :param head: Head node of the sorted linked list.
    :return: Head node of the modified list with duplicates removed.
    """
    current = head
    while current and current.next:
        if current.val == current.next.val:
            current.next = current.next.next  # Skip the duplicate node
        else:
            current = current.next  # Move to the next distinct node
    return head

# Helper function to create a linked list from a list of values
def create_linked_list(values):
    """
    Create a linked list from a list of values.
    
    This function converts a list of values into a linked list.
    
    :param values: List of values to create the linked list from.
    :return: Head node of the created linked list.
    """
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

# Helper function to print linked list
def print_linked_list(head):
    """
    Print the linked list in a readable format.
    
    This function traverses the linked list and prints the values of the nodes
    in a readable "val -> val -> ..." format.
    
    :param head: Head node of the linked list to be printed.
    """
    values = []
    current = head
    while current:
        values.append(current.val)
        current = current.next
    print(" -> ".join(map(str, values)))

# Example usage:
values = [1, 2, 2, 4, 4, 4, 5]  # List of values to create the linked list
head = create_linked_list(values)  # Create linked list from values
print("Input Linked List:")
print_linked_list(head)  # Print the original linked list
head = deleteDuplicates(head)  # Remove duplicates from the linked list
print("Output Linked List:")
print_linked_list(head)  # Print the modified linked list


# Code by- Vikas Saroj