# Code Satra Challenge

**Author**: [Aditya Vardhan Singh](https://github.com/aditya-vardhan-singh)

**Topic**: Code Satra is a 2-3 week challenge where you solve daily problems on different data structure topics, enhancing skills in data structures, algorithms, and version control systems.

**Languages Used**: `C/C++, Python, Java` | **Primary Language**: `Python`, for solutions in other languages, go to directories: `/Code Satra Problems` and `/Other Problems`

# Table of Contents

1. [Code Satra Problems](#code-satra-problems)
2. [Other Problems (LeetCode, GFG)](#other-problems-leetcode-gfg)
3. [Lessons](#lessons)

# Problems

## Code Satra Problems

<details>
<summary>Day 1: Bubble Sort with Swap Count</summary>

### Problem Statement:

Given an array of integers, write a function that sorts the array using the bubble sort algorithm and count the number of swaps performed during the sorting process. The function should return the sorted array and the total number of swaps.

### Solution Code:

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

</details>

<details>
<summary>Day 2: In-Place Sorting for Partially Sorted Array</summary>

### Problem Statement:

Given an array nums of length n+m where first n elements are sorted. Your task is to sort the last m elements in-place so that the whole array becomes sorted.

### Solution Code:

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

</details>

<details>
<summary>Day 3: Minimum Days to Make M Bouquets</summary>

### Problem Statement:

To make one bouquet we need K adjacent flowers from the garden. Here the garden consists of N different flowers, the ith flower will bloom in the bloomDay[i]. Each flower can be used inside only one bouquets. We have to find the minimum number of days need to wait to make M bouquets from the garden. If we cannot make M bouquets, then < return -1. Input: M = 2, K = 3 bloomDay = [5, 5, 5, 5, 10, 5, 5], Output: 10

### Solution Code:

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

</details>

<details>
<summary>Day 4: Lemonade Stand Change Problem</summary>

### Problem Statement:

You are an owner of lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by given array bills[]). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is Chat the customer pays $5. NOTE: At first, you do not have any bill to provide changes with. You can provide changes from the bills that you get from the previous customers. Given an integer array bills of size N where bills [i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise. Input: N = 5, bills [] = {5, 5, 5, 10, 20) Output: True

### Solution Code:

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

</details>

<details>
<summary>Day 5: Finding the Kth element in two sorted arrays</summary>

### Problem Statement:

Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the kth position of the final sorted array. Input arr1[] = {2, 3, 6, 7, 9}, arr2[] = {1, 4, 8, 10}, k = 5. Output: 6.

### Solution Code:

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

</details>

<details>
<summary>Day 6: Removing duplicates from a sorted linked list</summary>

### Problem Statement:

Given a sorted linked list, write a function that removes all duplicates such that each element only appears once. Input: LinkedList = 1 -> 2 -> 2 -> 4 -> 4 -> 4 -> 5. Output: 1 -> 2 -> 4 -> 5.

### Solution Code:

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

</details>

<details>
<summary>Day 7: Checking palindrome using stack and queue</summary>

### Problem Statement:

Determine if a given string is a palindrome (reads the same forwards and backwards). Use both a stack and a queue to check for palindromes. Input: CodeSatra. Output: False

### Solution Code:

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

</details>

<details>
<summary>Day 8: Finding the length of the longest subarray with sum divisible by k</summary>

### Problem Statement:

Given an arr[] containing n integers and a positive integer k, find the length of the longest subarray with the sum of the elements divisible by the given value k. Input: arr[] = {2, 7, 6, 1, 4, 5}, k = 3. Output: 4.

### Solution Code:

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

</details>

<details>
<summary>Day 9: Finding the Kth element of a matrix in spiral form</summary>

### Problem Statement:

Given an MxN matrix where M is the number of rows and N is the number of columns and an integer K (<M\*N), print the Kth element of the matrix in spiral form. For a matrix [[1, 2, 3], [4, 5, 6], [7, 8, 9]] its spiral form will be [1, 2, 3, 6, 9, 8, 7, 4, 5]. Input Matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, k = 7. Output = 16.

### Solution Code:

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

</details>

<details>
<summary>Day 10: Calculating the number of possible binary trees that can be formed from an inorder traversal array</summary>

### Problem Statement:

Given an array that represents inorder traversal, find the number of possibly binary trees. Input: arr=[4, 5, 7]. Output: 5

### Solution Code:

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

</details>

<details>
<summary>Day 11: Converting a sorted linked list into a binary search tree and displaying its preorder traversal</summary>

### Problem Statement:

Given a sorted linked list, convert it into a binary search tree and display its preorder traversal (root-left-right). Input: Linkedlist = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> null. Output: {4, 2, 1, 3, 6, 5, 7}.

### Solution Code:

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

</details>

<details>
<summary>Day 12: Merging K sorted arrays using a MinHeap to print the sorted output</summary>

### Problem Statement:

Given K sorted array each of length N (in the form of a 2D array), merge them and print the sorted output using a MinHeap. Input: K = 3, N = 4, arr = {{1,3,5,7}, {2,4,6,7}, {0,9,10,11}}. Output: 0 1 2 3 4 5 6 7 8 9 10 11

### Solution Code:

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

</details>

<details>
<summary>Day 13: Rearranging characters so no adjacent characters are the same in a string</summary>

### Problem Statement:

Given a string of lowercase letters, rearrange the character so that no adjacent character are the same. If not possible then return an empty string. Input: String = "aaabbc". Output: "abaca".

### Solution Code:

```Python
import heapq
from collections import Counter

def rearrange_chars(s):
    # Count frequency of each character in the string
    chars_freq = Counter(s)

    # Create a max_heap with neg freq
    heap = [(-freq, char) for char, freq in chars_freq.items()]
    heapq.heapify(heap)

    # To store previous frequency and character
    prev_count, prev_char = 0, ''
    ans_arr = []

    while heap:
        count, char = heapq.heappop(heap)
        ans_arr.append(char)

        if prev_count < 0: # character left to be used
            heapq.heappush(heap, (prev_count, prev_char))

        prev_count, prev_char = count + 1, char

    ans = ''.join(ans_arr)

    return ans if len(ans_arr) == len(s) else ''


s = "aaabbc"
print(rearrange_chars(s))
```

</details>

<details>
<summary>Day 14: Encoding and decoding a string using Huffman coding</summary>

### Problem Statement:

Given a string, compress it using huffman coding and display its binary encoded representation and also decode and print the decoded string.

### Solution Code:

```python
import heapq
from collections import Counter, namedtuple

class Node:
    def __init__(self, char, freq, left=None, right=None):
        self.char = char
        self.freq = freq
        self.left = left
        self.right = right

    def __lt__(self, other):
        return self.freq < other.freq

class HuffmanCoding:
    def __init__(self, data):
        self.data = data
        self.frequency = Counter(data)
        self.huffman_tree = self.build_huffman_tree()
        self.codes = self.generate_codes()

    def build_huffman_tree(self):
        heap = [Node(char, freq) for char, freq in self.frequency.items()]
        heapq.heapify(heap)

        while len(heap) > 1:
            left = heapq.heappop(heap)
            right = heapq.heappop(heap)
            merged = Node(None, left.freq + right.freq, left, right)
            heapq.heappush(heap, merged)

        return heap[0]

    def generate_codes(self):
        codes = {}

        def generate_codes_helper(node, current_code):
            if node is None:
                return

            if node.char is not None:
                codes[node.char] = current_code
                return

            generate_codes_helper(node.left, current_code + "0")
            generate_codes_helper(node.right, current_code + "1")

        generate_codes_helper(self.huffman_tree, "")
        return codes

    def encode(self):
        encoded_data = ''.join(self.codes[char] for char in self.data)
        return encoded_data

    def decode(self, encoded_data):
        decoded_data = []
        node = self.huffman_tree
        for bit in encoded_data:
            node = node.left if bit == '0' else node.right

            if node.char is not None:
                decoded_data.append(node.char)
                node = self.huffman_tree

        return ''.join(decoded_data)

data = "code satra"
huffman_coding = HuffmanCoding(data)
encoded_data = huffman_coding.encode()
decoded_data = huffman_coding.decode(encoded_data)

print("Input string: ", data)
print("Encoded: ", encoded_data)
print("Decoded: ", decoded_data)
```

</details>

<details>
<summary>Day 15: Detecting cycles in a directed graph and returning the cycle if present</summary>

### Problem Statement:

Given a directed graph, write a function that detects if there is a cycle in the graph. If the graph is cyclic, return the cycle, else return false. Input: Vertices = ['A', 'B', 'C', 'D'], Edges = [('A', 'B'), ('B', 'C'), ('C', 'A'), ('C', 'D')]. Output: ['A', 'B', 'C', 'A'].

### Solution Code:

```Python
def find_cycle(vertices, edges):
    from collections import defaultdict

    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)

    visited = {v: False for v in vertices}
    rec_stack = {v: False for v in vertices}

    def dfs(v, path):
        visited[v] = True
        rec_stack[v] = True
        path.append(v)

        for neighbor in graph[v]:
            if not visited[neighbor]:
                result = dfs(neighbor, path)
                if result:
                    return result
            elif rec_stack[neighbor]:
                # Cycle detected, extract the cycle
                cycle_start_index = path.index(neighbor)
                return path[cycle_start_index:] + [neighbor]

        rec_stack[v] = False
        path.pop()
        return None

    for vertex in vertices:
        if not visited[vertex]:
            path = []
            result = dfs(vertex, path)
            if result:
                return result

    return False

vertices = ['A', 'B', 'C', 'D']
edges = [('A', 'B'), ('B', 'C'), ('C', 'A'), ('C', 'D')]

cycle = find_cycle(vertices, edges)
print(cycle)
```

</details>

<details>
<summary>Day 16: Finding the shortest path in an unweighted graph from a starting node to a target node</summary>

### Problem Statement:

Given an unweighted graph, find the shortest path from a starting node to a target node. Input: Vertices: [A, B, C, D, E], Edges: [(A, B), (A, C), (B, D), (C, E), (D, E)], Start: A, Target: E. Output: [A, C, E].

### Solution Code:

```Python
from collections import deque

def bfs_shortest_path(graph, start, target):
    queue = deque([[start]])
    visited = set()

    while queue:
        path = queue.popleft()
        node = path[-1]

        if node == target:
            return path

        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                new_path = list(path)
                new_path.append(neighbor)
                queue.append(new_path)

    return None

graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['E'],
    'D': ['E'],
    'E': []
}

start = 'A'
target = 'E'
shortest_path = bfs_shortest_path(graph, start, target)
print(shortest_path)
```

</details>

<details>
<summary>Day 17: Using Dijkstra's algorithm to find the shortest path and distance between two nodes in a weighted graph</summary>

### Problem Statement:

Given a weighted graph, use Dijikstra's Algorithm to find the shortest path and the distance between the given start and end nodes. Input: Graph = { 'A': {'B': 4, 'C': 1}, 'B': {'C': 2, 'D': 5}, 'C': {'D': 8, 'E': 10), 'D': {'E': 2}, 'Ε': {}}, Start = 'A', End = 'E'. Output: Shortest Path = ['A', 'C', 'D', 'E'], Distance = 11.

### Solution Code:

```Python
from sys import maxsize as INT_MAX

size = 5

def minDistance(dist, sptSet):
    min, min_idx = INT_MAX, 0
    for v in range(size):
        if sptSet[v] is False and dist[v] <= min:
            min, min_idx = dist[v], v
    return min_idx

def printPath(parent, v):
    if (parent[v] == -1): return

    printPath(parent, parent[v])
    print(f' %d' % v, end='')

def printSolution(dist, parent, src):
    print(f'Vertex\t\tDistance\t\tPath', end='')
    for v in range(size):
        if v != src:
            print(f'\n%d->%d\t\t%d\t\t%d' %(src, v, dist[v], src), end='')
            printPath(parent, v)
    print()

def djkistra(graph, src, end):
    dist = [INT_MAX] * size
    sptSet = [False] * size
    parent = [-1] * size

    dist[src] = 0

    for count in range(0, size - 1):
        u = minDistance(dist, sptSet)
        sptSet[u] = True
        for v in range(0, size):
            if sptSet[v] is False and graph[u][v] and dist[u] != INT_MAX and (dist[u] + graph[u][v] < dist[v]):
                dist[v] = dist[u] + graph[u][v]
                parent[v] = u

    printSolution(dist, parent, src)

    print(f'\nShortest path from %d to %d' %(src, end))
    print(src, end='')
    printPath(parent, end)
    print(f'\nDistance = %d' % dist[end])

graph = [
    [0, 4, 1, 0, 0],
    [0, 0, 2, 5, 0],
    [0, 0, 0, 8, 10],
    [0, 0, 0, 0, 2],
    [0, 0, 0, 0, 0]
]

start, end = 0, 4
djkistra(graph, start, end)
```

</details>

<details>
<summary>Day 18: Floyd Warshall Algorithm</summary>

### Problem Statement:

Given a weighted graph, write a function to find the shortest paths between all pairs of nodes using Floyd-Warshall Algorithm. Input: Graph = {{0, 4, INF, 5, INF }, {INF, 0, 1, INF, 6), {2, INF, 0, 3, INF), {INF, INF, 1, 0, 2), {1, INF, INF, 4,0}}; Output: {{0, 4, 5, 5, 7), {3, 0, 1, 4, 6), {2, 6, 0, 3, 5), {3, 1, 7, 0, 2), {1, 5, 5, 4,0)}

### Solution Code:

```Python
def floyd_warshall(graph):
    n = len(graph)
    dist = [row[:] for row in graph]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf') and dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    return dist

graph = [
    [0, 4, float('inf'), 5, float('inf')],
    [float('inf'), 0, 1, float('inf'), 6],
    [2, float('inf'), 0, 3, float('inf')],
    [float('inf'), float('inf'), 1, 0, 2],
    [1, float('inf'), float('inf'), 4, 0]
]

result = floyd_warshall(graph)

for row in result:
    print(row)
```

</details>

<details>
<summary>Day 19: Shortest path in graph using Bellman-Ford Algo</summary>

### Problem Statement:

Given a weighted graph, write a function to find the shortest path from a single source node to all the other nodes using Bellman-Ford Algorithm. Input: Graph = {'A': {'B': 4, 'C': 1},
'B': {'C': -2, 'D': 5},
'C': {'E': 4, 'D': 2},
'D': {'E': -3},
'E': {}
}.
Start = 'A'.
Output: {'A': 0, 'B': 4, 'C': 1, 'D': 3, 'E': 0}

### Solution Code:

```Python
def bellman_ford(graph, start):
    distance = {node: float('inf') for node in graph}
    distance[start] = 0

    for _ in range(len(graph) - 1):
        for node in graph:
            for neighbor, weight in graph[node].items():
                if distance[node] + weight < distance[neighbor]:
                    distance[neighbor] = distance[node] + weight

    return distance

graph = {
    'A': {'B': 4, 'C': 1},
    'B': {'C': -2, 'D': 5},
    'C': {'E': 4, 'D': 2},
    'D': {'E': -3},
    'E': {}
}
start = 'A'

shortest_paths = bellman_ford(graph, start)
print(shortest_paths)
```

</details>

<details>
<summary>Day 20: Minimum time to paint boards</summary>

### Problem Statement:

Given are N boards with length of each given in the form of array, and K painters, such that each painter takes 1 unit of time to paint 1 unit of the board. The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards.
Input: n=4 arr = (10, 20, 30, 40) k=2
Output: 60

### Solution Code:

```Python
def minTime(arr, n, k):
  def checkTime(arr, n, k, max_time):
    total_time = 0
    painters = 1

    for i in range(n):
      total_time += arr[i]
      if total_time > max_time:
        total_time = arr[i]
        painters += 1
        if painters > k:
          return False
    return True

  low = max(arr) # min time
  high = sum(arr) # max time

  while low < high:
    mid = (low + high) // 2

    if checkTime(arr, n, k, mid):
      high = mid
    else:
      low = mid + 1

  return low

arr = [10, 20, 30, 40]
n = 4
k = 2

min_time = minTime(arr, n, k)
print(min_time)
```

</details>

<details>
<summary>Day 21: Minimum coins for target value using knapsack algorithm</summary>

### Problem Statement:

Given an array coins[] of size N and a target value V, where coins[i] represents the coins of different denominations. You have an infinite supply of each coin. The task is to find the minimum number of coins required to make the given value V. If it's not possible to make a change, print -1. Input: Coins = {9, 6, 5, 1}, V = 11. Output: 2.

### Solution Code:

```Python
def minCoins(coins, V):
    dp = [float('inf')] * (V+1)
    dp[0] = 0

    for i in range(1, V+1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[V] if dp[V] != float('inf') else -1

coins = [9,6,5,1]
V = 11
print(minCoins(coins, V))
```

</details>

<details>
<summary>Day 22:Longest Common Subsequence</summary>

### Problem Statement:

Given 3 strings, the task is to find the length of the longest common subsequence in all three given sequences. Input: str1="abcd1e2", str2="bc12ea", str3="bd1ea". Output: 3.

### Solution Code:

```Python
o 0
dp = [[[0 for _ in range(len3 + 1)] for _ in range(len2 + 1)] for _ in range(len1 + 1)]

# Fill the dp array
for i in range(1, len1 + 1):
    for j in range(1, len2 + 1):
        for k in range(1, len3 + 1):
            if str1[i-1] == str2[j-1] == str3[k-1]:
                dp[i][j][k] = dp[i-1][j-1][k-1] + 1
            else:
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])

# The length of the longest common subsequence
return dp[len1][len2][len3]

# Test the function
str1 = "abcd1e2"
str2 = "bc12ea"
str3 = "bd1ea"

print(lcs(str1, str2, str3))  # Output: 3
```

</details>

<details>
<summary>Day 23: N Queen Problem</summary>

### Problem Statement:

Given an integer N, place N queens on an NxN chessboard so that no two queens threaten each other. Return output in the form of a 2D array with 1 showing where the queen is placed and 0 where it's empty. Input: N=4. Output: [[0,1,0,0],[0,0,0,1],[1,0,0,0],[0,0,1,0]]

### Solution Code:

```Python
def solve_n_queen(n):

    def is_safe(board, row, col):

        for i in range(col):
            if board[row][i] == 1:
                return False

        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        for i, j in zip(range(row, n, 1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        return True

    def solve_nq_util(board, col):
        # If all queens are placed, return True
        if col >= n:
            return True

        for i in range(n):
            if is_safe(board, i, col):
                # Place this queen in board[i][col]
                board[i][col] = 1

                if solve_nq_util(board, col + 1):
                    return True

                board[i][col] = 0

        return False

    def solve_nq():
        board = [[0 for _ in range(n)] for _ in range(n)]

        if not solve_nq_util(board, 0):
            return []

        return board

    return solve_nq()

# Example usage
N = 4
result = solve_n_queen(N)
print(result)
```

</details>

<details>
<summary>Day 24: Sudoku Solver</summary>

### Problem Statement:

Given an unsolved sudoku in the form of a 9x9 matrix, where empty cells are represented by 0, solve the sudoku and display the solution. Input:
Sudoku = {{3,0,6,5,0,8,4,0,0},
{5,2,0,0,0,0,0,0,0},
{0,8,7,0,0,0,0,3,1},
{0,0,3,0,1,0,0,8,0},
{9,0,0,8,6,3,0,0,5},
{0,5,0,0,9,0,6,0,0},
{1,3,0,0,0,0,2,5,0},
{0,0,0,0,0,0,0,7,4},
{0,0,5,2,0,6,3,0,0}}.
Output: {{3,1,6,5,7,8,4,9,2},
{5,2,9,1,3,4,7,6,8},
{4,8,7,6,2,9,5,3,1},
{2,6,3,4,1,5,9,8,7},
{9,7,4,8,6,3,1,2,5},
{8,5,1,7,9,2,6,4,3},
{1,3,8,9,4,7,2,5,6},
{6,9,2,3,5,1,8,7,4},
{7,4,5,2,8,6,3,1,9}}.

### Solution Code:

```Python
def find_empty(sudoku, l):
    for i in range(9):
        for j in range(9):
            if sudoku[i][j] == 0:
                l[0] = i
                l[1] = j
                return True
    return False

def is_safe(sudoku, row, col, num):
    # check in row and col
    for i in range(9):
        if sudoku[row][i] == num:
            return False
        if sudoku[i][col] == num:
            return False

    # check in box
    start_row = row - row % 3
    start_col = col - col % 3

    for i in range(3):
        for j in range(3):
            if sudoku[i + start_row][j + start_col] == num:
                return False

    # found nowhere, therefore true
    return True

def sudoku_solve(sudoku):
    l = [0, 0]
    if not find_empty(sudoku, l):
        return True

    row = l[0]
    col = l[1]

    for num in range(1, 10):
        if is_safe(sudoku, row, col, num):
            sudoku[row][col] = num
            if sudoku_solve(sudoku):
                return True
            sudoku[row][col] = 0

    return False


sudoku = [[3,0,6,5,0,8,4,0,0],
[5,2,0,0,0,0,0,0,0],
[0,8,7,0,0,0,0,3,1],
[0,0,3,0,1,0,0,8,0],
[9,0,0,8,6,3,0,0,5],
[0,5,0,0,9,0,6,0,0],
[1,3,0,0,0,0,2,5,0],
[0,0,0,0,0,0,0,7,4],
[0,0,5,2,0,6,3,0,0]]

if sudoku_solve(sudoku):
    for i in sudoku:
        print(i)
```

</details>

<details>
<summary>Day 25: Task completion dependencies using Topological Sorting</summary>

### Problem Statement:

Given number of tasks N and an array of dependencies as pairs (a, b) where task a must be completed before task b, find a sequence to complete all tasks. Input: N = 6, Dependencies = [(5,2),(5,0),(4,0),(4,1),(2,3),(3,1)]. Output: [5,4,2,3,1,0].

### Solution Code:

```Python
from collections import deque, defaultdict

def find_task_order(N, dependencies):
    # Represent the graph
    graph = defaultdict(list)
    in_degree = [0] * N

    # Fill graph and in-degree array
    for a, b in dependencies:
        graph[a].append(b)
        in_degree[b] += 1

    # Init a queue with all tasks that have an in-degree of zero
    queue = deque([i for i in range(N) if in_degree[i] == 0])
    result = []

    # Process the queue
    while queue:
        node = queue.popleft()
        result.append(node)

        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    # Check if topological sort is possible
    if len(result) == N:
        return result
    else:
        return []

N = 6
dependencies = [(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)]
print(find_task_order(N, dependencies))
```

</details>

<details>
<summary>Day 26: Find Union (Disjonit Set Union)</summary>

### Problem Statement:

Given a network of N computers, in the form of (a, b) pairs where the pair represents a connection between computers a and b, perform a series of union and find operations to manage network connectivity and determine if two computers are in the same network. Input: N = 5, Connections = [(0,2),(4,2),(3,1)], Query = (4,0). Output: True.

### Solution Code:

```Python
class FindUnion:
    def __init__(self, size: int):
        self.parent = list(range(size))
        self.rank = [1] * size

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a: int, b: int) -> None:
        rootX = self.find(a)
        rootY = self.find(b)

        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1


def main(N, connections, query):
    fu = FindUnion(N)

    # Make connections
    for a, b in connections:
        fu.union(a, b)

    # Check query
    x, y = query
    return fu.find(x) == fu.find(y)


# Example usage

N = 5
connections = [(0, 2), (4, 2), (3, 1)]
query = (4, 0)
print(main(N, connections, query))
```

</details>

## Other problems (Leetcode, GFG)

<details>
<summary>Day 7: 1021. Remove Outermost Parentheses</summary>

### Problem Statement:

[1021 Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/) - A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation. For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings. A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings. Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings. Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

### Solution Code:

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

</details>

<details>
<summary>Day 12: 328. Odd Even Linked List</summary>

### Problem Statement:

[328 Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/) - Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list. The first node is considered odd, and the second node is even, and so on. Note that the relative order inside both the even and odd groups should remain as it was in the input. You must solve the problem in O(1) extra space complexity and O(n) time complexity.

### Solution Code:

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

</details>

<details>
<summary>Day 12: 19. Remove Nth Node From End of List</summary>

### Problem Statement:

[19 Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) - Given the head of a linked list, remove the nth node from the end of the list and return its head.

### Solution Code:

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

</details>

<details>
<summary>Day 12: 2095. Delete the Middle Node of a Linked List</summary>

### Problem Statement:

[2095 Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) - You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list. The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x. For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

### Solution Code:

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

</details>

<details>
<summary>Day 13: 148. Sort List</summary>

### Problem Statement:

[148 Sort List](https://leetcode.com/problems/sort-list/) - Given the head of a linked list, return the list after sorting it in ascending order.

### Solution Code:

```Python
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
```

</details>

<details>
<summary>Day 13: Sort a linked list of 0s, 1s and 2s</summary>

### Problem Statement:

[Sort a linked list of 0s, 1s and 2s](https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it) - Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

### Solution Code:

```Python
class Solution:
    #Function to sort a linked list of 0s, 1s and 2s.
    def segregate(self, head):
        #code here
        map = {x:0 for x in range(3)}
        temp = head
        while temp:
            map[temp.data] += 1
            temp = temp.next
        temp = head
        for value in range(3):
            while map[value] > 0:
                temp.data = value
                map[value] -= 1
                temp = temp.next
        return head
```

</details>

<details>
<summary>Day 13: 160. Intersection of Two Linked Lists</summary>

### Problem Statement:

[160 Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) - Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

### Solution Code:

```Python
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
```

</details>

<details>
<summary>Day 13: Add 1 to a Linked List Number</summary>

### Problem Statement:

[Add 1 to a Linked List Number](https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list) - A number is represented in the Linked List such that each digit corresponds to a node in the linked list. You need to add 1 to it. Returns the head of the modified linked list. Note: The head represents the leftmost digit of the number.

### Solution Code:

```Python
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
        return Solution.reverseList(self,head)
```

</details>

<details>
<summary>Day 14: 2. Add Two Numbers</summary>

### Problem Statement:

[2 Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) - You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

### Solution Code:

```Python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l3 = ListNode()
        t1, t2, t3 = l1, l2, l3
        carry = 0

        while t1 and t2:
            sum = t1.val + t2.val + carry
            if carry:
                carry = 0
            if sum > 9:
                carry = 1
                sum -= 10

            t3.val = sum

            t1 = t1.next
            t2 = t2.next
            t3.next = ListNode()
            t3 = t3.next

        while t1:
            sum = t1.val + carry
            if carry:
                carry = 0
            if sum > 9:
                carry = 1
                sum -= 10

            t3.val = sum
            t1 = t1.next
            t3.next = ListNode()
            t3 = t3.next

        while t2:
            sum = t2.val + carry
            if carry:
                carry = 0
            if sum > 9:
                carry = 1
                sum -= 10

            t3.val = sum
            t2 = t2.next
            t3.next = ListNode()
            t3 = t3.next

        if carry:
            t3.val = 1
            carry = 0

        t3 = l3
        while t3.next.next:
            t3 = t3.next
        if t3.next.val == 0:
            t3.next = None

        return l3
```

</details>

<details>
<summary>Day 15: 25. Reverse Nodes in k-Group</summary>

### Problem Statement:

[25 Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) - Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is. You may not alter the values in the list's nodes, only nodes themselves may be changed.

### Solution Code:

```Python
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
```

</details>

<details>
<summary>Day 15: Delete all occurrences of a given key in a doubly linked list</summary>

### Problem Statement:

[Delete all occurrences of a given key in a doubly linked list](https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list) - You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

### Solution Code:

```Python
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
```

</details>

<details>
<summary>Day 15: Find pairs with given sum in doubly linked list</summary>

### Problem Statement:

[Find pairs with given sum in doubly linked list](https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list) - Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

### Solution Code:

```Python
from typing import Optional


from typing import List

"""

Definition for singly Link List Node
class Node:
    def __init__(self,x):
        self.data=x
        self.next=None
        self.prev=None

You can also use the following for printing the link list.
displayList(node)
"""

class Solution:
    def findPairsWithGivenSum(self, target : int, head : Optional['Node']) -> List[List[int]]:
        # code here
        ans = []
        if head.next is None:
            return ans

        p1 = head
        p2 = head

        while p2.next:
            p2 = p2.next

        while p1 is not p2 and p2.next is not p1:
            d1, d2 = p1.data, p2.data

            if (d1 + d2) == target:
                ans.append([d1, d2])
                p1 = p1.next
                p2 = p2.prev
            elif (d1 + d2) < target:
                p1 = p1.next
            else:
                p2 = p2.prev

        return ans
```

</details>

<details>
<summary>Day 15: Remove duplicates from a sorted doubly linked list</summary>

### Problem Statement:

[Remove duplicates from a sorted doubly linked list](https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list) - Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

### Solution Code:

```Python
#Back-end complete function Template for Python 3

'''
# Node Class
        class Node:
            def __init__(self, data):   # data -> value stored in node
                self.data = data
                self.next = None
                self.prev = None
'''
class Solution:
    #Function to remove duplicates from unsorted linked list.
    def removeDuplicates(self, head):
        # code here
        # return head after editing list
        temp = head

        while temp.next:
            if temp.data == temp.next.data:
                temp.next = temp.next.next
            else:
                temp = temp.next

        return head
```

</details>

<details>
<summary>Day 17: 56. Merge Intervals</summary>

### Problem Statement:

[56 Merge Intervals](https://leetcode.com/problems/merge-intervals/) - Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

### Solution Code:

```C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 0; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};
```

</details>
<br>

# Lessons

<details>
<summary>Array</summary>

### Array

An array is a collection of elements, each identified by an index or key. Arrays can store integers, characters, strings, and more!.

### Why Use Arrays?

**Efficient Storage:** Arrays provide an efficient way to store multiple values of the same type. This helps in managing and organizing data effectively.

**Easy Access to Elements:** Accessing elements in an array is straightforward and fast. Retrieve any value directly by its position using a unique index.

**Ideal for Iteration and Manipulation:** Perfect for iterating through elements and performing bulk operations. Arrays provide a simple way to handle large datasets efficiently.

### Sorting Algorithms

1. Bubble Sort

   1. Description: Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
   2. Time Complexity: O(n^2)
   3. Space Complexity: 0(1)

2. Selection Sort

   1. Description: Divides the list into two parts: the sorted part at the left end and the unsorted part at the right end. Repeatedly selects the smallest (or largest, depending on sorting order) element from the unsorted part and swaps it with the leftmost unsorted element, moving the boundary between sorted and unsorted parts one element to the right
   2. Time Complexity: O(n^2)
   3. Space Complexity: O(1)

3. Insertion Sort

   1. Description: Builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
   2. Time Complexity: O(n^2)
   3. Space Complexity: O(1)

</details>

<!-- <details>
<summary></summary>
</details>

<details>
<summary></summary>
</details> -->

_Work in progress..._
