/*
Given an integer target, return true if target is in matrix or false otherwise.
Expected time complexity: O(log(m * n)).
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int row = matrix.size();
  int col = matrix[0].size();
  int start = 0, end = (row * col) - 1, mid;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    int row_index = mid / col;
    int col_index = mid % col;
    if (matrix[row_index][col_index] == target)
      return true;
    else if (matrix[row_index][col_index] < target)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return false;
};

int main(){
  vector<vector<int>>matrix = 
  {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}
  };

  int x = 20;

  cout<<searchMatrix(matrix, x);
  return 0;
}