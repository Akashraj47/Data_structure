#include <bits/stdc++.h>
using namespace std;
int memoization(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int op1 = 0, op2 = 0;
    if (n >= 1)
    {
        op1 = memoization(n - 1, dp);
    }
    if (n >= 2)
    {
        op2 = memoization(n - 2, dp);
    }
    return dp[n] = (op1 + op2);
}
int tabulation(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int op1 = 0, op2 = 0;
        if (i >= 1)
        {
            op1 = dp[i - 1];
        }
        if (i >= 2)
        {
            op2 = dp[i - 2];
        }
        dp[i] = (op1 + op2);
    }
    return dp[n];
}
int main()
{
    int n;
    cout << "Enter n:- ";
    cin >> n;

    // Memoization-->
    // vector<int> dp(n + 1, -1);
    // int res = memoization(n, dp);
    // cout << res << endl;

    // Tabulation-->
    int res = tabulation(n) ;
    cout << res << endl;
}
