#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>arr[],int source,int destination,bool visited[],vector<int>&path){
    visited[source] = true;
    path.push_back(source);
    if(source == destination){
        return true;
    }
    for(vector<int>::iterator it = arr[source].begin();it != arr[source].end();it++){
        if(visited[*it] != true){
            if(dfs(arr,*it,destination,visited,path)){
                return true;
            }
        }
    }
    return false;

}
void add_edge(vector<int>arr[],int p,int q){
    arr[p].push_back(q);
    arr[q].push_back(p);
}
int main(){
    vector<int>path;
    int n,e;
    cout << "Enter total number of vertices:- ";
    cin >> n ;
    vector<int>arr[n];
    bool visited[n];
    cout << "Enter total number of edges:- ";
    cin >> e;
    for(int i = 0;i<e;i++){
        int p,q;
        cout << "Enter 2 vertices to connect:- ";
        cin >> p >> q;
        add_edge(arr,p,q);
    }
    
    cout << "Enter source and destination vertices to check path:- ";
    int source,destination;
    cin >> source >> destination ;
    if(dfs(arr,source,destination,visited,path) == false){
        cout << "No such Path Exist";
    }
    else{
        cout << "YES Path Exist :- ";
        for(int i = 0;i<path.size();i++){
            if(i != path.size()-1){
                cout << path[i] << " --> ";
            }
            else{
                cout << path[i];
            }
            
        }
    }
    return 0;

}