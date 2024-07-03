#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r)
{

    int s1 = m - l + 1;

    int s2 = r - m;
 

    

    int left[s1];

    int right[s2];
 

    

    for (int i = 0; i < s1; i++)

        left[i] = a[l + i];
 

  

    for (int j = 0; j < s2; j++)

        right[j] = a[j + m + 1];
 

    int i = 0, j = 0, k = l;
 

    while (i < s1 && j < s2) {
 


        if (left[i] <= right[j]) {

            a[k] = left[i];

            i++;

        }
 

      

        else {

            a[k] = right[j];

            j++;

        }

        k++;

    }
 

    

    while (i < s1) {

        a[k] = left[i];

        i++;

        k++;

    }
 

    

    while (j < s2) {

        a[k] = right[j];

        j++;

        k++;

    }
}
 


void mergesort(int arr[], int l, int r)
{

    if (l < r) {
 

       

        int mid = l + (r - l) / 2;
 

        

        mergesort(arr, l, mid);

        mergesort(arr, mid + 1, r);
 

        

        merge(arr, l, mid, r);

    }
}
 


void sortlastMElements(int arr[], int N,

                       int M)
{

    int s = M + N - 1;
 

    

    mergesort(arr, N, s);
 

    

    merge(arr, 0, N - 1, N + M - 1);
 

    

    for (int i = 0; i < N + M; i++)

        cout << arr[i] << " ";
}
 


int main()
{

    int N = 3;

    int M = 5;

    int arr[] = { 2, 8, 10, 17, 15,

                  23, 4, 12 };

    sortlastMElements(arr, N, M);
 

    return 0;
}