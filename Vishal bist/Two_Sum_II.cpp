/*Program to find two numbers such that they add up to a specific number[x]. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  int start = 0, end = nums.size() - 1;
  vector<int> ans;
  while (start <= end)
  {
    if (nums[start] + nums[end] == target)
    {
      ans.push_back(start + 1);
      ans.push_back(end + 1);
      return ans;
    }
    else if (nums[start] + nums[end] > target)
      end--;
    else
      start++;
  }
  return ans;
};

int main()
{
  vector<int> nums = {2, 7, 11, 15};
  int x = 9;
  vector<int> result = twoSum(nums, x);
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
}