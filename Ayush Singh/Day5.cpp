#include <iostream>

#include <vector>

using namespace std;

int kthelement(vector<int>&a,vector<int>&b,int m,int n,int k){

    int i=0,j=0;

    vector<int>arr;

    while(i<m && j<n){

         if(a[i]>b[j]){

        arr.push_back(b[j++]);




    }else {

          arr.push_back(a[i++]);

    }




    }

    while(i<m){

        arr.push_back(a[i++]);




    }

    while(j<n){

       arr.push_back(b[j++]);




    }

    return arr[k-1];




}

int main(){

    vector<int>a={2,3,6,7,9};

    vector<int>b={1,4,8,10};

    cout<<"The Kth Element is : "<<kthelement(a,b,a.size(),b.size(),5)<<endl;




}
