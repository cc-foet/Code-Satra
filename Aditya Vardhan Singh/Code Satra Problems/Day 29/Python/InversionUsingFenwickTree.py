class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)
    
    def update(self, index, delta):
        while index <= self.size:
            self.tree[index] += delta
            index += index & -index
    
    def query(self, index):
        sum_ = 0
        while index > 0:
            sum_ += self.tree[index]
            index -= index & -index
        return sum_

def count_inversions(arr):
    sorted_arr = sorted(set(arr))
    rank = {value: idx + 1 for idx, value in enumerate(sorted_arr)}
    
    fenwick_tree = FenwickTree(len(rank))
    
    inversions = 0
    for num in reversed(arr):
        index = rank[num]
        inversions += fenwick_tree.query(index - 1)
        fenwick_tree.update(index, 1)
    
    return inversions

arr = [8, 4, 2, 1]
print(count_inversions(arr))
