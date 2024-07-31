#include <iostream>
using namespace std;


class Solution {
private:
    int num(char ch)
    {
        switch(ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }

public:

    int romanToInt(string s) {
        int result=0;
        int last=0;
        int current=0;
        for(int i=s.size()-1 ; i>=0 ; i--)
        {
            current=num(s[i]);
            if(current<last)
            {
                result=result-current;
                last=current;
            }
            else
            {
                result=result+current;
                last=current;
            }
        }
        return result;
    }    
};