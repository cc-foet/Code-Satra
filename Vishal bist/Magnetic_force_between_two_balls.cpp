/* Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start = 1, end = 0,mid,ans;
        int n = position.size();
        end = position[n-1] - position[0];
        while(start<=end){
            mid = start + (end - start)/2;
            int count = 1;
            long long  pos = position[0];
            for(int i = 0; i<n; ++i){
                if(pos+mid <= position[i]){
                    count++;
                    pos = position[i];
                }
            }
            if(count < m) {
                end = mid-1;
                }
            else{
                ans = mid;
                start = mid+1;                
            }
        }
        return ans;
  };
  
  int main(){
    vector<int> position = {1,2,3,4,7};
    int balls = 3;
    cout<<"Maximum distance and minimum force between two balls: "<<maxDistance(position,balls)<<endl;
  }
