/*Program to  find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :

1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
2.  x1 >x2 < x3 > x4 < x5. . . . . and so on */

#include<iostream>
#include<vector>
using namespace std;

int MaxLength(vector<int>& arr) {
        int up = 1,down = 1,n = arr.size();
        if(n==1)    return 1;
        if(n == 2)  return arr[0]==arr[1]?1:2;
        
        for(int i = 1; i<n; ++i){
            if(arr[i] > arr[i-1])   up = down+1;
            else if(arr[i]<arr[i-1])    down = up+1;
        }
        return max(up,down);
};

int main(){
  vector<int> arr = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  cout<<"Length of the longest alternating subsequence: "<<MaxLength(arr);
}