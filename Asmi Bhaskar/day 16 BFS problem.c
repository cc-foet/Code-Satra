#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define INF 1000000

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
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, char start, char end) {
    int startIndex = getIndex(graph, start);
    int endIndex = getIndex(graph, end);
    graph->adjMatrix[startIndex][endIndex] = 1;
    graph->adjMatrix[endIndex][startIndex] = 1;  
}

void printPath(int parent[], int j, Graph* graph) {
    if (parent[j] == -1) {
        printf("%c", graph->vertices[j]);
        return;
    }
    printPath(parent, parent[j], graph);
    printf(" -> %c", graph->vertices[j]);
}

void bfsShortestPath(Graph* graph, char start, char target) {
    int startIndex = getIndex(graph, start);
    int targetIndex = getIndex(graph, target);
    int visited[MAX_VERTICES] = {0};
    int distance[MAX_VERTICES];
    int parent[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }

    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startIndex] = 1;
    distance[startIndex] = 0;
    queue[rear++] = startIndex;

    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[current][i] && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[current] + 1;
                parent[i] = current;
                queue[rear++] = i;

                if (i == targetIndex) {
                    printf("Shortest path length is %d\n", distance[i]);
                    printf("Path is: ");
                    printPath(parent, i, graph);
                    printf("\n");
                    return;
                }
            }
        }
    }

    printf("No path found from %c to %c\n", start, target);
}

int main() {
    Graph graph;
    char* vertices[] = {"A", "B", "C", "D", "E"};
    int vertexCount = 5;
    initGraph(&graph, vertices, vertexCount);

    addEdge(&graph, 'A', 'B');
    addEdge(&graph, 'A', 'C');
    addEdge(&graph, 'B', 'D');
    addEdge(&graph, 'C', 'E');
    addEdge(&graph, 'D', 'E');

    char start = 'A';
    char target = 'E';

    bfsShortestPath(&graph, start, target);

    return 0;
}
