// BUBBLE SORT

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter size of array:- ";
    cin >> n;
    int arr[n];
    cout << "Enter data :- ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int flag = 0;
    for(int i=0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                flag = 1;
                swap(arr[j],arr[j+1]);
            }
        }
        if(flag == 0){
            cout << "Array is already sorted"<<endl;
            break;
        }
    }
    cout << "Sorted array is:- ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
