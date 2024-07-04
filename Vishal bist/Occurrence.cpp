// Program to check the first and last occurrence of an element in a sorted array.

#include <iostream>
#include <vector>
using namespace std;

vector<int> search_occurrence(vector<int>& arr, int x)
{
  int start = 0, end = arr.size() - 1, first = -1, last = -1, mid;
  if (arr.size() == 0)
    return {first, last};

  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] == x)
    {
      first = mid;
      end = mid - 1;
    }
    else if (arr[mid] < x)
    {
      start = mid + 1;
    }
    else
      end = mid - 1;
  }
  start = 0, end = arr.size() - 1;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] == x)
    {
      last = mid;
      start = mid + 1;
    }
    else if (arr[mid] < x)
    {
      start = mid + 1;
    }
    else
      end = mid - 1;
  }

  return {first, last};
}

int main()
{
  vector<int>arr = {2, 3, 3, 5, 7, 8, 9, 9, 9, 9, 11, 11, 15};
  int x = 9;
  vector<int> result = search_occurrence(arr, 9);
  cout<<"first: "<<result[0];
  cout<<" last: "<<result[1]<<endl;
}
