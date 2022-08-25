/*
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins
{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.

Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin

Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 
Explanation: Use one 6 cent coin
and one 5 cent coin

*/
// Source Code:- 

#include <bits/stdc++.h>
using namespace std;

int space_optimised_tabulation(int coins[], int M, int V)
{
	vector<int> pre(V + 1, 0);
	vector<int> curr(V + 1, 0);
	for (int i = 0; i < V + 1; i++)
	{
		if (i % coins[0] == 0)
		{
			pre[i] = i / coins[0];
		}
		else
		{
			pre[i] = 1e9;
		}
	}
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < V + 1; j++)
		{
			int not_take = pre[j];
			int take = 1e9;
			if (j >= coins[i])
			{
				take = 1 + curr[j - coins[i]];
			}
			curr[j] = min(take, not_take);
		}
		pre = curr;
	}
	return pre[V];
}
int tabulation(int coins[], int M, int V)
{
	vector<vector<int>> dp(M, vector<int>(V + 1, 0));
	for (int i = 0; i < V + 1; i++)
	{
		if (i % coins[0] == 0)
		{
			dp[0][i] = i / coins[0];
		}
		else
		{
			dp[0][i] = 1e9;
		}
	}
	for (int i = 1; i < M; i++)
	{
		for (int j = 1; j < V + 1; j++)
		{
			int not_take = dp[i - 1][j];
			int take = 1e9;
			if (j >= coins[i])
			{
				take = 1 + dp[i][j - coins[i]];
			}
			dp[i][j] = min(take, not_take);
		}
	}
	return dp[M - 1][V];
}
int memoization(int ind, int coins[], int V, vector<vector<int>> &dp)
{
	if (ind == 0)
	{
		if (V % coins[ind] == 0)
		{
			return V / coins[ind];
		}
		else
		{
			return 1e9;
		}
	}
	if (dp[ind][V] != -1)
	{
		return dp[ind][V];
	}
	int take = 1e9, not_take;
	not_take = memoization(ind - 1, coins, V, dp);
	if (V >= coins[ind])
	{
		take = memoization(ind, coins, V - coins[ind], dp) + 1;
	}
	return dp[ind][V] = min(take, not_take);
}
int minCoins(int coins[], int M, int V)
{
	// vector<vector<int> >dp(M+1,vector<int>(V+1,-1));
	// int res = memoization(M-1,coins,V,dp);
	// int res = tabulation(coins,M,V);
	int res = space_optimised_tabulation(coins, M, V);
	if (res >= 1e9)
	{
		return -1;
	}
	else
	{
		return res;
	}
}

int main()
{
  cout << "Enter no. of test cases" << endl;
	int t;
	cin >> t;
	while (t--)
	{
    cout << "Enter value V and size of array " << endl;
		int v, m;
		cin >> v >> m;

		int coins[m];
    cout << "Enter coins" << endl; 
		for (int i = 0; i < m; i++)
			cin >> coins[i];

		cout << minCoins(coins, m, v) << "\n";
	}
	return 0;
}
