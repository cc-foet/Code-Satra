def shortest_path(graph):
    n = len(graph)
    for i in range(n):
        for j in range(n):
            for k in range(n):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    return graph

INF = float('inf')
graph = [[0, 4, INF, 5, INF],
         [INF, 0, 1, INF, 6],
         [2, INF, 0, 3, INF],
         [INF, INF, 1, 0, 2],
         [1, INF, INF, 4, 0]]

dist = shortest_path(graph)
for row in dist:
    print(row)