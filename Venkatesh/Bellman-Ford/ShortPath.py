def bellman_ford(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    predecessors = {node: None for node in graph}

    for _ in range(len(graph) - 1):
        for node in graph:
            for neighbor, weight in graph[node].items():
                if distances[node] + weight < distances[neighbor]:
                    distances[neighbor] = distances[node] + weight
                    predecessors[neighbor] = node

    return distances

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