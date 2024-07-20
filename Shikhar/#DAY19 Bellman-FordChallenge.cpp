#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

// Function to find shortest paths using Bellman-Ford Algorithm
unordered_map<string, int> bellmanFord(unordered_map<string, unordered_map<string, int>>& graph, string start) {
    unordered_map<string, int> distances;
    for (auto& node : graph) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;

    int V = graph.size();
    for (int i = 1; i <= V - 1; ++i) {
        for (auto& node : graph) {
            string u = node.first;
            for (auto& neighbor : node.second) {
                string v = neighbor.first;
                int weight = neighbor.second;
                if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (auto& node : graph) {
        string u = node.first;
        for (auto& neighbor : node.second) {
            string v = neighbor.first;
            int weight = neighbor.second;
            if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                cout << "Graph contains a negative weight cycle" << endl;
                return {};
            }
        }
    }

    return distances;
}

int main() {
    // Define the graph
    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 4}, {"C", 1}}},
        {"B", {{"C", -2}, {"D", 5}}},
        {"C", {{"E", 4}, {"D", 2}}},
        {"D", {{"E", -3}}},
        {"E", {}}
    };
    string start = "A";

    // Find the shortest paths
    unordered_map<string, int> distances = bellmanFord(graph, start);

    // Print the result
    if (!distances.empty()) {
        cout << "Shortest distances from " << start << " to all other nodes:" << endl;
        for (auto& pair : distances) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    return 0;
}