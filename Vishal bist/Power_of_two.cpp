//Program to check if the given number is power of two or not
#include<iostream>
using namespace std;

bool isPowerOfTwo(int n) {
        if(n < 1)
            return 0;

        while(n != 1){
            if(n%2 == 1)
                return 0;
            n/=2;
        }
        return 1;
    };

int main(){
  cout<<isPowerOfTwo(16)<<endl;
  cout<<isPowerOfTwo(-96)<<endl;
  cout<<isPowerOfTwo(94372)<<endl;
}
