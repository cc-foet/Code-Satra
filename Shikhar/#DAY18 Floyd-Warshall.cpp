#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // Representing infinity

// Function to apply the Floyd-Warshall algorithm
vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;  // Initialize distance matrix

    // Main loop of Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}

int main() {
    // Define the graph
    vector<vector<int>> graph = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

    // Compute shortest paths
    vector<vector<int>> shortestPaths = floydWarshall(graph);

    // Print the result
    cout << "Shortest paths between all pairs of nodes:" << endl;
    for (const auto& row : shortestPaths) {
        for (int dist : row) {
            if (dist == INF) {
                cout << "INF ";
            } else {
                cout << dist << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
