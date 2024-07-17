/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.*/

#include<iostream>
#include<vector>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
        int start = 0,end = 0,mid,ans;
        int n = piles.size();
        long long sum = 0;
        for(int i = 0; i<n; ++i){
            sum += piles[i];
            end = max(end,piles[i]);
        }
        start = sum/h;
        if(!start)  start = 1;
        while(start <= end){
            mid = start + (end - start)/2;
            int total_time = 0;
            for(int i = 0; i<n; ++i){
                total_time += piles[i]/mid;
                if(piles[i]%mid != 0){
                    total_time++;
                }
            }
            if(total_time > h){
                start = mid+1;
            }
            else{
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
};

int main(){
  vector <int> piles = {30,11,23,4,20};
  int time = 5;

  cout<<"Minimum number of banana: "<<minEatingSpeed(piles,time);
}