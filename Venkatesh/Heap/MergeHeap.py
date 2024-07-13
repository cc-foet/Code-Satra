class Node:
    data = 0
    i = 0
    j = 0

    def __init__(self, data, i, j):
        self.data = data
        self.i = i
        self.j = j

class Min_Heap:
    heap_arr = None

    heap_size = 0

    def __init__(self, a, size):
        self.heap_arr = a
        self.heap_size = size
        i = int((self.heap_size - 1) / 2)
        while i >= 0:
            self.min_heapify(i)
            i -= 1
    
    def min_heapify(self, i):
        l = 2 * i + 1
        r = 2 * i + 2
        smallest = i
        if l < self.heap_size and self.heap_arr[l].data < self.heap_arr[i].data:
            smallest = l
        if r < self.heap_size and self.heap_arr[r].data < self.heap_arr[smallest].data:
            smallest = r
        if smallest != i:
            self.heap_arr[i], self.heap_arr[smallest] = self.heap_arr[smallest], self.heap_arr[i]
            self.min_heapify(smallest)
    
    def get_root(self):
        if self.heap_size <= 0:
            return None
        return self.heap_arr[0]
    
    def replace_root(self, root):
        self.heap_arr[0] = root
        self.min_heapify(0)

    def swap(self, x, y):
        self.heap_arr[x], self.heap_arr[y] = self.heap_arr[y], self.heap_arr[x]
    
    @staticmethod
    def merge_sorted(arr, k):
        heap_arr = [None] * k
        result_size = 0
        i = 0
        while i < k:
            node = Node(arr[i][0], i, 1)
            heap_arr[i] = node
            result_size += len(arr[i])
            i += 1

        min_heap = Min_Heap(heap_arr, k)
        result = [0] * result_size

        i = 0
        while i < result_size:
            root = min_heap.get_root()
            result[i] = root.data
            if root.j < len(arr[root.i]):
                root.data = arr[root.i][root.j]
                root.j += 1
            else:
                root.data = float('inf')
            min_heap.replace_root(root)
            i += 1
        return result


k = 3
n = 4
arr = [[1, 3, 5, 7], [2, 4, 6, 8], [0, 9, 10, 11]]

print(Min_Heap.merge_sorted(arr, k))