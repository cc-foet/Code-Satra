#include <iostream>
#include <vector>
using namespace std;

// This code calculates the number of possible Binary Trees for a given Inorder Traversal using Catalan numbers.
unsigned long int catalan(unsigned int n) {
    vector<unsigned long int> catalan(n + 1, 0);
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    return catalan[n];
}

unsigned long int numberOfBinaryTrees(vector<int>& inorder) {
    int n = inorder.size();
    return catalan(n);
}

int main() {
    vector<int> arr = {4, 5, 7};
    cout << "Number of possible Binary Trees: " << numberOfBinaryTrees(arr) << endl;
    return 0;
}

// Output: Number of possible Binary Trees: 5
