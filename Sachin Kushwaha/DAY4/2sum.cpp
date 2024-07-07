// hello readers!!
// this is a leetcode inspired problem 

// https://leetcode.com/problems/two-sum/description/
// in this leetcode problem program return indexes of the pairs value 
// and i modify the code and my code 2sum.cpp will return value of the pairs instead of indexes

// here user will input a target value let say K
// program will return all pair of 2 digits which present in the given array vec1 = {2, 3, 4, 2, 5, 6, 7, 9}
// and sum of the pair is equal to K
// code is very simple and easy to understand , one can modify this code to take user input for the array too.
// well this is all the code read and enjoy


#include <bits/stdc++.h>
using namespace std;

// creating a function to print the pairs to form given target sum

void findPair(vector<int> &arr, int n, int s)
{

    vector<vector<int>> ans;

    int start = 0;
    while (start < n - 1)
    {
        int end = n - 1;
        while (start <= end)
        {
            int sum = arr[start] + arr[end];
            if (sum == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[start], arr[end]));
                temp.push_back(max(arr[start], arr[end]));
                ans.push_back(temp);

                end--;
            }

            else
                end--;
        }
        start++;
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
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
    vector<int> vec1 = {2, 3, 4, 2, 5, 6, 7, 9};
    int n = vec1.size();
    int target;
    cin >> target;
    findPair(vec1, n, target);
    return 0;
}