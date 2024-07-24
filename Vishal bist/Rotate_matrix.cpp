/*
Program to rotate a 2D array by 90 degree.
*/

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int start,end,n = matrix.size();
        for(int i = 0; i<n-1; ++i){
            for(int j = i+1; j<n; ++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0; i<n; ++i){
            start = 0,end = n-1;
            while(start<end){
                swap(matrix[i][start],matrix[i][end]);
                start++,end--;
            }
        }
};

int main(){
  vector<vector<int>>matrix = {
    {5,1,9,11},
    {2,4,8,10},
    {13,3,6,7},
    {15,14,12,16}
  };
  rotate(matrix);
  for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}