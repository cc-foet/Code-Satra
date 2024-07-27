#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* parent;
    int* rank;
    int size;
} DisjointSetUnion;

DisjointSetUnion* createDSU(int n) {
    DisjointSetUnion* dsu = (DisjointSetUnion*)malloc(sizeof(DisjointSetUnion));
    dsu->parent = (int*)malloc(n * sizeof(int));
    dsu->rank = (int*)malloc(n * sizeof(int));
    dsu->size = n;
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
    return dsu;
}

int find(DisjointSetUnion* dsu, int x) {
    if (dsu->parent[x] != x) {
        dsu->parent[x] = find(dsu, dsu->parent[x]);
    }
    return dsu->parent[x];
}

void unionSets(DisjointSetUnion* dsu, int x, int y) {
    int xRoot = find(dsu, x);
    int yRoot = find(dsu, y);
    if (xRoot == yRoot) {
        return;
    }
    if (dsu->rank[xRoot] < dsu->rank[yRoot]) {
        dsu->parent[xRoot] = yRoot;
    } else if (dsu->rank[xRoot] > dsu->rank[yRoot]) {
        dsu->parent[yRoot] = xRoot;
    } else {
        dsu->parent[yRoot] = xRoot;
        dsu->rank[xRoot]++;
    }
}

bool areConnected(int connections[][2], int connectionsNum, int query[2], int n) {
    DisjointSetUnion* dsu = createDSU(n);
    for (int i = 0; i < connectionsNum; i++) {
        unionSets(dsu, connections[i][0], connections[i][1]);
    }
    bool result = find(dsu, query[0]) == find(dsu, query[1]);
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
    return result;
}

int main() {
    int n = 5;
    int connections[][2] = {{0, 2}, {4, 2}, {3, 1}};
    int connectionsNum = sizeof(connections) / sizeof(connections[0]);
    int query[] = {4, 0};

    if (areConnected(connections, connectionsNum, query, n)) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}