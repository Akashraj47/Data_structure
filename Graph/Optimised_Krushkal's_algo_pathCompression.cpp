#include<bits/stdc++.h>
using namespace std;
int find(int i,int parent[]){
    if(parent[i] == -1){
        return i;
    }
    return find(parent[i],parent);
}
bool union_(int i,int j,int parent[],int rank[],int v){
    int r1 = find(i,parent);
    int r2 = find(j,parent);
    if(r1 == r2){
        return true;
    }
    if(rank[r1] > rank[r2]){
        parent[r2] = r1;
    }
    else if(rank[r1] < rank[r2]){
        parent[r1] = r2;
    }
    else{
        parent[r1] = r2;
        rank[r2]++;
    }
    return false;
}
bool detect_loop(pair<int,int>p,int parent[],int rank[],int v){
    if(union_(p.first,p.second,parent,rank,v) == true){
        return true;
    }
    return false;
}
vector<pair<int,pair<int,int>> > MST(vector<pair<int,pair<int,int> > >V,int v,int e,int *cost){
    int rank[v];
    memset(rank,0,sizeof(rank));
    vector<pair<int,pair<int,int> > >p;
    int parent[v];
    for(int i = 0;i<v;i++){
        parent[i] = -1;
    }
    for(int i = 0;i<e;i++){
        if(detect_loop(V[i].second,parent,rank,v) == false){
            *cost += V[i].first;
            p.push_back(V[i]);
        }
    }
    return p;
}
int main(){
    int v,e,cost=0;
    cout << "Enter total vertices:- ";
    cin >> v;
    cout << "Enter total edges:- ";
    cin >> e;
    vector<pair<int,pair<int,int> > > V,p;
    for(int i = 0;i<e;i++){
        int p , q , w;
        cout << "Enter 2 edges to connect :- ";
        cin >> p >> q;
        cout << "Enter weight:- ";
        cin >> w;
        V.push_back({w,{p,q}});
    }
    cout << endl;
    for(int i = 0;i<e;i++){
        cout << V[i].second.first << " " << V[i].second.second << " --> " << V[i].first << endl;
    }
    cout << endl;
    sort(V.begin(),V.end());
    cout << "\n\n";
    p = MST(V,v,e,&cost);
    cout << "Minimal spanning tree is\n" ;
    for(int i = 0;i<p.size();i++){
        cout << p[i].second.first << " " << p[i].second.second << " --> " << p[i].first << endl;
    }
    cout << "Total cost of MST is:- " << cost << endl;
}
