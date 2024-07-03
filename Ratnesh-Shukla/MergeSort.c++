#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int index = s;   
    for(int i = 0; i < len1; i++) {
        first[i] = arr[index++];
    }

    index = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = arr[index++];
    }

    int firstIndex = 0;
    int secondIndex = 0;
    int arrIndex = s;

    while(firstIndex < len1 && secondIndex < len2) {
        if(first[firstIndex] < second[secondIndex]) {
            arr[arrIndex++] = first[firstIndex++];
        } else {
            arr[arrIndex++] = second[secondIndex++];
        }
    }

    while(firstIndex < len1) {
        arr[arrIndex++] = first[firstIndex++];
    }

    while(secondIndex < len2) {
        arr[arrIndex++] = second[secondIndex++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e) {
    if(s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

void mergeInPlace(int arr[], int n, int m) {
    mergeSort(arr, n, n + m - 1);
    merge(arr, 0, n + m - 1);
}

void printArray(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl << endl;
}

int main() {
    int n = 3;
    int m = 3;
    int arr[] = {1, 3, 6, 19, 11, 16};

    int size = n + m;

    cout << "Array before sorting -->>  ";
    printArray(arr, size);

    mergeInPlace(arr, n, m);

    cout << "Array after sorting -->>  ";
    printArray(arr, size);

    return 0;
}
