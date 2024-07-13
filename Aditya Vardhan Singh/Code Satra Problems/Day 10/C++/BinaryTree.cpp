#include <iostream>
#include <vector>

using namespace std;

int num_trees(int n) {
    vector<int> catalan(n+1, 0);
    catalan[0] = 1;
    catalan[1] = 1;

    for (int i = 2; i < n + 1; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i-j-1];
        }
    }

    return catalan[n];
}

int main() {
    vector<int> arr = {4, 5, 7};
    cout << num_trees(arr.size()) << endl;
    return 0;
}