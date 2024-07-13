#include <iostream>
#include <vector>

int find_spiral(std::vector<std::vector<int>>& matrix, int K) {
  int N = matrix.size();
  int M = matrix[0].size();
  std::vector<int> spiral_arr;

  int top = 0, bottom = N - 1;
  int left = 0, right = M - 1;

  while (left <= right && top <= bottom) {
    for (int i = left; i <= right; ++i) {
      spiral_arr.push_back(matrix[top][i]);
    }
    top++;

    for (int i = top; i <= bottom; ++i) {
      spiral_arr.push_back(matrix[i][right]);
    }
    right--;

    if (top <= bottom) {
      for (int i = right; i>= left; --i) {
        spiral_arr.push_back(matrix[bottom][i]);
      }
      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; --i) {
        spiral_arr.push_back(matrix[i][left]);
      }
      left++;
    }
  }

  return spiral_arr[K-1];
}

int main(int argc, char const *argv[]) {
  std::vector<std::vector<int>> matrix = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  int K = 7;

  std::cout << find_spiral(matrix, K) << '\n';
  return 0;
}
