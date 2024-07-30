#include<math.h>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return 0;
        }
    long long unsigned int ans=0;
    int i=x;
    int count=-1;
    while(i!=0)
    {
        count++;
        i=i/10;
    }
    i=x;
    while(i!=0)
    {
        int a=i%10;
        ans=ans+(a*pow(10,count));
        count--;
        i=i/10;
    }
  
    if(ans==x)
    {
        return 1;
    }
    else
    return 0;
    }
};