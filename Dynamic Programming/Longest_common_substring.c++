
#include <bits/stdc++.h>
using namespace std;

int tabulation(int n, int m, string s1, string s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int MAX = INT_MIN;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                MAX = max(MAX, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
                MAX = max(MAX, dp[i][j]);
            }
        }
    }
    return MAX;
}

int longestCommonSubstr(string S1, string S2, int n, int m)
{

    int res = tabulation(n, m, S1, S2);
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstr(s1, s2, n, m) << endl;
}