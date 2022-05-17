// BFS traversal code for directed , undirected , directed disconnected , undirected disconnected Graph

#include <bits/stdc++.h>
using namespace std;
void add_edge_directed(vector<int> a[], int u, int v)
{
    a[u].push_back(v);
}
void add_edge_undirected(vector<int> a[], int u, int v)
{
    a[u].push_back(v);
    a[v].push_back(u);
}
void bfs(vector<int> a[], int u, bool visited[], queue<int> q)
{
    q.push(u);
    visited[u] = true;
    while (q.empty() != 1)
    {
        int x = q.front();
        for (vector<int>::iterator it = a[x].begin(); it < a[x].end(); it++)
        {
            if (visited[*it] != true)
            {
                q.push(*it);
                visited[*it] = true;
            }
        }
        cout << x << " ";
        q.pop();
    }
}
int main()
{
    cout << "Press 1 for directed graph or any other for undirected graph:- ";
    int choice;
    cin >> choice;
    int V, E;
    cout << "Enter total vertices:- ";
    cin >> V;
    cout << "Enter total Edges:- ";
    cin >> E;
    vector<int> a[V];
    // for directed graph
    if (choice == 1)
    {
        for (int i = 0; i < E; i++)
        {
            int p, q;
            cout << "Enter source and destiny node:- ";
            scanf("%d%d", &p, &q);
            add_edge_directed(a, p, q);
        }
    }
    // for undirected graph
    else
    {
        for (int i = 0; i < E; i++)
        {
            int p, q;
            cout << "Enter 2 nodes to connect:- ";
            cin >> p >> q;
            add_edge_undirected(a, p, q);
        }
    }
    bool visited[V];
    queue<int> q;
    // bfs traversal
    for (int i = 0; i < V; i++)
    {
        if (visited[i] != true)
        {
            bfs(a, i, visited, q);
        }
    }
}
