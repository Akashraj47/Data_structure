// Find the Union of 2 Array

#include<bits/stdc++.h>
using namespace std;
vector<int> find_union(int *arr,int *brr,int n,int m){
    vector<int> v;
    int big = arr[0];
    for(int i=1;i<n;i++){
        if(big < arr[i]){
            big = arr[i];
        }
    }
    for(int i=0;i<m;i++){
        if(big < brr[i]){
            big = brr[i];
        }
    }
    int crr[big+1] = {0};
    for(int i=0;i<n;i++){
        crr[arr[i]]++;
    }
    for(int i=0;i<m;i++){
        crr[brr[i]]++;
    }
    for(int i = 0;i<=big;i++){
        if(crr[i]){
            v.push_back(i);
        }
    }
    return v;

}
int main(int argc, char const *argv[])
{
    vector<int> v ;
    int n;
    cout << "Enter size of 1st array:- ";
    cin >> n;
    int arr[n];
    cout << "Enter data:- ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter size of 2nd array:- ";
    int m;
    cin >> m;
    int brr[m];
    cout << "Enter data:- ";
    for(int i=0;i<m;i++)
    {
        cin >> brr[i];
    }
    v = find_union(arr,brr,n,m);
    cout << "Union is:- ";
    for(int i:v){
        cout << i << " ";
    }
    return 0;
}
