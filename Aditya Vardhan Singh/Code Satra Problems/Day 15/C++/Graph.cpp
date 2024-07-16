#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

bool dfs(const string& node, const unordered_map<string, vector<string>>& graph, unordered_set<string>& visited, unordered_set<string>& recStack, vector<string>& path, vector<string>& cycle) {
    visited.insert(node);
    recStack.insert(node);
    path.push_back(node);

    for (const string& neighbor : graph.at(node)) {
        if (visited.find(neighbor) == visited.end()) {
            if (dfs(neighbor, graph, visited, recStack, path, cycle)) {
                return true;
            }
        } else if (recStack.find(neighbor) != recStack.end()) {
            // Cycle detected
            auto it = find(path.begin(), path.end(), neighbor);
            cycle.insert(cycle.end(), it, path.end());
            cycle.push_back(neighbor);
            return true;
        }
    }

    recStack.erase(node);
    path.pop_back();
    return false;
}

vector<string> findCycle(const vector<string>& vertices, const vector<pair<string, string>>& edges) {
    unordered_map<string, vector<string>> graph;
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
    }

    unordered_set<string> visited;
    unordered_set<string> recStack;
    vector<string> path;
    vector<string> cycle;

    for (const auto& vertex : vertices) {
        if (visited.find(vertex) == visited.end()) {
            if (dfs(vertex, graph, visited, recStack, path, cycle)) {
                return cycle;
            }
        }
    }

    return {};
}

int main() {
    vector<string> vertices = {"A", "B", "C", "D"};
    vector<pair<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "A"}, {"C", "D"}};

    vector<string> cycle = findCycle(vertices, edges);
    
    if (!cycle.empty()) {
        for (const string& node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    return 0;
}
