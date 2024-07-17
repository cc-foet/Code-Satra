#include <stdio.h>
#include <stdlib.h>

int countTrees(int* arr, int start, int end) {
    if (start > end) {
        return 1;
    }

    int i, leftCount, rightCount, totalCount = 0;

    for (i = start; i <= end; i++) {
        leftCount = countTrees(arr, start, i - 1);
        rightCount = countTrees(arr, i + 1, end);
        totalCount += leftCount * rightCount;
    }

    return totalCount;
}

int main() {
    int arr[] = {4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int totalCount = countTrees(arr, 0, n - 1);

    printf("Total number of possible binary trees: %d\n", totalCount);

    return 0;
}
