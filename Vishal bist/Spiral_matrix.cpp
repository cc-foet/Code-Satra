/* Program to print all elements of the matrix in spiral order. */

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  int row = matrix.size();
  int col = matrix[0].size();
  vector<int> ans;
  int top = 0, bottom = row - 1, left = 0, right = col - 1;

  while (top <= bottom && left <= right)
  {
    for (int i = left; i <= right; ++i)
      ans.push_back(matrix[top][i]);
    top++;
    for (int j = top; j <= bottom; ++j)
      ans.push_back(matrix[j][right]);
    right--;
    if (top <= bottom)
    {
      for (int i = right; i >= left; --i)
        ans.push_back(matrix[bottom][i]);
      bottom--;
    }
    if (left <= right)
    {
      for (int j = bottom; j >= top; --j)
        ans.push_back(matrix[j][left]);
      left++;
    }
  }
  return ans;
};

int main(){
  vector<vector<int>> matrix = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
    };
  vector<int>ans = spiralOrder(matrix);
  for(int num: ans){
    cout<<num<<" ";
  }
}