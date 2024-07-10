#include <iostream>
#include <vector>
using namespace std;
  
vector <int> spiralOrder(vector<vector<int>>& matrix) {vector<int>ans;
  int n=matrix.size();
  int m=matrix[0].size();
  int startingrow=0;
  int endingcolumn=n-1;
  int endingrow=m-1;
  int startingcolumn=0;
  int totalelement=m*n;
  int count=0;
  while(count<totalelement){
    for(int i=startingcolumn;i<=endingcolumn && count<totalelement;i++){
ans.push_back(matrix[startingrow][i]);
count++;
    }
    startingrow++;

     for(int i=startingrow;i<=endingrow && count<totalelement;i++){
ans.push_back(matrix[i][endingcolumn]);
count++;
    }
  endingcolumn--;


  
     for(int i=endingcolumn;i>=startingcolumn && count<totalelement;i--){
ans.push_back(matrix[endingrow][i]);
count++;
    }
  endingrow--;

     for(int i=endingrow;i>=startingrow && count<totalelement;i--){
ans.push_back(matrix[i][startingcolumn]);
count++;
    }
startingcolumn++;
  }return ans;
 } 

