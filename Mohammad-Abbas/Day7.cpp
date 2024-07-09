#include <bits/stdc++.h>
using namespace std;

bool isPalindromeusingStack(string str){
stack<char>st;
for(char c: str){
    st.push(c);
}
for(char c:str){
    if(c!=st.top()){return false;}
    st.pop();
}
return true;
}

bool isPalindromeusingQueue(string stra){
queue<char>q;
string reversestr="";
for(char c:stra){
q.push(c);
}
while(!q.empty()){
  reversestr+=  q.front();
    q.pop();
}
return stra==reversestr;
}
int main(){
    string str="codesatra";
    if(isPalindromeusingStack(str)){
        cout<<str<<" is Palindrome !"<<endl;
    }
    else {
        cout<<str<<" is not palindrome"<<endl;
    }

      string stra="codesatra";
    if(isPalindromeusingQueue(stra)){
        cout<<stra<<" is Palindrome !"<<endl;
    }
    else {
        cout<<stra<<" is not palindrome"<<endl;
    }
    return 0;
}
