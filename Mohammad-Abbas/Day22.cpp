#include <bits/stdc++.h>
using namespace std;
int longestcommonsubsequence(string &a,string &b,string &c,int i,int j,int k){
    if(i==a.length()) return 0;
      if(j==b.length()) return 0;
        if(k==c.length()) return 0;
int length=0;
        if(a[i]==b[j] && b[j]==c[k]){
          length=1+longestcommonsubsequence(a,b,c,i+1,j+1,k+1);

        }
        else {
            length=max(
              {  longestcommonsubsequence(a,b,c,i+1,j,k),
                longestcommonsubsequence(a,b,c,i,j+1,k),
                longestcommonsubsequence(a,b,c,i,j,k+1)
         } );
        }
        return length;

} 
int main(){
    string a ="abcd1e2";
    string b="bc12ea";
    string c="bd1ea";
    int ans=longestcommonsubsequence(a, b ,c,0,0,0);
cout<<ans;
}