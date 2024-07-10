#include <bits/stdc++.h>

using namespace std;

void spiralOrder(const vector<vector<int>>& matrix, vector<int>& result) {
  int rows = matrix.size();
  if (rows == 0){ 
    return;
  }
  int cols = matrix[0].size();
    
  int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; ++i) {
      result.push_back(matrix[top][i]);
    }
    top++;

    for (int i = top; i <= bottom; ++i) {
      result.push_back(matrix[i][right]);
    }
      right--;

    if (top <= bottom) {
      for (int i = right; i >= left; --i) {
        result.push_back(matrix[bottom][i]);
      }
      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; --i) {
        result.push_back(matrix[i][left]);
      }
        left++;
    }
  }
}

int main() {
  int m, n, k;
  cout << "Enter the number of rows: ";
  cin >> m;
  cout << "Enter the number of columns: ";
  cin >> n;

  vector<vector<int>> matrix(m, vector<int>(n));
  cout << "Enter the matrix elements:" << endl;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  cout << "Enter the value of k: ";
  cin >> k;

  vector<int> result;
  spiralOrder(matrix, result);

  if (k > 0 && k <= result.size()) {
    cout << "The " << k << "th element in spiral order is: " << result[k - 1] << endl;
  } 
  else {
    cout << "Invalid value of k" << endl;
  }

  return 0;
}
