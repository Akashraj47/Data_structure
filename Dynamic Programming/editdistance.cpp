#include <bits/stdc++.h>
using namespace std;
// Memoization---->
// int editdistance(int n,int m,string s,string t,vector<vector<int> > &dp){
//         if(n == 0 || m == 0){
//             return max(n,m);
//         }
//         if(s[n-1] == t[m-1]){
//             return dp[n][m] = 0 + editdistance(n-1,m-1,s,t,dp);
//         }
//         if(dp[n][m] != -1){
//             return dp[n][m];
//         }
//         int in = 0,de = 0,re = 0;
//         in = 1 + editdistance(n,m-1,s,t,dp);
//         de = 1 + editdistance(n-1,m,s,t,dp);
//         re = 1 + editdistance(n-1,m-1,s,t,dp);
//         return dp[n][m] = min(in,min(de,re)) ;

//     }
// int main(){
//     string s  , t;
//     cout << "Enter 1st strings:- ";
//     cin >> s;
//     cout << "Enter 2nd strings:- ";
//     cin >> t;
//     int n = s.size();
//     int m = t.size();
//     vector<vector<int> > dp (n+1,vector<int>(m+1,-1));
//     int res = editdistance(n,m,s,t,dp);
//     cout << res;
//     return 0;
// }

// Tabuation--->
int main()
{
    string s, t;
    cout << "Enter 1st strings:- ";
    cin >> s;
    cout << "Enter 2nd strings:- ";
    cin >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < m + 1; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {

            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int in = 0, de = 0, re = 0;
                in = dp[i][j - 1];
                de = dp[i - 1][j];
                re = dp[i - 1][j - 1];
                dp[i][j] = min(in, min(de, re)) + 1;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
