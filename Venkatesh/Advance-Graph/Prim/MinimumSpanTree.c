#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

typedef struct {
    Edge *data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    pq->data = (Edge*) malloc(capacity * sizeof(Edge));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(Edge *a, Edge *b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->data[index].weight < pq->data[parent].weight) {
            swap(&pq->data[index], &pq->data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(PriorityQueue *pq, int index) {
    int left, right, smallest;
    while (true) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;
        if (left < pq->size && pq->data[left].weight < pq->data[smallest].weight) {
            smallest = left;
        }
        if (right < pq->size && pq->data[right].weight < pq->data[smallest].weight) {
            smallest = right;
        }
        if (smallest != index) {
            swap(&pq->data[index], &pq->data[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void push(PriorityQueue *pq, Edge edge) {
    if (pq->size == pq->capacity) {
        return;
    }
    pq->data[pq->size] = edge;
    heapifyUp(pq, pq->size);
    pq->size++;
}

Edge pop(PriorityQueue *pq) {
    if (pq->size == 0) {
        Edge e = { -1, -1, -1 };
        return e;
    }
    Edge min = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return min;
}

void prim(int graph[][3], int edges, int n, int result[][3]) {
    bool visited[MAX] = { false };
    PriorityQueue *pq = createQueue(edges);
    int count = 0;
    push(pq, (Edge) { 0, 0, 0 });

    while (pq->size > 0 && count < n - 1) {
        Edge minEdge = pop(pq);
        int u = minEdge.end;
        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        if (minEdge.start != minEdge.end) {
            result[count][0] = minEdge.start;
            result[count][1] = minEdge.end;
            result[count][2] = minEdge.weight;
            count++;
        }

        for (int i = 0; i < edges; i++) {
            if (graph[i][0] == u && !visited[graph[i][1]]) {
                push(pq, (Edge) { graph[i][0], graph[i][1], graph[i][2] });
            } else if (graph[i][1] == u && !visited[graph[i][0]]) {
                push(pq, (Edge) { graph[i][1], graph[i][0], graph[i][2] });
            }
        }
    }
    free(pq->data);
    free(pq);
}

void main() {
    int graph[][3] = {{0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};
    int n = 5;
    int edges = sizeof(graph) / sizeof(graph[0]);
    int result[MAX][3];
    
    prim(graph, edges, n, result);

    printf("[");
    for (int i = 0; i < n - 1; i++) {
        printf("[%d, %d, %d]", result[i][0], result[i][1], result[i][2]);
        if (i < n - 2) {
            printf(", ");
        }
    }
    printf("]\n");
}