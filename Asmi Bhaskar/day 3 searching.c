#include <stdio.h>
#include <stdbool.h>

bool canMakeBouquets(int* bloomDay, int N, int M, int K, int days) {
    int bouquets = 0;
    int flowers = 0;

    for (int i = 0; i < N; i++) {
        if (bloomDay[i] <= days) {
            flowers++;
            if (flowers == K) {
                bouquets++;
                flowers = 0;
                if (bouquets == M) {
                    return true;
                }
            }
        } else {
            flowers = 0;
        }
    }
    return false;
}

int minDays(int* bloomDay, int N, int M, int K) {
    if (N < M * K) {
        return -1;
    }

    int left = bloomDay[0];
    int right = bloomDay[0];

    for (int i = 1; i < N; i++) {
        if (bloomDay[i] < left) {
            left = bloomDay[i];
        }
        if (bloomDay[i] > right) {
            right = bloomDay[i];
        }
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canMakeBouquets(bloomDay, N, M, K, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int bloomDay[] = {5, 5, 5, 5, 10, 5, 5};
    int M = 2;
    int K = 3;
    int N = sizeof(bloomDay) / sizeof(bloomDay[0]);

    int result = minDays(bloomDay, N, M, K);
    printf("Minimum number of days to make %d bouquets is: %d\n", M, result);

    return 0;
}
