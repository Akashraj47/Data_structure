
#include <bits/stdc++.h>

using namespace std;

void add_edges(vector<int>arr[],int p,int q){
    arr[p].push_back(q);
}

bool dfs(vector<int>arr[],int i,bool visited[],bool dvisited[]){
    visited[i] = true;
    dvisited[i] = true;
    for(auto it = arr[i].begin();it != arr[i].end();it++){
        if(visited[(*it)] != true){
            if(dfs(arr,*it,visited,dvisited) == true){
                return true;
            }
        }
        else{
            if(visited[i] == true && dvisited[(*it)] == true){
                return true;
            }
        }
    }
    dvisited[i] = false;
    return false;
}

int main()
{
    int V,E;
    cout << "Enter total vertices:- ";
    cin >> V;
    cout << "Enter total edges:- ";
    cin >> E;
    vector<int>arr[V];
    for(int i = 0;i<E;i++){
        cout << "Enter 2 vertices to connect:- ";
        int p,q;
        cin >> p >> q;
        add_edges(arr,p,q);
    }
    bool visited[V];
    bool dvisited[V];
    int flag = 0;
    for(int i = 0;i<V;i++){
        if(visited[i]!=true){
            if(dfs(arr,i,visited,dvisited) == true){
                flag = 1;
                cout << "Cycle Detected";
                break;
            }
        }
    }
    if(flag == 0){
        cout << "Cycle Not Detected";
    }
    return 0;
}
