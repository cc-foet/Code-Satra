def find_cycle(vertices, edges):
    from collections import defaultdict

    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)

    visited = {v: False for v in vertices}
    rec_stack = {v: False for v in vertices}

    def dfs(v, path):
        visited[v] = True
        rec_stack[v] = True
        path.append(v)

        for neighbor in graph[v]:
            if not visited[neighbor]:
                result = dfs(neighbor, path)
                if result:
                    return result
            elif rec_stack[neighbor]:
                # Cycle detected, extract the cycle
                cycle_start_index = path.index(neighbor)
                return path[cycle_start_index:] + [neighbor]

        rec_stack[v] = False
        path.pop()
        return None

    for vertex in vertices:
        if not visited[vertex]:
            path = []
            result = dfs(vertex, path)
            if result:
                return result

    return False

vertices = ['A', 'B', 'C', 'D']
edges = [('A', 'B'), ('B', 'C'), ('C', 'A'), ('C', 'D')]

cycle = find_cycle(vertices, edges)
