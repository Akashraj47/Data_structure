#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int LOG = 18;
int st[LOG][MAXN];

// Here it could be anyfunction like add, max, min, AND, OR etc...
int AND(int &a,int &b){
    return (a & b);
}
void calculateSt(vector<int>&v){
    int n = v.size();
    for(int i = 0;i<n;i++){
        st[0][i] = v[i];
    }
    int k = log2(n);
    for(int i = 1;i<=k;i++){
        for(int j = 0;j+(1<<i) <= n;j++){
            st[i][j] = AND(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
}
// process each query in logn time. There is also slight improvement for this algorithm. In some cases we can also process it in constant time.
int processQ(int left,int right){
    int w = (right-left+1);
    int ans = -1;
    int row =0;
    while(w){
        if(w & 1){
            ans = (ans & st[row][left]);
            left += (1 << row);
        }
        row++;
        w = w >> 1;
    }
    return ans ;
}
int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int &i : v) cin >> i;
    calculateSt(v);

    

    for(int i = 0;i<=2;i++){
        for(int j = 0;j<n;j++){
            cout << st[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "**************************\n";
    for(int i = 0;i<5;i++){
        for(int j = i+1;j<5;j++){
            cout << processQ(i,j) << " ";
        }
        cout << "\n";
    }

    return 0;
}
