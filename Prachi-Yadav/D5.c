#include <stdio.h>

int kth_element(int arr1[], int len1, int arr2[], int len2, int k) {
    int i = 0, j = 0;
    int count = 0;
    int result = 0;

    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            count++;
            if (count == k) {
                result = arr1[i];
                break;
            }
            i++;
        } else {
            count++;
            if (count == k) {
                result = arr2[j];
                break;
            }
            j++;
        }
    }

    while (i < len1 && count < k) {
        count++;
        if (count == k) {
            result = arr1[i];
            break;
        }
        i++;
    }

    while (j < len2 && count < k) {
        count++;
        if (count == k) {
            result = arr2[j];
            break;
        }
        j++;
    }

    return result;
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1, 4, 8, 10};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;

    int result = kth_element(arr1, len1, arr2, len2, k);
    printf("The kth element in the merged sorted array is: %d\n", result);

    return 0;
}
