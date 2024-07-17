// Program to merge K sorted arrays each of length N using a MinHeap
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct MinHeapNode {
    int element;
    int i;
    int j;
};

struct compare {
    bool operator()(const MinHeapNode& lhs, const MinHeapNode& rhs) {
        return lhs.element > rhs.element;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int K, int N) {
    priority_queue<MinHeapNode, vector<MinHeapNode>, compare> minHeap;
    vector<int> result;

    for (int i = 0; i < K; ++i) {
        if (N > 0) {
            MinHeapNode node = {arr[i][0], i, 1};
            minHeap.push(node);
        }
    }

    while (!minHeap.empty()) {
        MinHeapNode root = minHeap.top();
        minHeap.pop();
        result.push_back(root.element);

        if (root.j < N) {
            MinHeapNode nextNode = {arr[root.i][root.j], root.i, root.j + 1};
            minHeap.push(nextNode);
        }
    }

    return result;
}

int main() {
    int K = 3;
    int N = 4;
    vector<vector<int>> arr = { {1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11} };

    vector<int> output = mergeKSortedArrays(arr, K, N);

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << " ";
    }

    return 0;
}

// Output:- 0 1 2 3 4 5 6 7 8 9 10 11 
