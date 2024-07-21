#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n), rightmax(n);
        leftmax[0] = 0, rightmax[n - 1] = 0;
        for (int i = 1; i < n; ++i) {
            leftmax[i] = max(leftmax[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i > 0; --i) {
            rightmax[i] = max(rightmax[i + 1], height[i + 1]);
        }
        int minheight,water = 0;
        for (int i = 0; i < n; ++i) {
            minheight = min(leftmax[i], rightmax[i]);
            if (minheight - height[i] >= 0)
                water += (minheight - height[i]);
        }
        return water;
};

int main(){
  vector<int>height = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout<<"Max water trapped: "<<trap(height)<<endl;
}