// Program to check if the given number is a palindrome or not.
#include<iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        int ans = 0, num = x, rem;
        while(num != 0){
            rem = num%10;
            num/=10;
            if(ans > INT_MAX/10 || ans < INT_MIN/10)
                return 0;
            ans = ans*10 + rem;
        }
        if(ans == x)
            return true;
        return false;
};

int main()
{
  cout<<isPalindrome(121)<<endl;
  cout<<isPalindrome(-121)<<endl;
  cout<<isPalindrome(114)<<endl;
}
