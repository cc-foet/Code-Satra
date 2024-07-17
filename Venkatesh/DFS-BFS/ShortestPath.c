#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 5
#define MAX_PATH_LENGTH 100

typedef struct Node {
    char *vertex;
    struct Node *next;
} Node;

typedef struct Queue {
    char **path;
    int path_length;
    struct Queue *next;
} Queue;

void enqueue(Queue **head, char **path, int path_length) {
    Queue *new_node = (Queue *)malloc(sizeof(Queue));
    new_node->path = (char **)malloc(path_length * sizeof(char *));
    for (int i = 0; i < path_length; ++i) {
        new_node->path[i] = strdup(path[i]);
    }
    new_node->path_length = path_length;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Queue *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

char **dequeue(Queue **head, int *path_length) {
    if (*head == NULL) {
        return NULL;
    }

    Queue *temp = *head;
    *head = (*head)->next;

    char **path = temp->path;
    *path_length = temp->path_length;
    free(temp);

    return path;
}

int is_empty(Queue *head) {
    return head == NULL;
}

int contains(char **path, int path_length, const char *vertex) {
    for (int i = 0; i < path_length; ++i) {
        if (strcmp(path[i], vertex) == 0) {
            return 1;
        }
    }
    return 0;
}

char **shortest_path(char *graph[MAX_NODES][MAX_NODES], int nodes_count, const char *start, const char *end) {
    Queue *queue = NULL;
    char **initial_path = (char **)malloc(sizeof(char *));
    initial_path[0] = strdup(start);
    enqueue(&queue, initial_path, 1);
    free(initial_path);

    char **shortest = NULL;
    int shortest_length = 0;

    while (!is_empty(queue)) {
        int path_length;
        char **path = dequeue(&queue, &path_length);
        char *vertex = path[path_length - 1];

        for (int i = 0; i < nodes_count; ++i) {
            if (graph[vertex[0] - 'A'][i] != NULL && !contains(path, path_length, graph[vertex[0] - 'A'][i])) {
                char **new_path = (char **)malloc((path_length + 1) * sizeof(char *));
                for (int j = 0; j < path_length; ++j) {
                    new_path[j] = strdup(path[j]);
                }
                new_path[path_length] = strdup(graph[vertex[0] - 'A'][i]);

                if (strcmp(graph[vertex[0] - 'A'][i], end) == 0) {
                    if (shortest == NULL || path_length + 1 < shortest_length) {
                        if (shortest != NULL) {
                            for (int j = 0; j < shortest_length; ++j) {
                                free(shortest[j]);
                            }
                            free(shortest);
                        }
                        shortest = new_path;
                        shortest_length = path_length + 1;
                    } else {
                        for (int j = 0; j <= path_length; ++j) {
                            free(new_path[j]);
                        }
                        free(new_path);
                    }
                } else {
                    enqueue(&queue, new_path, path_length + 1);
                    for (int j = 0; j <= path_length; ++j) {
                        free(new_path[j]);
                    }
                    free(new_path);
                }
            }
        }

        for (int i = 0; i < path_length; ++i) {
            free(path[i]);
        }
        free(path);
    }

    return shortest;
}

void main() {
    char *nodes[] = {"A", "B", "C", "D", "E"};
    char *edges[][2] = {{"A", "B"}, {"A", "C"}, {"B", "D"}, {"C", "E"}, {"D", "E"}};
    int nodes_count = 5;
    int edges_count = 5;
    char *start_node = "A";
    char *end_node = "E";

    char *graph[MAX_NODES][MAX_NODES] = {NULL};

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = NULL;
        }
    }

    for (int i = 0; i < edges_count; ++i) {
        int start_idx = edges[i][0][0] - 'A';
        int end_idx = edges[i][1][0] - 'A';
        graph[start_idx][end_idx] = edges[i][1];
    }

    char **path = shortest_path(graph, nodes_count, start_node, end_node);
    if (path != NULL) {
        for (int i = 0; path[i] != NULL; ++i) {
            printf("%s ", path[i]);
            free(path[i]);
        }
        free(path);
        printf("\n");
    }
}
