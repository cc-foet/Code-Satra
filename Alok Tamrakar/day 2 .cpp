// solution of Desorting codeforces 

#include<bits/stdc++.h>
using namespace std;

int isPossible(vector<int>&value){
    int minimum = INT_MAX;
    for(int i =0;i<value.size()-1;i++){
        if(value[i]<=value[i+1]){
            int difference = value[i+1]-value[i];
            minimum = min(minimum,difference);
        }
        else {
            return -1;
        }
    }
    return minimum;
}
int main (){
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>value(n);
        
        for(int i =0;i<n;i++){
            cin>>value[i];
        }
        
        int answer = isPossible(value);
         if(answer ==-1){
                       cout<<0<<endl;
                   }
       
        
         else   if(answer %2 ==0){
                cout<< (answer/2)+1<<endl;
            }
            else if(answer%2 !=0){
                cout<<((answer+1)/2)<<endl;
            }
                  
    }
    return 0;
}
