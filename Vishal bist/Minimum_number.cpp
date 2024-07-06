// Program to find the minimum element from a rotated array.
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &arr)
{
  int start = 0, end = arr.size() - 1, ans = arr[0], mid;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] >= arr[0])
      start = mid + 1;
    else
    {
      ans = arr[mid];
      end = mid - 1;
    }
  }
  return ans;
};

int main()
{
  vector<int> arr = {4, 5, 8, 9, 0, 1, 2, 3};
  cout<<findMin(arr)<<endl;
  return 0;
}