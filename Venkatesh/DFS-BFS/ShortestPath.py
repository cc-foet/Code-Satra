def shortest_path(graph, start, end):
    queue = [(start, [start])]
    shortest = None
    while queue:
        (vertex, path) = queue.pop(0)
        for next in set(graph[vertex]) - set(path):
            if next == end:
                if shortest is None or len(path) + 1 < len(shortest):
                    shortest = path + [next]
            else:
                queue.append((next, path + [next]))
    return shortest

nodes = ['A', 'B', 'C', 'D', 'E']
edges = [('A', 'B'), ('A', 'C'), ('B', 'D'), ('C', 'E'), ('D', 'E')]
start_node = 'A'
end_node = 'E'

graph = {node: set() for node in nodes}
for start_edge, end_edge in edges:
    graph[start_edge].add(end_edge)

print(shortest_path(graph, start_node, end_node))