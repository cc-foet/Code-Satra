#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_idx;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_idx = v;
    return min_idx;
}

void printPath(int parent[], int v) {
    if (parent[v] == -1) return;

    printPath(parent, parent[v]);
    printf(" %d", v);
}

void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\t\tDistance\t\tPath");
    for (int v = 0; v < V; v++)
        if (v != src) {
            printf("\n%d->%d\t\t%d\t\t%d", src, v, dist[v], src);
            printPath(parent, v);
        }
    printf("\n");
}

void dijikstra(int graph[V][V], int src, int end) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int v = 0; v < V; v++)
        dist[v] = INT_MAX, sptSet[v] = false, parent[v] = -1;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v]
            && dist[u] != INT_MAX
            && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src);

    printf("\nShortest path from %d to %d\n", src, end);
    printf("%d", src);
    printPath(parent, end);
    printf("\nDistance = %d\n", dist[end]);
}

int main() {
    int graph[V][V] = {
        {0, 4, 1, 0, 0},
        {0, 0, 2, 5, 0},
        {0, 0, 0, 8, 10},
        {0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0}
    };

    int start = 0;
    int end = 4;
    dijikstra(graph, start, end);

    return 0;
}
