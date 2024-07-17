// Solved the challenge of Day 15.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

// Function to perform DFS and detect a cycle in the graph
bool dfs(const string& node, unordered_map<string, vector<string>>& graph, unordered_map<string, bool>& visited, unordered_map<string, bool>& recStack, stack<string>& path, vector<string>& cycle) {
    visited[node] = true;
    recStack[node] = true;
    path.push(node);

    for (const string& neighbor : graph[node]) {
        if (!visited[neighbor] && dfs(neighbor, graph, visited, recStack, path, cycle)) {
            return true;
        } else if (recStack[neighbor]) {
            while (!path.empty() && path.top() != neighbor) {
                cycle.push_back(path.top());
                path.pop();
            }
            cycle.push_back(neighbor);
            cycle.push_back(node);
            return true;
        }
    }

    recStack[node] = false;
    path.pop();
    return false;
}

// Function to detect a cycle in the directed graph
vector<string> detectCycle(vector<string>& vertices, vector<pair<string, string>>& edges) {
    unordered_map<string, vector<string>> graph;
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
    }

    unordered_map<string, bool> visited;
    unordered_map<string, bool> recStack;
    stack<string> path;
    vector<string> cycle;

    for (const string& vertex : vertices) {
        if (!visited[vertex]) {
            if (dfs(vertex, graph, visited, recStack, path, cycle)) {
                reverse(cycle.begin(), cycle.end());
                return cycle;
            }
        }
    }

    return {};
}

int main() {
    vector<string> vertices = {"A", "B", "C", "D"};
    vector<pair<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "A"}, {"C", "D"}};

    vector<string> cycle = detectCycle(vertices, edges);

    if (!cycle.empty()) {
        cout << "Cycle detected: ";
        for (const string& node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
