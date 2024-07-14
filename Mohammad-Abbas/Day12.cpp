#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void mergeAndPrintSorted(vector<vector<int>> &arr ){
    priority_queue<int,vector<int>,greater<int>>minHeap;

    for (const auto&i:arr){
    for(int num:i){
            minHeap.push(num);
        }
    }
    while(!minHeap.empty()){
cout<<minHeap.top()<<" ";
minHeap.pop();
    }
    cout<<endl;
};
int main() {

    vector<vector<int>> arr = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {10, 9, 10, 11}
    };

    // Merge and print sorted elements
    mergeAndPrintSorted(arr);

    return 0;
}