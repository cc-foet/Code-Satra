import heapq

def dijkstra(graph, start, end):
    shortest = {node: float('inf') for node in graph}
    shortest[start] = 0
    prev = {}
    pq = [(0, start)]

    while pq:
        curr_distance, curr_node = heapq.heappop(pq)

        if curr_node == end:
            break

        for neighbor, weight in graph[curr_node].items():
            distance = curr_distance + weight
            if distance < shortest[neighbor]:
                shortest[neighbor] = distance
                prev[neighbor] = curr_node
                heapq.heappush(pq, (distance, neighbor))

        path = []
    curr_node = end
    while curr_node != start:
        if curr_node in prev:
            path.insert(0, curr_node)
            curr_node = prev[curr_node]
        else:
            print('Path not reachable')
            return
    path.insert(0, start)

    if shortest[end] != float('inf'):
        print('Shortest Path: ', path)
        print("Distance:", shortest[end])

graph = {'A': {'B':4,'C':1},
         'B': {'C':2,'D':5},
         'C': {'D':8, 'E':10},
         'D': {'E':2},
         'E': {}}
start = 'A'
end = 'E'

dijkstra(graph, start, end)