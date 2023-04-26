// Longest Pallindromic Substring
// Leetcode - https://leetcode.com/problems/longest-palindromic-substring/description/
// Youtube Reference - https://www.youtube.com/watch?v=UflHuQj6MVA


#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    int max_len = 0;
    int left_ind = 0,right_ind = 0;
    for(int i = 0;i<n;i++){
        dp[i][i] = true;
    }
    for(int i = 0;i<n-1;i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
            max_len = 2;
            left_ind = i;
            right_ind = i+1;
        }
    }
    for(int i = 2;i<n;i++){
        int j = i;
        int k = 0;
        while(k < n and j < n){
            if(s[k] == s[j] and dp[k+1][j-1] == true){
                dp[k][j] = true;
                if((j - k + 1) > max_len){
                    max_len = (j - k + 1);
                    left_ind = k;
                    right_ind = j;
                }
            }
            k++;
            j++;
        }
    }
    string ans;
    for(int i = left_ind;i<=right_ind;i++){
        ans += s[i];
    }
    return ans;
}
int main(){
    string s ;
    cout << "Enter a String:- ";
    cin >> s;
    cout << longestPalindrome(s);
}
