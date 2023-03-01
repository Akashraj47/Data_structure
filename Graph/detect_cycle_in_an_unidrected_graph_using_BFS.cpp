#include <bits/stdc++.h>
using namespace std;

    // Function to detect cycle in an undirected graph.
    bool dfs(int V,int sc,vector<bool>&visited,vector<int>adj[],int p){
        visited[sc] = true;
        for(int node : adj[sc]){
            if(visited[node] != true){
                if(dfs(V,node,visited,adj,sc)) return true;
            }
            else if(node != p) return true;
        }
        return false;
    }
    bool bfs(int V,int sc,vector<int>adj[]){
        queue<int>q;
        vector<bool>visited(V,false);
        vector<int>parent(V,-1);
        parent[sc] = sc;
        q.push(sc);
        visited[sc] = true;
        while(q.empty() != 1){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(visited[v] == false){
                    parent[v] = u;
                    q.push(v);
                    visited[v] = true;
                }
                else if(v != parent[u]) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i = 0;i<V;i++){
            if(visited[i] != true){
                if(bfs(V,i,adj)) return true;
            }
        }
        return false;
    }
int main() {
    cout << "Enter total vertices and edges" << "\n";
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    cout << "Enter 2 vertices to connect them" << "\n"; 
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = isCycle(V, adj);
    if (ans)
        cout << "Cycle Presnt\n";
    else
        cout << "No Cycle present\n";
    return 0;
}