
#include <bits/stdc++.h>
using namespace std;
bool lemonadechange(int bills[],int n){
    int five=0,ten=0;
    for(int i=0;i<n;i++){
if(bills[i]==5){
    five++;
}
else if(bills[i]==10){
    if(five>=1)
    {ten++;
    five--;}
    else {return false;}
}
else {
    if(five>0 && ten>0){
        ten--;five--;
    }
    else if(five>2){
five-=3;
    }
    else {return false;}
}
    }
    return true;
}
int main(){
int bills[]={5,5,5,10,20};
int n=5;
int ans=lemonadechange(bills,n);
  if(ans==1){
   cout<<"True";
  }
  else {cout<<"False";}
}