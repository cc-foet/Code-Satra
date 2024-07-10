#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, vector<int> &first, vector<int> &second){
  int firstIndex = 0;
  int secondIndex = 0;
  int arrIndex = 0;
  int len1 = first.size();
  int len2 = second.size();
  arr.resize(len1 + len2);
  while(firstIndex < len1 && secondIndex < len2){
    if(first[firstIndex] < second[secondIndex]){
      arr[arrIndex++] = first[firstIndex++];
    }
    else{
      arr[arrIndex++] = second[secondIndex++];
    }
  }
  
  while(firstIndex < len1){
    arr[arrIndex++] = first[firstIndex++];
  }
  
  while(secondIndex < len2){
    arr[arrIndex++] = second[secondIndex++];
  }
}

int main()
{
  int n;
  cout << "Enter the number of elements in first array: ";
  cin >> n;
  vector<int> first(n);
  cout << "Enter the elements: ";
  for (int i = 0; i < n; ++i) {
    cin >> first[i];
  }
  int m;
  cout << "Enter the number of elements in second array: ";
  cin >> m;
  vector<int> second(m);
  cout << "Enter the elements: ";
  for (int i = 0; i < m; ++i) {
    cin >> second[i];
  }

  int index;
  cout << "Enter the index: ";
  cin >> index;
  if(index < 1 || index > n + m) {
    cout << "Index out of bounds." << endl;
    return 1;
  }
    
  vector<int> arr;
  merge(arr, first, second);
  cout << "Element at index " << index << " is: " << arr[index - 1] << endl; 
  return 0;
}