// QUICK SORT IMPLIMENTATION

#include<bits/stdc++.h>
using namespace std;
int partition(int *arr,int l,int h){
    int pivot = arr[h];
    int i = l-1;
    int j = l;
    for(j=l;j<h;j++){
        if(arr[j] < pivot){
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[++i],arr[h]);
    return i;
}
void quick_sort(int *arr,int l,int h){
    if(l<h){
        int index = partition(arr,l,h);
        quick_sort(arr,l,index-1);
        quick_sort(arr,index+1,h);
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
    quick_sort(arr,0,n-1);
    cout << "Sorted array is:- ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
