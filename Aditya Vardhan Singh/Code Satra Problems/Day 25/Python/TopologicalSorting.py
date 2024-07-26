from collections import deque, defaultdict

def find_task_order(N, dependencies):
    # Represent the graph
    graph = defaultdict(list)
    in_degree = [0] * N

    # Fill graph and in-degree array
    for a, b in dependencies:
        graph[a].append(b)
        in_degree[b] += 1

    # Init a queue with all tasks that have an in-degree of zero
    queue = deque([i for i in range(N) if in_degree[i] == 0])
    result = []

    # Process the queue
    while queue:
        node = queue.popleft()
        result.append(node)

        for neighbor in graph[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)

    # Check if topological sort is possible
    if len(result) == N:
        return result
    else:
        return []

N = 6
dependencies = [(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)]
print(find_task_order(N, dependencies))
