#include <bits/stdc++.h>
using namespace std;
void add_edge_undirected(vector<int> a[], int u, int v)
{
    a[u].push_back(v);
    a[v].push_back(u);
}
int dfs(vector<int> a[], int u, bool visited[], int p)
{
    visited[u] = true;
    for (vector<int>::iterator it = a[u].begin(); it < a[u].end(); it++)
    {
        if (visited[*it] != true)
        {
            if (dfs(a, *it, visited, u))
            {
                return 1;
            }
        }
        else if (*it != p)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int V, E;
    cout << "Enter total vertices:- ";
    cin >> V;
    cout << "Enter total Edges:- ";
    cin >> E;
    vector<int> a[V];
    bool visited[V];
    for (int i = 0; i < E; i++)
    {
        int p, q;
        cout << "Enter 2 nodes to connect:- ";
        cin >> p >> q;
        add_edge_undirected(a, p, q);
    }
    int c = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] != 1)
        {
            c = dfs(a, i, visited, -1);
            if (c == 1)
                break;
        }
    }
    if (c == 1)
    {
        cout << "Cycle Detected";
    }
    else
    {
        cout << "Cycle not detected";
    }
}
