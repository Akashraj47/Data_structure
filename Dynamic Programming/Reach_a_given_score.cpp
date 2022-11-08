// Question:- 
// Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

// Example:
// Input
// 3
// 8
// 20
// 13
// Output
// 1
// 4
// 2

// Explanation
// For 1st example when n = 8
// { 3, 5 } and {5, 3} are the 
// two possible permutations but 
// these represent the same 
// cobmination. Hence output is 1.

// code:- 

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

long long int memoization(long long int n,vector<int>&p,int pt,vector<vector<long long int>>&dp){
    if(n == 0){
        return 1;
    }
    if(pt > 2){
        return 0;
    }
    if(dp[pt][n] != -1){
        return dp[pt][n];
    }
    long long int op1 = 0,op2 = 0;
    op1 += memoization(n,p,pt+1,dp);
    if(n >= p[pt]){
        op2 += memoization(n-p[pt],p,pt,dp);
    }
    return dp[pt][n] = op1+op2;
}

long long int tabulation(long long int n){
    vector<int>pt(3,0);
    pt[0] = 3;
    pt[1] = 5;
    pt[2] = 10;
    vector<vector<int>>dp(4,vector<int>(n+1,0));
    for(int i = 0;i<4;i++){
        dp[i][0] = 1;
    }
    for(int i = 1;i<4;i++){
        for(int j = 1;j<n+1;j++){
            int op1 = dp[i-1][j];
            int op2 = 0;
            if(j >= pt[i-1]){
                op2 = dp[i][j-pt[i-1]];
            }
            dp[i][j] = op1 + op2;
        }
    }
    return dp[3][n];
}

long long int count(long long int n)
{
    // Memoization
    // vector<vector<long long int>>dp(3,vector<long long int>(n+1,-1));
    // vector<int>p(3,0);
    // p[0] = 3;
    // p[1] = 5;
    // p[2] = 10;
    // long long res = 0;
    // res = memoization(n,p,0,dp);
    
    // Tabulation
    long long int res = 0;
    res = tabulation(n);
    return res;
}

int main()
{
  cout << "Enter goal:- ";
	ll n;
	cin>>n;
	cout<<count(n)<<endl;
	return 0;
}
