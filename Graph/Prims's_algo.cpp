// C++ code for Prim's Algo


#include<bits/stdc++.h>
using namespace std;
void add_edge(int p,int q,int w,vector<pair<int,int> >arr[]){
    arr[p].push_back({q,w});
    arr[q].push_back({p,w});
}
int min(int cost[],bool mst[]){
    int j;
    int m = INT_MAX;
    for(int i = 0;i<v;i++){
        if(mst[i] != true){
            if(cost[i] < m){
                j = i;
            }
        }
    }
    return j;
}
void MST(vector<pair<int,int>>arr[],int v,int e){
    vector<pair<int,int>>p;
    int parent[v];
    int cost[v];
    bool mst[v];
    cost[0] = -1;
    for(int i = 1;i<v;i++){
        cost[i] = INT_MAX;
    }
    parent[0] = -1;
    for(int i = 0;i<v;i++){
        int m = min(cost,mst);
        mst[m] = true;

        for(vector<pair<int,int>>::iterator it = arr[m].begin();it != arr[m].end();it++){
            if(mst[(*it).first] != true){
                // RELAX
                // update weight
                // update parent
            }
        }
    }
}
int main(){
    int v,e;
    cout << "Enter total vrtices:- ";
    cin >> v;
    cout << "Enter total edges:- ";
    cin >> e;
    vector<pair<int,int> >arr[v];
    for(int i = 0;i<e;i++){
        int p,q,w;
        cout << "Enter 2 vertices to connect:- ";
        cin >> p >> q;
        cout << "Enter weight:- ";
        cin >> w;
        add_edge(p,q,w,arr);
    }
    for(int i = 0;i<v;i++){
        cout << i << " --> " << " ";
        for(vector<pair<int,int> > :: iterator it = arr[i].begin();it != arr[i].end();it++){
            cout << (*it).first << " cost = " << (*it).second << " ";
        }
        cout << endl;
    }
    MST(arr,v,e);
}
