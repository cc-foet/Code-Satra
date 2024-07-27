class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1

def are_connected(n, connections, query):
    dsu = DisjointSetUnion(n)
    for x, y in connections:
        dsu.union(x, y)
    return dsu.find(query[0]) == dsu.find(query[1])                

n = 5
connections = [(0, 2), (4, 2), (3, 1)]
query = (4, 0)

print(are_connected(n, connections, query))