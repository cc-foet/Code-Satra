#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

// Function to implement Dijkstra's algorithm using a set
void dijkstra(unordered_map<string, unordered_map<string, int>> &graph, string start, string end) {
    unordered_map<string, int> distances;
    unordered_map<string, string> previous;
    set<pair<int, string>> nodes;

    for (auto &node : graph) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;
    nodes.insert({0, start});

    while (!nodes.empty()) {
        auto top = *(nodes.begin());
        nodes.erase(nodes.begin());

        int current_distance = top.first;
        string current_node = top.second;

        for (auto &neighbor : graph[current_node]) {
            string next_node = neighbor.first;
            int edge_weight = neighbor.second;
            int new_distance = current_distance + edge_weight;

            if (new_distance < distances[next_node]) {
                if (distances[next_node] != INT_MAX) {
                    nodes.erase(nodes.find({distances[next_node], next_node}));
                }
                distances[next_node] = new_distance;
                previous[next_node] = current_node;
                nodes.insert({new_distance, next_node});
            }
        }
    }

    // Reconstruct the shortest path
    vector<string> path;
    for (string at = end; at != ""; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    // Print the shortest path and distance
    cout << "Shortest Path: ";
    for (const string &node : path) {
        cout << node << " ";
    }
    cout << "\nDistance: " << distances[end] << endl;
}

int main() {
    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 4}, {"C", 1}}},
        {"B", {{"C", 2}, {"D", 5}}},
        {"C", {{"D", 8}, {"E", 10}}},
        {"D", {{"E", 2}}},
        {"E", {}}
    };

    string start = "A";
    string end = "E";

    dijkstra(graph, start, end);

    return 0;
}
