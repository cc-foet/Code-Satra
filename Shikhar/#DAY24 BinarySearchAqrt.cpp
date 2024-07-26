#include<iostream>
using namespace std;

class Solution {
public:

int bin_sea(int n)
{
   long int s=0;
   long int e=n;
    long int mid=s+(e-s)/2;
    long int ans=-1;
    while(s<=e)
    {
        long int square=mid*mid;
        if(square<n)
        {
            ans=mid;
            s=mid+1;
        }

        else if(square>n)
        {
            e=mid-1;
        }

        else
        {
            return mid;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}


    int mySqrt(int x) {
        return bin_sea(x);
    }
};