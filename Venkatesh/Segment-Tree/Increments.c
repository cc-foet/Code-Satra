#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int *segmentTree;
int *prefix;

int max(int a, int b) {
    return a > b ? a : b;
}

int buildTree(int arr[], int start, int end, int node) {
    if (start == end) {
        segmentTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        segmentTree[node] = max(buildTree(arr, start, mid, 2 * node + 1), buildTree(arr, mid + 1, end, 2 * node + 2));
    }
    return segmentTree[node];
}

int query(int start, int end, int l, int r, int node) {
    if (start > r || end < l) {
        return INT_MIN;
    }
    if (start >= l && end <= r) {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    return max(query(start, mid, l, r, 2 * node + 1), query(mid + 1, end, l, r, 2 * node + 2));
}

int longestSubarray(int arr[], int len, int k) {
    int res = 1;

    prefix = (int *)malloc((len + 1) * sizeof(int));
    prefix[0] = arr[0];
    for (int i = 1; i < len; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    buildTree(arr, 0, len - 1, 0);

    for (int i = 0; i < len; i++) {
        int start = i;
        int end = len - 1;
        int max_index = i;

        while (start <= end) {
            int mid = (start + end) / 2;
            int max_num = query(0, len - 1, i, mid, 0);

            int sum_expected = (mid - i + 1) * max_num;
            int sum_actual = prefix[mid] - prefix[i] + arr[i];

            if (sum_actual + k >= sum_expected) {
                max_index = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        res = max(res, max_index - i + 1);
    }
    free(prefix);
    return res;
}

void main() {
    int arr[] = {2, 0, 4, 6, 7};
    int k = 6;
    int len = sizeof(arr) / sizeof(arr[0]);

    segmentTree = (int *)malloc((2 * len - 1) * sizeof(int));
    memset(segmentTree, 0, (2 * len - 1) * sizeof(int));

    printf("%d\n", longestSubarray(arr, len, k));

    free(segmentTree);
}