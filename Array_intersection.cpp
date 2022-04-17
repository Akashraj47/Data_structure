// Code to find Intersection of array

#include<bits/stdc++.h>
using namespace std;
int find_big(int *a,int *b,int n,int m)
{
    int big = a[0];
    for(int i=1;i<n;i++){
        if(big < a[i]){
            big = a[i];
        }
    }
    for(int i=0;i<m;i++){
        if(big < b[i]){
            big = b[i];
        }
    }
    return big;
}
vector<int> intersection(int *a,int *b,int n,int m){
    int big = find_big(a,b,m,n);
    vector<int> v;
    int c[big+1] = {0};
    for(int i=0;i<n;i++){
        if(c[a[i]] != 1){
            c[a[i]] = 1;
        }
    }
    for(int i=0;i<m;i++){
        if(c[b[i]] == 1){
            c[b[i]]++;
        }
    }
    for(int i = 0;i<=big;i++){
        if(c[i] > 1){
            v.push_back(i);
        }
    }
    return v;
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter size of array:-> ";
    cin >> n;
    int a[n];
    cout << "Enter elements in 1st Array:- ";
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int m;
    cout << "Enter size of 2nd array:-> ";
    cin >> m;
    int b[m];
    cout << "Enter elements in 1st Array:- ";
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    vector<int> v;
    v = intersection(a,b,n,m);
    cout << "Intersection:- ";
    for(int i : v){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
