#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
#define INF INT_MAX

void bellman_ford(int graph[V][V], int start) {
    int distances[V];
    for (int i = 0; i < V; i++)
        distances[i] = INF;
    distances[start] = 0;

    for (int i = 1; i < V; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != INF && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                printf("Graph contains a negative-weight cycle\n");
                return;
            }
        }
    }

    for (int i = 0; i < V; i++)
        printf("Distance from node %d to node %d is %d\n", start, i, distances[i]);
}

int main() {
    int graph[V][V] = {
        {0, 4, 1, INF, INF},
        {INF, 0, -2, 5, INF},
        {INF, INF, 0, 2, 4},
        {INF, INF, INF, 0, -3},
        {INF, INF, INF, INF, 0}
    };

    int start = 0;
    bellman_ford(graph, start);

    return 0;
}
