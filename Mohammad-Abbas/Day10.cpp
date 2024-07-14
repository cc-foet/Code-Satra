#include <iostream>
using namespace std;
int factorial(int n){int factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i;
    }
    return factorial;
}
int main(){
int arr[]={4,5,7};
int n=3;
    //Using Catalan Number 2n!/n!*(n+1)!
int ans=factorial(2*n)/(factorial(n)*factorial(n+1));
cout<<"Number of Binary Trees are:"<<ans<<endl;
return 0;

}