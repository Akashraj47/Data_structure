// Insertion sort

#include<bits/stdc++.h>
using namespace std;
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
    for(i = 1;i<n;i++){
        int key = arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j] > key){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        if(i != j+1){
            arr[j+1] = key;
        }
    }
    cout << "Sorted array is:- ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
