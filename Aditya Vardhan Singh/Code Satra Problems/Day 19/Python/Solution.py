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
