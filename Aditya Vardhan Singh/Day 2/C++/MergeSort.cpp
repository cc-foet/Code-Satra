/*** Includes ***/
#include <iostream>
#include <vector>

using namespace std;

/*** Merge Sort ***/
void merge(vector<int>& arr, int low, int mid, int high) {
  int left = low;
  int right = mid+1;
  vector<int> temp;

  while (left <= mid && right <= high) {
    if (arr[left] < arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }
  for (int i = low; i <= high; i++) {
    arr[i] = temp[i-low];
  }
}

void merge_sort(vector<int>& arr, int low, int high) {
  if (low >= high) return;

  int mid = low + (high-low)/2;
  merge_sort(arr, low, mid);
  merge_sort(arr, mid+1, high);
  merge(arr, low, mid, high);
}

void print_array(vector<int>& arr) {
  int n = arr.size();

  cout << "[";
  for (int i = 0; i < n-1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[n-1] << "]\n";
}

/*** Driver code ***/
int main(int argc, const char **argv) {
  // check arguments
  if (argc != 2) {
    printf("Usage: %s <inputfile>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  // arguments check end

  // open file and input array size, array, n, m
  FILE *fin = fopen(argv[1], "r");
  int size, n, m;
  vector<int> arr;

  fscanf(fin, "%d", &size);
  for (int i = 0, data; i < size; i++) {
    fscanf(fin, "%d", &data);
    arr.push_back(data);
  }
  fscanf(fin, " %d%d", &n, &m);
  // file input ends

  merge_sort(arr, n, n+m-1);
  print_array(arr);

  return EXIT_SUCCESS;
}
