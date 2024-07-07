// hello readers!!
// this is a leetcode inspired problem 
// here user will input a target value let say K
// program will return pair of 3 digits which present in the given array arr = {10, 5, 5, 5, 2, 6, 4, 2}
// and sum of the pair is equal to K
// code is very simple and easy to understand , one can modify this code to take user input for the array too.
// well this is all the code read and enjoy

#include <bits/stdc++.h>
using namespace std;

void findTriplets(vector<int> arr, int n, int K)
{
    set<vector<int>> ans;

    // first we will sort the array make it easier to solve
    sort(arr.begin(), arr.end());

    int i = 0;
    while (i < n - 2)
    {
        int start = i + 1;
        int end = n - 1;
        while (start < end)
        {
            int sum = arr[i] + arr[start] + arr[end];
            if (sum == K)
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[start]);
                temp.push_back(arr[end]);
                ans.insert(temp);
                start++;
                end--;
            }
            else if (sum > K)
                end--;
            else
                start++;
        }
        i++;
    }
    vector<vector<int>> answer(ans.begin(), ans.end());
    //   return answer;
    for (auto x : answer)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {10, 5, 5, 5, 2, 6, 4, 2};
    int size = arr.size();
    int target;
    cin >> target;
    findTriplets(arr, size, target);

    return 0;
}