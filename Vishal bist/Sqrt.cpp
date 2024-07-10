// Program to find the square root of given number(non negative) rounded down to the nearest integer.
#include<iostream>
using namespace std;

int Sqrt(int x) {
        int start = 0,end = x,mid,ans;

        if(x<2)    return x;

            while(start<=end){
                mid = start + (end-start)/2;
                if(mid == x/mid) return mid;
                else if(mid < x/mid){
                    ans = mid;
                    start = mid+1;
                }
                else
                    end = mid-1;
            }
        return ans;
    };

int main(){
      int x;
      cout<<"Enter a number: ";
      cin>>x;
      cout<<Sqrt(x)<<endl;
return 0;
}