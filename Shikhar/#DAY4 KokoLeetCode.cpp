// Problem statement:- 

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Problem Link: https://leetcode.com/problems/koko-eating-bananas/description/

// Solution: 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int> arr, int k, int h){
        long int hours = 0;
        for(int i=0; i<arr.size(); i++){
            int m = arr[i]/k;
            hours = hours+m;
            if(arr[i]%k!=0){
                hours++;
            }
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        
        int s = 1;
	    int e = 1000000000;
        
        while(s <= e){
        int mid = s+(e-s)/2;
        if(isPossible(arr, mid, h)){
            e = mid-1;
        }
        else{
            s = mid+1;
        }

    }
            return s;
    }
    
};



















// PS:- Took me an hour 😭