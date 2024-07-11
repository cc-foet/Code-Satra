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