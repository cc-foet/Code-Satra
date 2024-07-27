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