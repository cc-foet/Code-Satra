def floyd_warshall(graph):
    n = len(graph)
    dist = [row[:] for row in graph]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf') and dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    return dist

graph = [
    [0, 4, float('inf'), 5, float('inf')],
    [float('inf'), 0, 1, float('inf'), 6],
    [2, float('inf'), 0, 3, float('inf')],
    [float('inf'), float('inf'), 1, 0, 2],
    [1, float('inf'), float('inf'), 4, 0]
]

result = floyd_warshall(graph)

for row in result:
    print(row)
