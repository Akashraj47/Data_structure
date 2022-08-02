#include <bits/stdc++.h>
using namespace std;

long long memoization(int r, int c, int m, int n, vector<vector<long long>> &dp)
{
    if (r >= m || c >= n)
    {
        return dp[r][c] = 0;
    }
    if (r == m - 1 && c == n - 1)
    {
        return dp[r][c] = 1;
    }
    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }
    int right = (memoization(r, c + 1, m, n, dp) % 1000000007);
    int down = (memoization(r + 1, c, m, n, dp) % 1000000007);
    return dp[r][c] = ((right + down) % 1000000007);
}
long long tabulation(int m, int n)
{
    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long int right = 0;
            long int down = 0;
            if (j - 1 >= 0)
            {
                right = dp[i][j - 1] % 1000000007;
            }
            if (i - 1 >= 0)
            {
                down = dp[i - 1][j] % 1000000007;
            }
            dp[i][j] = (right + down) % 1000000007;
        }
    }
    return dp[m - 1][n - 1];
}
long long optimised(int m, int n)
{
    vector<int> pre(n, 1);
    vector<int> curr(n, 0);
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long right = 0;
            long long down = 0;
            down = pre[j] % 1000000007;
            if (j - 1 >= 0)
            {
                right = curr[j - 1] % 1000000007;
            }
            curr[j] = (right + down) % 1000000007;
        }
        pre = curr;
    }
    return pre[n - 1];
}
long long int numberOfPaths(int m, int n)
{
    // code here
    // Memoization solution-->
    // vector<vector<long long > >dp(m+1,vector<long long>(n+1,-1));
    // long long  res = memoization(0,0,m,n,dp);
    // return res;

    // Tabulation solution-->
    // long long int res = tabulation(m,n);
    // return res;

    // Space optimised solutuon-->
    long long int res = optimised(m, n);
    return res;
}
int main()
{

    int n, m;
    cin >> m >> n;
    cout << numberOfPaths(m, n) << endl;
    return 0;
}
