#include <map>
#include <vector>
#include <deque>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<char> bfs_shortest_path(map<char, vector<char>>& graph, char start, char target) {
    deque<vector<char>> queue = {{start}};
    unordered_set<char> visited = {};
    vector<char> path;

    while (!queue.empty()) {
        path = queue.front();
        queue.pop_front();
        char node = path[path.size()-1];

        if (node == target) {
            return path;
        }

        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (auto neighbor : graph[node]) {
                vector<char> new_path = path;
                new_path.push_back(neighbor);
                queue.push_back(new_path);
            }
        }
    }

    return path;
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D'}},
        {'C', {'E'}},
        {'D', {'E'}},
        {'E', {}}
    };

    char start = 'A', target = 'E';
    vector<char> shortest_path = bfs_shortest_path(graph, start, target);

    int i;
    cout << '[';
    for (i = 0; i < shortest_path.size() - 1; i++) {
        cout << "'" << shortest_path[i] << "', ";
    }
    cout << "'" << shortest_path[i] << "']" << endl;

    return 0;
}
