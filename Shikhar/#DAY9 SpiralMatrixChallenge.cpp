// In this file I have solved the Day 8 challenge.

#include<iostream>
using namespace std;


int main(){
        int matrix[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        int bottom=3;
        int top=0;
        int left=0;
        int right=3;
        int count = 0;
        int k=7;
        int ans;
        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++){
                count++;
                if(count==k){
                    ans = matrix[top][i];
                }
            }
            top++;
            for(int i=top; i<=bottom; i++){
                count++;
                if(count==k){
                  ans = matrix[i][right];
                }       
            }
            right--;
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    count++;
                    if(count==k){
                        ans=matrix[bottom][i];
                    }
                }
            bottom--;
            }
            
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    count++;
                    if(count==k){
                        ans = matrix[i][left];
                    }
                }
            left++;
            }
        }
        cout<< ans;
    }

// Output 16