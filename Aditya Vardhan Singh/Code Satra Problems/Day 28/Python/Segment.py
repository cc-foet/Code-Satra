class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.data = data
        self.tree_max = [0] * (4 * self.n)
        self.tree_sum = [0] * (4 * self.n)
        self._build(0, 0, self.n - 1)
    
    def _build(self, node, start, end):
        if start == end:
            self.tree_max[node] = self.data[start]
            self.tree_sum[node] = self.data[start]
        else:
            mid = (start + end) // 2
            self._build(2 * node + 1, start, mid)
            self._build(2 * node + 2, mid + 1, end)
            self.tree_max[node] = max(self.tree_max[2 * node + 1], self.tree_max[2 * node + 2])
            self.tree_sum[node] = self.tree_sum[2 * node + 1] + self.tree_sum[2 * node + 2]
    
    def query_max(self, l, r):
        return self._query_max(0, 0, self.n - 1, l, r)
    
    def query_sum(self, l, r):
        return self._query_sum(0, 0, self.n - 1, l, r)
    
    def _query_max(self, node, start, end, l, r):
        if r < start or l > end:
            return -float('inf')
        if l <= start and end <= r:
            return self.tree_max[node]
        mid = (start + end) // 2
        left_max = self._query_max(2 * node + 1, start, mid, l, r)
        right_max = self._query_max(2 * node + 2, mid + 1, end, l, r)
        return max(left_max, right_max)
    
    def _query_sum(self, node, start, end, l, r):
        if r < start or l > end:
            return 0
        if l <= start and end <= r:
            return self.tree_sum[node]
        mid = (start + end) // 2
        left_sum = self._query_sum(2 * node + 1, start, mid, l, r)
        right_sum = self._query_sum(2 * node + 2, mid + 1, end, l, r)
        return left_sum + right_sum

def longest_subarray_with_k_increments(arr, K):
    st = SegmentTree(arr)
    n = len(arr)
    max_length = 0
    left = 0
    
    for right in range(n):
        max_val = st.query_max(left, right)
        total_sum = st.query_sum(left, right)
        increments_needed = (max_val * (right - left + 1)) - total_sum
        
        while increments_needed > K:
            left += 1
            max_val = st.query_max(left, right)
            total_sum = st.query_sum(left, right)
            increments_needed = (max_val * (right - left + 1)) - total_sum
        
        max_length = max(max_length, right - left + 1)
    
    return max_length

arr = [2, 0, 4, 6, 7]
K = 6
print(longest_subarray_with_k_increments(arr, K))
