#include <stdio.h>
#include <limits.h>

int canMake(int days, int bloomArray[], int size, int flowersInBouquets, int noOfBouquets) {
    int bouquets = 0;
    int flowers = 0;
    for (int i = 0; i < size; i++) {
        if (bloomArray[i] <= days) {
            flowers++;
            if (flowers == flowersInBouquets) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
    }
    return bouquets >= noOfBouquets;
}

int daysToBouquet(int bloomArray[], int size, int flowersInBouquets, int noOfBouquets) {
    if (size < flowersInBouquets * noOfBouquets) {
        return -1;
    }

    int left = INT_MAX, right = 0;
    for (int i = 0; i < size; i++) {
        left = bloomArray[i] < left ? bloomArray[i] : left;
        right = bloomArray[i] > right ? bloomArray[i] : right;       
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canMake(mid, bloomArray, size, flowersInBouquets, noOfBouquets)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return canMake(left, bloomArray, size, flowersInBouquets, noOfBouquets) ? left : -1;
}

void main() {
    int bloomDay[] = {1, 10, 3, 10, 2};
    int k = 1;
    int m = 3;

    int size = sizeof(bloomDay) / sizeof(bloomDay[0]);
    printf("%d",daysToBouquet(bloomDay, size, k, m));
}