// BFS for connected graph

#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int> a[],int u,int v){
	a[u].push_back(v);
	a[v].push_back(u);
}
void bfs(vector<int> a[],int u,int n){
	queue<int> q;
	int v[n] = {0};
	q.push(u);
	v[u] = 1;
	while(q.empty() != 1){
		int x = q.front();
		for(vector<int>::iterator it = a[x].begin();it<a[x].end();it++){
			if(v[*it] == 0){
				q.push(*it);
				v[*it] = 1;
			}
		}
		cout << x << " ";
		q.pop();
		
	}
}
int main(){
	int n;
	cout << "Enter total number of vertics:- ";
	cin >> n;
	vector<int> a[n];
	addedge(a,0,1);
	addedge(a,1,2);
	addedge(a,2,3);
	vector<int>:: iterator it;
	/*for(int i = 0;i<n;i++){
		for(it=a[i].begin();it<a[i].end();it++){
			cout << *(it) << " ";
		}
		cout << endl;
	}*/
	cout << "BFS TRAVERSAL :- ";
	bfs(a,2,n);
}
