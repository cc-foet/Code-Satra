# Introduction

Author: [Aditya Vardhan Singh](https://github.com/aditya-vardhan-singh)

Languages used: `C/C++, Python, Java`

Primary language used for this file: `Python`

For solution in all languages used, go to directory: `/Code Satra Problems` and `/Other Problems`

# Table of Contents

1. [Problems / Questions](#problems--questions)
    - [Code Satra Problems](#code-satra-problems)
    - [Other Problems (leetcode)](#other-problems-leetcode)
2. [Lessons](#lessons)

# Problems / Questions

## Code Satra Problems

### Day 1

Given an array of integers, write a function that sorts the array using the bubble sort algorithm and count the number of swaps performed during the sorting process. The function should return the sorted array and the total number of swaps.

```Python
def bubble_sort_and_count(arr):
    swaps = 0
    for i in range(len(arr)):
        no_swap = True
        for j in range(len(arr)-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swaps += 1
                no_swap = False
        if no_swap:
            break
    return swaps

arr = [64, 34, 25, 12, 22, 11, 90]
print(arr)

swaps = bubble_sort_and_count(arr)
print("Sorted array: ", arr)
print("Number of swaps: ", swaps)
```

### Day 2

Given an array nums of length n+m where first n elements are sorted. Your task is to sort the last m elements in-place so that the whole array becomes sorted.

```Python
def merge(arr, low, mid, high):
    left = low
    right = mid+1
    temp = []

    while left <= mid and right <= high:
        if arr[left] < arr[right]:
            temp.append(arr[left])
            left += 1
        else:
            temp.append(arr[right])
            right += 1
    while left <= mid:
        temp.append(arr[left])
        left += 1
    while right <= high:
        temp.append(arr[right])
        right += 1
    for i in range(low, high + 1):
        arr[i] = temp[i-low]

def merge_sort(arr, low, high):
    if low < high:
        mid = low + (high - low) // 2;
        merge_sort(arr, low, mid)
        merge_sort(arr, mid + 1, high)
        merge(arr, low, mid, high)

arr = [1, 3, 6, 19, 11, 16]
print(arr)
merge_sort(arr, 0, len(arr)-1)
print(arr)
```

### Day 3

To make one bouquet we need K adjacent flowers from the garden. Here the garden consists of N different flowers, the ith flower will bloom in the bloomDay[i]. Each flower can be used inside only one bouquets. We have to find the minimum number of days need to wait to make M bouquets from the garden. If we cannot make M bouquets, then < return -1. Input: M = 2, K = 3 bloomDay = [5, 5, 5, 5, 10, 5, 5], Output: 10

```Python
import sys

def getSum(bloomDay, i, n):
    sum = 0
    for idx in range(i, n):
        sum += bloomDay[idx]
    return sum

def getMax(bloomDay, i, n):
    max = bloomDay[i]
    for idx in range(i, n):
        if bloomDay[idx] > max:
            max = bloomDay[idx]
    return max

def bouquet(bloomDay, M, K):
    adj_flowers = M * K;

    if adj_flowers > len(bloomDay):
        return -1

    min_idx = 0
    min_sum = sys.maxsize
    for i in range(len(bloomDay) - adj_flowers):
        sum = getSum(bloomDay, i, i+adj_flowers)
        if sum < min_sum:
            min_sum = sum
            min_idx = i
    
    return getMax(bloomDay, min_idx, min_idx + adj_flowers)

M = 2
K = 3
bloomDay = [5, 5, 5, 5, 10, 5, 5]

print(bouquet(bloomDay, M, K))
```

### Day 4

You are an owner of lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by given array bills[]). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is Chat the customer pays $5. NOTE: At first, you do not have any bill to provide changes with. You can provide changes from the bills that you get from the previous customers. Given an integer array bills of size N where bills [i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise. Input: N = 5, bills [] = {5, 5, 5, 10, 20) Output: True

```Python
def check_change(bills):
    ''' Check if we can provide change to every customer '''
    desk = [0] * 3
    for i in bills:
        # submit change in our desk
        match i:
            case 5: desk[0] += 1
            case 10: desk[1] += 1
            case 20: desk[2] += 1
            case _: pass
        # check change
        change = i - 5
        # check and return change
        if change == 15: 
            if desk[1] > 0 and desk[0] > 0: 
                desk[1] -= 1
                desk[0] -= 1
            elif desk[0] > 3:
                desk[0] -= 3
            else:
                return False
        elif change == 5:
            if desk[0] > 0:
                desk[0] -= 1
            else: 
                return False
    return True

bills = [5, 5, 5, 10, 20, 10, 10]
print( check_change(bills) )
```

### Day 5

Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array. Input arr1[] = {2, 3, 6, 7, 9}, arr2[] = {1, 4, 8, 10}, k = 5. Output: 6.

```Python
def find_position(arr1, arr2, k):
    arr3 = []
    n = len(arr1)
    m = len(arr2)
    i = j = 0

    while i < n and j < m:
        if arr1[i] < arr2[j]:
            arr3.append(arr1[i])
            i += 1
        else:
            arr3.append(arr2[j])
            j += 1
    
    while i < n:
        arr3.append(arr1[i])
        i += 1
    
    while j < m:
        arr3.append(arr2[j])
        j += 1
    
    return arr3[k-1]


arr1 = [2, 3, 6, 7, 9]
arr2 = [1, 4, 8, 10]
k = 5

print( find_position(arr1, arr2, k) )
```

### Day 6

Given a sorted linked list, write a function that removes all duplicates such that each element only appears once. Input: LinkedList = 1 -> 2 -> 2 -> 4 -> 4 -> 4 -> 5. Output: 1 -> 2 -> 4 -> 5.

```Python
# Create a Node class to create a node
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Create a LinkedList class
class LinkedList:
    def __init__(self):
        self.head = None

    # Method to add a node at begin of LL
    def insertAtBegin(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        else:
            new_node.next = self.head
            self.head = new_node

    # Method to add a node at any index
    # Indexing starts from 0.
    def insertAtIndex(self, data, index):
        new_node = Node(data)
        current_node = self.head
        position = 0
        if position == index:
            self.insertAtBegin(data)
        else:
            while(current_node != None and position+1 != index):
                position = position+1
                current_node = current_node.next

            if current_node != None:
                new_node.next = current_node.next
                current_node.next = new_node
            else:
                print("Index not present")

    # Method to add a node at the end of LL

    def insertAtEnd(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return

        current_node = self.head
        while(current_node.next):
            current_node = current_node.next

        current_node.next = new_node

    # Update node of a linked list
        # at given position
    def updateNode(self, val, index):
        current_node = self.head
        position = 0
        if position == index:
            current_node.data = val
        else:
            while(current_node != None and position != index):
                position = position+1
                current_node = current_node.next

            if current_node != None:
                current_node.data = val
            else:
                print("Index not present")

    # Method to remove first node of linked list

    def remove_first_node(self):
        if(self.head == None):
            return

        self.head = self.head.next

    # Method to remove last node of linked list
    def remove_last_node(self):

        if self.head is None:
            return

        current_node = self.head
        while(current_node.next.next):
            current_node = current_node.next

        current_node.next = None

    # Method to remove at given index
    def remove_at_index(self, index):
        if self.head == None:
            return

        current_node = self.head
        position = 0
        if position == index:
            self.remove_first_node()
        else:
            while(current_node != None and position+1 != index):
                position = position+1
                current_node = current_node.next

            if current_node != None:
                current_node.next = current_node.next.next
            else:
                print("Index not present")

    # Method to remove a node from linked list
    def remove_node(self, data):
        current_node = self.head

        if current_node.data == data:
            self.remove_first_node()
            return

        while(current_node != None and current_node.next.data != data):
            current_node = current_node.next

        if current_node == None:
            return
        else:
            current_node.next = current_node.next.next

    # Print the size of linked list
    def sizeOfLL(self):
        size = 0
        if(self.head):
            current_node = self.head
            while(current_node):
                size = size+1
                current_node = current_node.next
            return size
        else:
            return 0

    # print method for the linked list
    def printLL(self):
        current_node = self.head
        while(current_node):
            print(current_node.data, end=' -> ')
            current_node = current_node.next
        print('None')

    def remove_duplicate(self):
        # either empty or only head present
        if self.head is None or self.head.next is None: return # empty list

        ptr = self.head
        while ptr.next:
            if ptr.data == ptr.next.data:
                ptr.next = ptr.next.next
            else:
                ptr = ptr.next
  

# create a new linked list
llist = LinkedList()

# add nodes to the linked list
arr = [1, 1, 2, 2, 4, 4, 4, 5, 5]
for i in arr:
    llist.insertAtEnd(i)

# print the linked list
print("Original List:")
llist.printLL()

print("List after remove duplicates:")
llist.remove_duplicate()
llist.printLL()
```

### Day 7

Determine if a given string is a palindrome (reads the same forwards and backwards). Use both a stack and a queue to check for palindromes. Input: CodeSatra. Output: False

```Python
def is_palindrome_string(input_string):
    stack = []
    for i in input_string:
        stack.append(i)
    reverse_string = ""
    while len(stack) != 0:
        reverse_string += stack.pop()
    if input_string == reverse_string:
        return True
    else:
        return False

input_string = 'CodeSatra'
print(is_palindrome_string(input_string))
```

### Day 8

Given an arr[] containing n integers and a positive integer k, find the length of the longest subarray with the sum of the elements divisible by the given value k. Input: arr[] = {2, 7, 6, 1, 4, 5}, k = 3. Output: 4.

```Python
def sum_factor(arr, k):
    mod_map = {}
    max_len = 0
    prefix_sum = 0

    for i in range(len(arr)):
        prefix_sum += arr[i]
        mod = prefix_sum % k
        if mod == 0:
            max_len = i + 1
        if mod not in mod_map:
            mod_map[mod] = i
        else:
            max_len = max(max_len, i - mod_map[mod])

    return max_len

arr = [2, 7, 6, 1, 4, 5]
k = 3

print(sum_factor(arr, k))
```

### Day 9

Given an MxN matrix where M is the number of rows and N is the number of columns and an integer K (<M*N), print the Kth element of the matrix in spiral form. For a matrix [[1, 2, 3], [4, 5, 6], [7, 8, 9]] its spiral form will be [1, 2, 3, 6, 9, 8, 7, 4, 5]. Input Matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, k = 7. Output = 16.

```Python
def find_spiral(matrix: [[int]], k: int) -> int:
    n = len(matrix)
    m = len(matrix[0])
    spiral_arr = []

    top = 0
    bottom = n - 1
    left = 0
    right = m - 1

    while left <= right and top <= bottom:
        for i in range(left, right + 1):
            spiral_arr.append(matrix[top][i])
        top += 1

        for i in range(top, bottom + 1):
            spiral_arr.append(matrix[i][right])
        right -= 1

        if top <= bottom:
            for i in range(right, left - 1, -1):
                spiral_arr.append(matrix[bottom][i])
            bottom -= 1

        if left <= right:
            for i in range(bottom, top - 1, -1):
                spiral_arr.append(matrix[i][left])
            left += 1

    return spiral_arr[k-1]

matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]
]
k = 7

print(find_spiral(matrix, k))
```

### Day 10

Given an array that represents inorder traversal, find the number of possibly binary trees. Input: arr=[4, 5, 7]. Output: 5

```Python
# Find no. of binary trees using catalan algorithm
# Catalan[n] gives no of binary trees using n nodes.
# where Catalan C(i) = (i-1)Σ(j=0) C(j) × C(i-j-1)

def num_trees(n: int) -> int:
    ''' Find no of binary trees that can be constructed using n nodes using catalan formula '''
    catalan = [0] * (n + 1)
    catalan[0] = 1
    catalan[1] = 1

    for i in range(2, n + 1):
        for j in range(i):
            catalan[i] += catalan[j] * catalan[i-j-1]
    
    return catalan[n]

arr = [4, 5, 7]
print(num_trees(len(arr)))
```

### Day 11

Given a sorted linked list, convert it into a binary search tree and display its preorder traversal (root-left-right). Input: Linkedlist = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null. Output: {4, 2, 1, 3, 6, 5, 7}.

```Python
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
```

### Day 12

Given K sorted array each of length N (in the form of a 2D array), merge them and print the sorted output using a MinHeap. Input: K = 3, N = 4, arr = {{1,3,5,7}, {2,4,6,7}, {0,9,10,11}}. Output: 0 1 2 3 4 5 6 7 8 9 10 11 

```Python
import heapq

def merge_array(arr):
    K = len(arr)
    N = len(arr[0])
    
    min_heap = []
    
    # Insert the first element of each array into the heap
    for i in range(K):
        heapq.heappush(min_heap, (arr[i][0], i, 0))
    
    result = []
    
    while min_heap:
        value, row, col = heapq.heappop(min_heap)
        result.append(value)
        
        if col + 1 < N:
            heapq.heappush(min_heap, (arr[row][col + 1], row, col + 1))
    
    return result

arr = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]

output = merge_array(arr)
print(output)
```

## Other problems (leetcode)

### Day 7

[1021 Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/) - A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation. For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings. A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings. Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings. Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

```Python
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        count = 0
        substr = ""
        ans = ""
        for i in s:
            if i == '(':
                count += 1
                substr += i
            elif i == ')':
                count -= 1
                substr += i
            if count == 0:
                ans += substr[1:len(substr)-1]
                substr = ""
        return ans
```

### Day 12 

[328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) - Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list. The first node is considered odd, and the second node is even, and so on. Note that the relative order inside both the even and odd groups should remain as it was in the input. You must solve the problem in O(1) extra space complexity and O(n) time complexity.

```Python
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
```

[19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) - Given the head of a linked list, remove the nth node from the end of the list and return its head.

```Python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        size = 0
        temp = head
        while temp:
            size += 1
            temp = temp.next
        
        m = size - n + 1

        if m == 1:
            head = head.next
        else:
            count = m - 2
            temp = head
            while count:
                temp = temp.next
                count -= 1
            temp.next = temp.next.next
        
        return head
```

[2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) - You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list. The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x. For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

```Python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next is None: # one node only
            return None
        if head.next.next is None: # two nodes only
            head.next = None
            return head

        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        slow.val = slow.next.val
        slow.next = slow.next.next
        
        return head
```

# Lessons

### Day 1

Introduction to arrays. Why to use arrays?

Sorting algos:
- Bubble sort
- Selection sort
- Insertion sort
