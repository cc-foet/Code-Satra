#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    char vertices[MAX_VERTICES];
} Graph;

int getIndex(Graph* graph, char vertex) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

void initGraph(Graph* graph, char* vertices[], int vertexCount) {
    graph->numVertices = vertexCount;
    for (int i = 0; i < vertexCount; i++) {
        graph->vertices[i] = vertices[i][0];
    }
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            graph->adjMatrix[i][j] = INF;
        }
    }
}

void addEdge(Graph* graph, char start, char end, int weight) {
    int startIndex = getIndex(graph, start);
    int endIndex = getIndex(graph, end);
    graph->adjMatrix[startIndex][endIndex] = weight;
}

int minDistance(int dist[], int visited[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j, Graph* graph) {
    if (parent[j] == -1) {
        printf("%c", graph->vertices[j]);
        return;
    }
    printPath(parent, parent[j], graph);
    printf(" -> %c", graph->vertices[j]);
}

void dijkstra(Graph* graph, char start, char target) {
    int V = graph->numVertices;
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    int parent[MAX_VERTICES];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    int startIndex = getIndex(graph, start);
    int targetIndex = getIndex(graph, target);
    dist[startIndex] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph->adjMatrix[u][v] != INF && dist[u] != INF
                && dist[u] + graph->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Shortest path distance from %c to %c is %d\n", start, target, dist[targetIndex]);
    printf("Path is: ");
    printPath(parent, targetIndex, graph);
    printf("\n");
}

int main() {
    Graph graph;
    char* vertices[] = {"A", "B", "C", "D", "E"};
    int vertexCount = 5;
    initGraph(&graph, vertices, vertexCount);

    addEdge(&graph, 'A', 'B', 4);
    addEdge(&graph, 'A', 'C', 1);
    addEdge(&graph, 'B', 'C', 2);
    addEdge(&graph, 'B', 'D', 5);
    addEdge(&graph, 'C', 'D', 8);
    addEdge(&graph, 'C', 'E', 10);
    addEdge(&graph, 'D', 'E', 2);

    char start = 'A';
    char target = 'E';

    dijkstra(&graph, start, target);

    return 0;
}
