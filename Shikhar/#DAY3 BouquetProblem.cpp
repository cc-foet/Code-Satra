// Solution:-

// The approach is firstly, we create a function which checks if the blooming of flowers is possible on a given day or not and whether or not required number of bouquets can be created from those number of consecutive flowers.

// Secondly we write two functions called lowNo and highNo which help us find the range in which the possible number of days are present in which bouquet can be made.

// The third and the final step includes us writing a binary search algorithm with the logic that:
// 1- If the "mid" element is possible then we look for a lesser element by doing high=mid-1
//2 If the "mid" element is not possible then we look for the element in the remaning grater half of the array because anyhing less than mid will also not be possible.

// And also we check if the case is impossible or not by (m*k > arr.size()) because in such a case no bouquets will be possible.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isPossible(vector<int> arr, int day, int m, int k){
	int count= 0;
	int noOfBouquet = 0;
	for(int i=0; i<arr.size(); i++){
		if(arr[i] <= day){
			count++;
		}else{
			noOfBouquet += count/k;
			count = 0;
		}
	}
	noOfBouquet += count/k;
	if(noOfBouquet >= m){
		return true;
	}else{
		return false;
	}
}

int lowNo(vector<int> arr){
	int ans = INT_MAX;
	for(int i=0 ; i<arr.size(); i++){
		if(ans > arr[i]){
			ans = arr[i];
		}
	}
	return ans;
}

int highNo(vector<int> arr){
	int ans = INT_MIN;
	for(int i=0 ; i<arr.size(); i++){
		if(ans < arr[i]){
			ans = arr[i];
		}
	}
	return ans;
}

int roseGarden(vector<int> arr, int k, int m)
{
	int low = lowNo(arr);
	int high = highNo(arr);
	if(m*k>arr.size()){
		return -1;
	}
	while(low <= high){
		int mid = low+(high-low)/2;
		if(isPossible(arr, mid, m, k)){
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return low;
}