def cyclic(graph):
    def dfs(node, visited, path):
        if node in visited:
            start_index = path.index(node)
            cycle = path[start_index:]
            cycle.append(node)
            return cycle
        visited.add(node)
        path.append(node)
        for neighbour in graph.get(node, []):
            cycle = dfs(neighbour, visited, path)
            if cycle:
                return cycle
            path.pop()
            return False
        
    for node in graph:
        cycle = dfs(node, set(), [])
        if cycle:
            return cycle
    return False

    

nodes = ['A', 'B', 'C', 'D']
edges = [('A', 'B'), ('B', 'C'), ('C', 'A'), ('C', 'D')]

graph = {node: [] for node in nodes}
for start, end in edges:
    graph[start].append(end)
print(cyclic(graph))