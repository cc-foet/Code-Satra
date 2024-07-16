/*Given an array consisting of n integers which denote the position of a stall. You are also given an integer k which 
denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance 
between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minDis(int n, int k, vector<int> &stalls) {
        int start = 1,end,mid,ans;
        sort(stalls.begin(),stalls.end());
        end = stalls[n-1]-stalls[0];
        while(start<=end){
            mid = start + (end - start)/2;
            int count = 1, pos = stalls[0];
            for(int i = 1; i<n; ++i){
                if((pos + mid) <= stalls[i]){
                    count++;
                    pos = stalls[i];
                }
            }
            if(count < k){
                end = mid-1;
            }
            else{
                ans = mid;
                start = mid+1;
                }
        }
        return ans;
};

int main() {
    vector <int> stalls = {10, 1, 2, 7, 5};
    int n = stalls.size();

    cout<<"Minimum distance between two cows: "<<minDis(n,3,stalls)<<endl;
}