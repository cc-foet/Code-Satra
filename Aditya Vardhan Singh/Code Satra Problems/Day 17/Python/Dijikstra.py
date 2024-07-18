from sys import maxsize as INT_MAX

size = 5

def minDistance(dist, sptSet):
    min, min_idx = INT_MAX, 0
    for v in range(size):
        if sptSet[v] is False and dist[v] <= min:
            min, min_idx = dist[v], v
    return min_idx

def printPath(parent, v):
    if (parent[v] == -1): return

    printPath(parent, parent[v])
    print(f' %d' % v, end='')

def printSolution(dist, parent, src):
    print(f'Vertex\t\tDistance\t\tPath', end='')
    for v in range(size):
        if v != src:
            print(f'\n%d->%d\t\t%d\t\t%d' %(src, v, dist[v], src), end='')
            printPath(parent, v)
    print()

def djkistra(graph, src, end):
    dist = [INT_MAX] * size
    sptSet = [False] * size
    parent = [-1] * size

    dist[src] = 0

    for count in range(0, size - 1):
        u = minDistance(dist, sptSet)
        sptSet[u] = True
        for v in range(0, size):
            if sptSet[v] is False and graph[u][v] and dist[u] != INT_MAX and (dist[u] + graph[u][v] < dist[v]):
                dist[v] = dist[u] + graph[u][v]
                parent[v] = u

    printSolution(dist, parent, src)

    print(f'\nShortest path from %d to %d' %(src, end))
    print(src, end='')
    printPath(parent, end)
    print(f'\nDistance = %d' % dist[end])

graph = [
    [0, 4, 1, 0, 0],
    [0, 0, 2, 5, 0],
    [0, 0, 0, 8, 10],
    [0, 0, 0, 0, 2],
    [0, 0, 0, 0, 0]
]

start, end = 0, 4
djkistra(graph, start, end)
