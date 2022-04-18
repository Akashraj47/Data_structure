// Counting sort

#include<bits/stdc++.h>
using namespace std;
int find_big(int *arr,int n){
    int big = arr[0];
    for(int i=0;i<n;i++){
        if(big < arr[i]){
            big = arr[i];
        }
    }
    return big;
}
void counting_sort(int *arr,int n){
    int big = find_big(arr,n);
    int pos;
    int a[big+1] = {0};
    int c[n];
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    // Cummulative sum
    for(int i=1;i<=big;i++){
        a[i] = a[i] + a[i-1];
    }
    for(int i=n-1;i>=0;i--){
        pos = a[arr[i]];
        c[pos-1] = arr[i];
        a[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = c[i];
    }
}
int main(int argc, char const *argv[])
{
    int n,i,j;
    cout << "Enter size of array:- ";
    cin >> n;
    int arr[n];
    cout << "Enter array:- ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    counting_sort(arr,n);
    cout << "Sorted array is:- ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
