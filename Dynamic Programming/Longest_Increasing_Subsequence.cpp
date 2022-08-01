#include <bits/stdc++.h>
using namespace std;

int memoization(int n, int arr[], int pre, int curr, vector<vector<int>> &dp)
{
    if (curr == 0)
    {
        return dp[curr][pre - 1] = 0;
    }
    if (dp[curr][pre - 1] != -1)
    {
        return dp[curr][pre - 1];
    }
    int t = 0, nt = 0;
    nt = memoization(n, arr, pre, curr - 1, dp);
    if (pre == n + 1 || arr[curr - 1] < arr[pre - 1])
    {
        t = 1 + memoization(n, arr, curr, curr - 1, dp);
    }
    return dp[curr][pre - 1] = max(t, nt);
}
int tabulation(int n, int nums[])
{
    vector<int> dp(n, 1);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int l = INT_MIN;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j])
            {
                l = max(l, dp[j]);
            }
        }
        if (l != INT_MIN)
        {
            dp[i] = l + 1;
        }
    }
    int l = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        l = max(l, dp[i]);
    }
    return l;
}
int optimised(int n, int nums[])
{
    vector<int> dp;
    vector<int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        if (dp.empty() == 1 || dp[dp.size() - 1] < nums[i])
        {
            dp.push_back(nums[i]);
        }
        else
        {
            it = lower_bound(dp.begin(), dp.end(), nums[i]);
            dp[(it - dp.begin())] = nums[i];
        }
    }
    return dp.size();
}
int longestSubsequence(int n, int a[])
{
    int res;
    // O(n^2)
    //   vector<vector<int> > dp(n+1,vector<int>(n+2,-1));
    //   res = memoization(n,a,n+1,n,dp);

    // O(n^2)
    // res = tabulation(n,a);
    
    // O(nlogn)
    res = optimised(n, a);
    return res;
}
int main()
{
    cout << "Enter size of array:- ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter array:- ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << longestSubsequence(n, a) << endl;
}