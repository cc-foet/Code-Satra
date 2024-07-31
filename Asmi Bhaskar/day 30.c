#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX], rank[MAX], edge_count = 0;

int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void union_sets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void kruskal(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    qsort(edges, edge_count, sizeof(Edge), compare);
    for (int i = 0; i < edge_count; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            printf("(%d, %d, %d) ", edges[i].u, edges[i].v, edges[i].weight);
            union_sets(edges[i].u, edges[i].v);
        }
    }
    printf("\n");
}

int main() {
    int n = 5;
    edges[0] = (Edge){0, 1, 2};
    edges[1] = (Edge){1, 2, 3};
    edges[2] = (Edge){0, 3, 6};
    edges[3] = (Edge){1, 3, 8};
    edges[4] = (Edge){1, 4, 5};
    edges[5] = (Edge){2, 4, 7};
    edge_count = 6;
    kruskal(n);
    return 0;
}
