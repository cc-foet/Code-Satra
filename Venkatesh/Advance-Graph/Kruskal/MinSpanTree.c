#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

void kruskal(int graph[][3], int n) {
    struct Edge result[n];
    int e = 0;
    int i = 0;

    qsort(graph, n, sizeof(struct Edge), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(n * sizeof(struct Subset));

    for (int v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < n - 1 && i < n) {
        struct Edge nextEdge = *((struct Edge*)(&graph[i++]));

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    for (i = 0; i < e; i++) {
        printf("[%d, %d, %d]", result[i].src, result[i].dest, result[i].weight);
        if (i < e - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(subsets);
}

void main() {
    int graph[][3] = {{0, 1, 2}, {1, 2, 3}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};
    int n = 5;

    kruskal(graph, n);
}