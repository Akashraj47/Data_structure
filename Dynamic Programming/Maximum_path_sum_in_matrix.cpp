/* 
Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

1. Matrix [r+1] [c]
2. Matrix [r+1] [c-1]
3. Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1

eg:- 
Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

*/

// Source code:- 


#include <bits/stdc++.h>
using namespace std;

    int memoization(int r,int c,int N,vector<vector<int>>Matrix,vector<vector<int> >&dp){
        if(r < 0 || c < 0 || r > N-1 || c > N-1){
            return 0;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        int nt = INT_MIN;
        if(r == 0){
            nt = memoization(r,c+1,N,Matrix,dp);
        }
        int op1 = INT_MIN,op2 = INT_MIN,op3 = INT_MIN;
        op1 = Matrix[r][c] + memoization(r+1,c,N,Matrix,dp);
        op2 = Matrix[r][c] + memoization(r+1,c-1,N,Matrix,dp);
        op3 = Matrix[r][c] + memoization(r+1,c+1,N,Matrix,dp);

        return dp[r][c] = max(nt,max(op1,max(op2,op3)));
    }
    
    int tabulation(int N,vector<vector<int>>Matrix){
        vector<vector<int> >dp(N,vector<int>(N,0));
        for(int i = 0;i<N;i++){
            dp[0][i] = Matrix[0][i];
        }
        for(int i = 1;i<N;i++){
            for(int j = 0;j<N;j++){
                int op1 = INT_MIN,op2 = INT_MIN,op3 = INT_MIN;
                if(i-1>=0 && j-1 >= 0){
                    op1 = Matrix[i][j] + dp[i-1][j-1];
                }
                if(i-1 >= 0){
                    op2 = Matrix[i][j] + dp[i-1][j];
                }
                if(i-1 >= 0 && j+1 <= N-1){
                    op3 = Matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = max(op1,max(op2,op3));
            }
        }
        int res = INT_MIN;
        for(int i = 0;i<N;i++){
            if(dp[N-1][i] > res){
                res = dp[N-1][i];
            }
        }
        return res;
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        // Memoization--->
        vector<vector<int> >dp(N,vector<int>(N,-1));
        int res = memoization(0,0,N,Matrix,dp);
        return res;
        
        // Tabulation--->
        // int res = tabulation(N,Matrix);
        // return res;
    }

int main(){
    int N;
    cout << "Enter size of Matrix:- ";
    cin >> N;
    vector<vector<int>>Matrix;
    for(int i = 0;i<N;i++){
        vector<int> v;
        cout << "Enter row number " << i << ":- ";
        for(int i = 0;i<N;i++){
            int t;
            cin >> t;
            v.push_back(t);
        }
        Matrix.push_back(v);
    }
    cout << maximumPath(N,Matrix);
    return 0;
}
    
