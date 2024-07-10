// Solving the challenge for Day 7

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

bool checkUsingStack(string& str){
    stack<char> s;
    queue<char> q;
    for(int i=0 ; i<str.length() ; i++){
        s.push(str[i]);
        q.push(str[i]);
    }
    while(!s.empty()){
        if(s.top() != q.front()){
            return false;
        }
        s.pop();
        q.pop();
    }
    return true;
}

int main(){
    string s1 = "CodeSatra";
    if(checkUsingStack(s1)){
        cout<<"Yes its a palindrome"<<endl;
    }else{
        cout<<"No its not a palindrome"<<endl;
    }

    string s2 = "assa";
    if(checkUsingStack(s2)){
        cout<<"Yes its a palindrome"<<endl;
    }else{
        cout<<"No its not a palindrome"<<endl;
    }
}

// Output
// No its not a palindrome
// Yes its a palindrome