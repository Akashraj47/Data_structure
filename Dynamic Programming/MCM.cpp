#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int mcm(vector<int>mat,int i,int j){
    if(i >= j){
        return 0;
    }
    int minm = 1e9;
    for(int k = i;k<j;k++){
        int temp = temp = mcm(mat,i,k) + mcm(mat,k+1,j) + (mat[i-1]*mat[k]*mat[j]);
        minm = min(minm,temp);
    }
    return minm;
}
int main(){
    int n;
    cout << "Enter size of array:- ";
    cin >> n;
    vector<int>mat(n,0);
    cout << "Enter array:- ";
    for(int i = 0;i<n;i++){
        cin >> mat[i];
    }
    int res = mcm(mat,1,n-1);
    cout << "Minimum cost of multiplication is:- " << res ;
    return 0;
}