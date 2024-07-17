#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to find the shortest path in an unweighted graph using BFS
vector<string> findShortestPath(vector<string>& vertices, vector<pair<string, string>>& edges, string start, string target) {
    unordered_map<string, vector<string>> graph;
    for (auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);  // Because the graph is undirected
    }

    unordered_map<string, string> parent;
    queue<string> q;
    q.push(start);
    parent[start] = "";

    while (!q.empty()) {
        string node = q.front();
        q.pop();

        if (node == target) {
            vector<string> path;
            for (string at = target; at != ""; at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (string& neighbor : graph[node]) {
            if (parent.find(neighbor) == parent.end()) {
                q.push(neighbor);
                parent[neighbor] = node;
            }
        }
    }

    return {}; // Return empty if no path found
}

int main() {
    // Define the vertices and edges of the graph
    vector<string> vertices = {"A", "B", "C", "D", "E"};
    vector<pair<string, string>> edges = {{"A", "B"}, {"A", "C"}, {"B", "D"}, {"C", "E"}, {"D", "E"}};
    string start = "A";
    string target = "E";

    vector<string> path = findShortestPath(vertices, edges, start, target);

    if (!path.empty()) {
        cout << "Shortest path: ";
        for (string& node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << target << endl;
    }

    return 0;
}
