import heapq

def prim(graph, n):
    mst = []
    visited = [False] * n
    min_heap = [(0, 0, 0)]
    edges = {i: [] for i in range(n)}

    for u, v, weight in graph:
        edges[u].append((weight, v))
        edges[v].append((weight, u))

    while len(mst) < n - 1:
        weight, u, v = heapq.heappop(min_heap)
        if visited[v]:
            continue
        visited[v] = True
        if u != v:
            mst.append((u, v, weight))

        for w, next_vertex in edges[v]:
            if not visited[next_vertex]:
                heapq.heappush(min_heap, (w, v, next_vertex))

    return mst

graph = [(0, 1, 2), (1, 2, 3), (0, 3, 6), (1, 3, 8), (1, 4, 5), (2, 4, 7)]
n = 5

print(prim(graph, n))
