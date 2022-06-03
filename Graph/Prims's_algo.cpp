/* Code for prim's algorithm */

#include<bits/stdc++.h>
using namespace std;
void add_edge(int p,int q,int w,vector<pair<int,int> >arr[]){
    arr[p].push_back({q,w});
    arr[q].push_back({p,w});
}
int min(int cost[],int v,bool mst[]){
    int k = INT_MAX;
    int index;
    for(int i = 0;i<v;i++){
        if(mst[i] != true){
            if(cost[i] < k){
                k = cost[i];
                index = i;
            }
        }
    }
    return index;
}
vector<pair<int,pair<int,int> > > MST(vector<pair<int,int>>arr[],int v,int *tcost){
    vector<pair<int , pair<int,int> > >p;
    int parent[v];
    bool mst[v];
    int cost[v];
    cost[0] = -1;
    for(int i = 1;i<v;i++){
        cost[i] = INT_MAX;
    }
    for(int i = 0;i<v;i++){
        int k = min(cost,v,mst);
        mst[k] = true;
        for(vector<pair<int,int>>::iterator it = arr[k].begin();it != arr[k].end(); it++){
            if(mst[(*it).first] != true){
                if((*it).second < cost[(*it).first]){
                    cost[(*it).first] = (*it).second;
                    parent[(*it).first] = k;
                }
            }
        }
    }
    for(int i = 0;i<v;i++){
        if(cost[i] != -1){
            *tcost += cost[i];
            p.push_back({cost[i],{i,parent[i]}});
        }
    }
    return p;

}
int main(){
    vector<pair <int , pair<int , int > > > p;
    int v,e,cost = 0;
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
    p = MST(arr,v,&cost);
    cout << endl;
    cout << "Minimal spanning tree is:- " << endl;
    for(vector<pair<int,pair<int,int> > >::iterator it = p.begin();it != p.end();it++){
        cout << (*it).second.first << " " << (*it).second.second << " --> " << (*it).first << endl;
    }
    cout << "Cost of Minimal spanning tree is:- " << cost << endl;
    return 0;
}
