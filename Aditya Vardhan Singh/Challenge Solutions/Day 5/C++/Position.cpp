#include <iostream>
#include <vector>

using namespace std;

int find_position(vector<int>& arr1, vector<int>& arr2, int k) {
    vector<int> arr3;
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3.push_back(arr1[i]);
            i++;
        } else {
            arr3.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n) {
        arr3.push_back(arr1[i]);
        i++;
    }

    while (j < m) {
        arr3.push_back(arr2[j]);
        j++;
    }

    return arr3[k-1];
}

int main(int argc, const char ** argv) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    int data, n;
    vector<int> arr1, arr2;
    int k;

    fscanf(fp, "%d", &n);
    while (n--) {
        fscanf(fp, "%d", &data);
        arr1.push_back(data);
    }

    fscanf(fp, "%d", &n);
    while (n--) {
        fscanf(fp, "%d", &data);
        arr2.push_back(data);
    }

    fscanf(fp, "%d", &k);

    cout << find_position(arr1, arr2, k) << endl;
    return EXIT_SUCCESS;
}