/* Program to find the length of the smallest distinct substring(window) from the given string 's'. The smallest substring should contains all the characters of the given string at least one time.
The given string [s] consists of English letters, digits, symbols and spaces. */

#include<iostream>
#include<vector>
using namespace std;

int findSubString(string str)
    {
        vector<int>Char(256,0);
        int first = 0, second = 0, len=str.size(),uniqueChar = 0;
        while(first< str.size()){
            if(Char[str[first]] == 0){
            uniqueChar++;
            Char[str[first]]++;
            }
            first++;
        }
        for(int i = 0; i<256; ++i) Char[i] = 0;
        first = 0;
        while(second<str.size()){
            while(uniqueChar&&second<str.size()){
                if(Char[str[second]] == 0)    uniqueChar--;
                Char[str[second]]++;
                second++;
            }
            len = min(len,second-first);
            while(uniqueChar!=1){
                len = min(len,second-first);
                Char[str[first]]--;
                if(Char[str[first]]==0) uniqueChar++;
                first++;
            }
        }
        return len;
};

int main(){
  string str = "AA1B*2BBCBB1A2*C";
  cout<<"Length of the smallest distinct substring: "<<findSubString(str)<<endl;
  return 0;
}