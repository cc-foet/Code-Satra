#include <stdio.h>
#include <stdbool.h>

int max(int *arr, int n) {
  int max_num = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max_num) {
      max_num = arr[i];
    }
  }
  return max_num;
}

int sum(int *arr, int n) {
  int sum_arr = 0;
  for (int i = 0; i < n; i++) {
    sum_arr += arr[i];
  }
  return sum_arr;
}

bool checkTime(int *arr, int n, int k, int max_time) {
  int total_time = 0, painters = 1;

  for (int i = 0; i < n; i++) {
    total_time += arr[i];
    if (total_time > max_time) {
      total_time = arr[i];
      painters += 1;
      if (painters > k) {
        return false;
      }
    }
  }

  return true;
}

int getMinTime(int *arr, int n, int k) {
  int low = max(arr, n), high = sum(arr, n);

  while (low < high) {
    int mid = (low + high) / 2;
    if (checkTime(arr, n, k, mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return low;
}

int main() {
  int arr[] = {10, 20, 30, 40};
  int n = sizeof arr / sizeof arr[0];
  int k = 2;

  int min_time = getMinTime(arr, n, k);
  printf("%d\n", min_time);
  return 0;
}