// Program to find the number of triplets chosen from the array that can make valid triangles if we take them as side lengths of a triangle.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ValidTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), ans = 0;
        for (int c = 2; c < n; ++c) {
            int a = 0, b = c - 1;
            while (a < b) {
                if (arr[a] + arr[b] > arr[c]) {
                    ans += b - a;
                    b --;
                }
                else
                    a++;
            }
        }
        return ans;
};

int main(){
  vector <int> arr = {2,2,3,4};
  cout<<"Valid triangles: "<<ValidTriangles(arr)<<endl;
}