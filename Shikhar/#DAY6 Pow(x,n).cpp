// Leetcode question 50
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// A special care should be taken because an edge case can be because the range of int is
// -2,147,483,648 to 2,147,483,647 so when we try to convert it we can make the stack overflow so we use long long int.

//Problem Link:- https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long int m = n;
        if(m<0) m = -1 * m;
        while(m){
            if(m%2){
            ans = ans*x;
            m = m-1;
        }else{ 
            x = x*x;
            m = m/2;
        }
        }
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};