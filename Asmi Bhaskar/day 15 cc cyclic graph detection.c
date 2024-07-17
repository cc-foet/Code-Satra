#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

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
}

int dfsCycleUtil(Graph* graph, int v, int visited[], int recStack[], int parent[]) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[v][i]) {
                if (!visited[i]) {
                    parent[i] = v;
                    if (dfsCycleUtil(graph, i, visited, recStack, parent)) {
                        return 1;
                    }
                } else if (recStack[i]) {
                    parent[i] = v;
                    return 1;
                }
            }
        }
    }
    recStack[v] = 0;
    return 0;
}

int detectCycle(Graph* graph, char cycle[]) {
    int visited[MAX_VERTICES] = {0};
    int recStack[MAX_VERTICES] = {0};
    int parent[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        parent[i] = -1;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (dfsCycleUtil(graph, i, visited, recStack, parent)) {
            int cycleStart = -1;
            for (int j = 0; j < graph->numVertices; j++) {
                if (recStack[j]) {
                    cycleStart = j;
                    break;
                }
            }

            int k = 0;
            int cycleNode = cycleStart;
            while (1) {
                cycle[k++] = graph->vertices[cycleNode];
                cycleNode = parent[cycleNode];
                if (cycleNode == cycleStart) {
                    cycle[k++] = graph->vertices[cycleStart];
                    break;
                }
            }
            cycle[k] = '\0';
            return 1;
        }
    }
    return 0;
}

int main() {
    Graph graph;
    char* vertices[] = {"A", "B", "C", "D"};
    int vertexCount = 4;
    initGraph(&graph, vertices, vertexCount);

    addEdge(&graph, 'A', 'B');
    addEdge(&graph, 'B', 'C');
    addEdge(&graph, 'C', 'A');
    addEdge(&graph, 'C', 'D');

    char cycle[MAX_VERTICES];
    if (detectCycle(&graph, cycle)) {
        printf("Cycle detected: %s\n", cycle);
    } else {
        printf("No cycle detected\n");
    }

    return 0;
}
