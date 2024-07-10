#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int getSum(vector<int>& bloomDay, int i, int n) {
    int sum = 0;
    for (int idx = i; idx < n; idx++) {
        sum += bloomDay[idx];
    }
    return sum;
}

int getMax(vector<int>& bloomDay, int i, int n) {
    int max = bloomDay[i];
    for (int idx = i+1; idx < n; idx++) {
        if (bloomDay[idx] > max) max = bloomDay[idx];
    }
    return max;
}

int bouquet(vector<int>& bloomDay, int M, int K) {
    int n = bloomDay.size();
    int adj_flowers = M * K;

    // required flowers are more than flowers in garden
    if (adj_flowers > n) return -1;

    int min_idx = 0;
    int min_sum = INT_MAX;
    int sum = 0;
    for (int i = 0; i <= n - adj_flowers; i++) {
        sum = getSum(bloomDay, i, i+adj_flowers);
        if (sum < min_sum) {
            min_sum = sum;
            min_idx = i;
        }
    }

    return getMax(bloomDay, min_idx, min_idx + adj_flowers);
}

int main(int argc, const char **argv) {
    // check arguments for testcases file
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open testcases file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Cannot open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // get M, K, bloomDay array from testcase file
    int M, K;
    fscanf(fp, "%d%d", &M, &K);
    vector<int> bloomDay;
    int n, data;
    fscanf(fp, "%d", &n);
    while (n--) {
        fscanf(fp, "%d", &data);
        if (data == EOF) {
            printf("Error getting array elements!\n");
            exit(EXIT_FAILURE);
        }
        bloomDay.push_back(data);
    }
    // input from testcase file ends

    // print output
    cout << bouquet(bloomDay, M, K) << endl;
}