#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    char node;
    char neighbors[MAX_NODES];
    int neighbor_count;
} Node;

Node graph[MAX_NODES];
int graph_size = 0;

Node* get_node(char node) {
    for (int i = 0; i < graph_size; i++) {
        if (graph[i].node == node) {
            return &graph[i];
        }
    }
    return NULL;
}

void add_edge(char start, char end) {
    Node* start_node = get_node(start);
    if (start_node == NULL) {
        start_node = &graph[graph_size++];
        start_node->node = start;
        start_node->neighbor_count = 0;
    }
    start_node->neighbors[start_node->neighbor_count++] = end;
}

int index_of(char* array, int size, char value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

char* dfs(char node, char* visited, int* visited_count, char* path, int* path_count) {
    if (index_of(visited, *visited_count, node) != -1) {
        int start_index = index_of(path, *path_count, node);
        char* cycle = (char*)malloc((*path_count - start_index + 2) * sizeof(char));
        int cycle_length = 0;
        for (int i = start_index; i < *path_count; i++) {
            cycle[cycle_length++] = path[i];
        }
        cycle[cycle_length++] = node;
        cycle[cycle_length] = '\0';
        return cycle;
    }
    visited[(*visited_count)++] = node;
    path[(*path_count)++] = node;
    Node* current_node = get_node(node);
    if (current_node != NULL) {
        for (int i = 0; i < current_node->neighbor_count; i++) {
            char* cycle = dfs(current_node->neighbors[i], visited, visited_count, path, path_count);
            if (cycle != NULL) {
                return cycle;
            }
            (*path_count)--;
        }
    }
    return NULL;
}

char* cyclic() {
    char visited[MAX_NODES];
    int visited_count = 0;
    char path[MAX_NODES];
    int path_count = 0;
    for (int i = 0; i < graph_size; i++) {
        char* cycle = dfs(graph[i].node, visited, &visited_count, path, &path_count);
        if (cycle != NULL) {
            return cycle;
        }
    }
    return NULL;
}

int main() {
    char nodes[] = {'A', 'B', 'C', 'D'};
    int num_nodes = sizeof(nodes) / sizeof(nodes[0]);
    for (int i = 0; i < num_nodes; i++) {
        graph[i].node = nodes[i];
        graph[i].neighbor_count = 0;
    }
    graph_size = num_nodes;

    add_edge('A', 'B');
    add_edge('B', 'C');
    add_edge('C', 'A');
    add_edge('C', 'D');

    char* cycle = cyclic();
    if (cycle != NULL) {
        printf("%s \n", cycle);
        free(cycle);
    } else {
        printf("False");
    }

    return 0;
}
