def sequence(dependencies, n):
    graph = [[] for _ in range(n)]
    indegree = [0] * n
    
    for u, v in dependencies:
        graph[u].append(v)
        indegree[v] += 1

    queue = []
    for i in range(n):
        if indegree[i] == 0:
            queue.append(i)
    result = []

    while queue:
        u = queue.pop(0)
        result.append(u)
        for v in graph[u]:
            indegree[v] -= 1
            if indegree[v] == 0:
                queue.append(v)

    return result

n = 6
dependencies = [(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)]

print(sequence(dependencies, n))