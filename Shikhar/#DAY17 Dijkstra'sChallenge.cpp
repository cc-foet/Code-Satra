// Solved the problem challenge on Dijkstra's algorithm

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>

using namespace std;

// Function to find the shortest path using Dijkstra's Algorithm
pair<vector<string>, int> dijkstra(unordered_map<string, unordered_map<string, int>>& graph, string start, string end) {
    unordered_map<string, int> distances;
    unordered_map<string, string> parent;
    for (auto& node : graph) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;

    auto compare = [&distances](string left, string right) { return distances[left] > distances[right]; };
    priority_queue<string, vector<string>, decltype(compare)> pq(compare);
    pq.push(start);

    while (!pq.empty()) {
        string current = pq.top();
        pq.pop();

        if (current == end) break;

        for (auto& neighbor : graph[current]) {
            int newDist = distances[current] + neighbor.second;
            if (newDist < distances[neighbor.first]) {
                distances[neighbor.first] = newDist;
                parent[neighbor.first] = current;
                pq.push(neighbor.first);
            }
        }
    }

    vector<string> path;
    int distance = distances[end];
    if (distance == numeric_limits<int>::max()) {
        return {{}, -1};  // Return empty path and -1 if no path found
    }

    for (string at = end; at != ""; at = parent[at]) {
        path.push_back(at);
        if (at == start) break;
    }
    reverse(path.begin(), path.end());

    return {path, distance};
}

int main() {
    // Define the graph
    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 4}, {"C", 1}}},
        {"B", {{"C", 2}, {"D", 5}}},
        {"C", {{"D", 8}, {"E", 10}}},
        {"D", {{"E", 2}}},
        {"E", {}}
    };
    string start = "A";
    string end = "E";

    // Find the shortest path and distance
    pair<vector<string>, int> result = dijkstra(graph, start, end);
    vector<string> path = result.first;
    int distance = result.second;

    // Print the result
    if (!path.empty() && distance != -1) {
        cout << "Shortest Path: ";
        for (string& node : path) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Distance: " << distance << endl;
    } else {
        cout << "No path found from " << start << " to " << end << endl;
    }

    return 0;
}