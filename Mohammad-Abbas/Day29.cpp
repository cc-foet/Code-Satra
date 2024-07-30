 #include<bits/stdc++.h>
 using namespace std;
 
 
 int minimumDeletions(string &s) {
    int n=s.length();
    int count=0;
    stack<char>st;
    for(int i=0;i<n;i++){
if(!st.empty() && s[i]=='a' && st.top()=='b'){st.pop();count++;}
else {
    st.push(s[i]);
}
    }
    return count;
 }


 int main(){
    string s="aababbab";
    cout<<"Minimum Deletions to make string balanced "<<minimumDeletions(s);
 }