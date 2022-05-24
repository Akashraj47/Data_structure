// C++ Code for detect cycle in undirected Graph by set method

#include <bits/stdc++.h>
using namespace std;
int find(int k,int parent[]){
	if(parent[k] == -1)
		return k;
	return find(parent[k],parent);
}
bool union_(int p,int q,int parent[]){
	int r1,r2;
	r1 = find(p,parent);
	r2 = find(q,parent);
	if(r1 == r2)
		return true;
	parent[r1] = r2;
	return false;
}
bool detect_cycle(vector<pair<int,int> > A,int v,int e){
	int parent[v];
	for(int i = 0;i<v;i++)
		parent[i] = -1;
	for(int i = 0;i < e;i++){
		int x = A[i].first;
		int y = A[i].second;
		if(union_(x,y,parent)){
			return true;
		}
	}
	return false;
}
int main(){
	int v,e;
	cout << "Enter number of vertices:- ";
	cin >> v;
	cout << "Enter number of edges:- ";
	cin >> e;
	vector<pair <int , int > > A;
	for(int i = 0;i<e;i++){
		int p,q;
		cout << "Enter 2 vertices to connect:- ";
		cin >> p >> q;
		A.push_back(make_pair(p,q));
	}
	for(int i = 0;i<e;i++){
		cout << A[i].first << " " << A[i].second << endl;
	}
	if(detect_cycle(A,v,e))
		cout << "Cycle Detected" << endl;
	else
		cout << "Cycle not detected" << endl;
	return 0;
}
