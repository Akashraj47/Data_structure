// unbounded coin change problem

#include <bits/stdc++.h>
using namespace std;
// Meomoization----------->
// int coinchange(int index,int t,int s[],int dp[][100]){
//     if(index == 0){
//         if(t % s[index] == 0){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     if(dp[index][t] != -1){
//         return dp[index][t];
//     }
//     int in = 0,out;
//     out = coinchange(index-1,t,s,dp);
//     if(t >= s[index]){
//         in = coinchange(index,t-s[index],s,dp);
//     }
//     return dp[index][t] = in + out;
// }
// int main(){
//     int n = 10,m = 4;
//     int s[m] = {2,5,3,6};
//     int dp[100][100];
//     for (int i = 0;i<100;i++){
//         for (int j = 0;j<100;j++){
//             dp[i][j] = -1;
//         } 
//     }
//     int res = coinchange(m-1,n,s,dp);
//     cout << res;
//       return 0;
// }


// Tabulation--------->
int main(){
    int n = 10,m = 4;
    int s[m] = {2,5,3,6};
    vector<vector<int> >v (m , vector<int> (n+1)); 
    for(int i = 0;i<n+1;i++){
        if(i % s[0] == 0){
            v[0][i] = 1;
        }
        else{
            v[0][i] = 0;
        }
    }
    for(int i = 1;i<m;i++){
        for(int j = 0;j<n+1;j++){
            int out = v[i-1][j];
            int in = 0;
            if(j >= s[i]){
                in = v[i][j-s[i]];
            }
            v[i][j] = in + out;
        }
    }
    cout << v[m-1][n];
    return 0;
}
