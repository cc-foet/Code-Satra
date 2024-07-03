#include <iostream>
#include <vector>

using namespace std;

void merge_sorted_parts(vector<int>& nums, int n, int m) 
{
    int i = 0, j = n;
    while (i < n && j < n + m) 
    {
        if (nums[i] <= nums[j]) 
        {
            i++;
        } 
        else 
        {
            int temp = nums[j];
            for (int k = j; k > i; k--) 
            {
                nums[k] = nums[k - 1];
            }
            nums[i] = temp;
            i++;
            j++;
            n++;
        }
    }
}

int main() 
{
    vector<int> nums = {1, 3, 6, 19, 11, 16};
    int n = 3;
    int m = 3;

    merge_sorted_parts(nums, n, m);

    for (int num : nums) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
