/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either
x , y or z. Here x, y, and z are integers. After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.

Example 2:

Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
*/

// source code:- 

#include <bits/stdc++.h>
using namespace std;
int memoization(int n, int x, int y, int z, vector<int> &dp)
{
    if (n < 0)
    {
        return INT_MIN;
    }
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
    op1 = memoization(n - x, x, y, z, dp);
    op2 = memoization(n - y, x, y, z, dp);
    op3 = memoization(n - z, x, y, z, dp);

    return dp[n] = max(op1, max(op2, op3)) + 1;
}
int tabulation(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
    for (int i = 1; i < n + 1; i++)
    {
        if (i - x >= 0)
        {
            op1 = dp[i - x];
        }
        if (i - y >= 0)
        {
            op2 = dp[i - y];
        }
        if (i - z >= 0)
        {
            op3 = dp[i - z];
        }
        int res = max(op1, max(op2, op3));
        if (res < 0)
        {
            dp[i] = INT_MIN;
        }
        else
        {
            dp[i] = res + 1;
        }
    }
    return dp[n];
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    if (x == 1 || y == 1 || z == 1)
    {
        return n;
    }
    // memoization-->
    // vector<int> dp(n+1,-1);
    // int res = memoization(n,x,y,z,dp);
    // if(res < 0){
    //     return 0;
    // }
    // return res;

    // Tabulation-->
    int res = tabulation(n, x, y, z);
    if (res < 0)
    {
        return 0;
    }
    return res;
}
int main()
{

    int n;
    cout << "Enter length of line segment:- ";
    cin >> n;

    cout << "Enter x , y , z :- ";
    int x, y, z;
    cin >> x >> y >> z;
    cout << maximizeTheCuts(n, x, y, z) << endl;
    return 0;
}
