// problem statement

// Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

// Note:
//         1. All numbers will be positive integers.
//         2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//         3. The combinations themselves must be sorted in ascending order.


// Example 1:

// Input:
// N = 4
// arr[] = {7,2,6,5}
// B = 16
// Output:
// (2 2 2 2 2 2 2 2)
// (2 2 2 2 2 6)
// (2 2 2 5 5)
// (2 2 5 7)
// (2 2 6 6)
// (2 7 7)
// (5 5 6)

// source code

#include<bits/stdc++.h>
using namespace std;

void func(int pt,vector<int>&candidates,int target,vector<vector<int>>&ways,vector<int>&temp,int pick){
    if(target == 0){
        ways.push_back(temp);
        if(pick == 1){
            temp.pop_back();
        }
    }
    else if(pt >= candidates.size()){
        if(pick == 1){
            temp.pop_back();
        }
    }
    else{
        func(pt+1,candidates,target,ways,temp,0);
        if(target >= candidates[pt]){
            temp.push_back(candidates[pt]);
            func(pt,candidates,target-candidates[pt],ways,temp,1);
        }
        if(pick == 1){
            temp.pop_back();
        }
    }
}

int main(){
    int target;
    cout << "Enter target:- ";
    cin >> target;
    int n;
    cout << "Enter size of candidates array:- ";
    cin >> n;
    vector<int>candidates(n,0);
    cout << "Enter candidates\n";
    for(int i = 0;i<n;i++){
        cin >> candidates[i];
    }
    sort(candidates.begin(),candidates.end());
    vector<int>temp;
    vector<vector<int>>ways;
    func(0,candidates,target,ways,temp,-1);

    cout << "ways of reaching target are:- \n";
    sort(ways.begin(),ways.end());
    for(int i = 0;i<ways.size();i++){
        for(int j = 0;j<ways[i].size();j++){
            cout << ways[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
