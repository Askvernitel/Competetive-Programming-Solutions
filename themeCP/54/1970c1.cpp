#include <bits/stdc++.h>

using namespace std;
vector<int> neigh[200001];
int p;
int dfs(int cur,int par, int depth){
	if(neigh[cur].size() <= 1) return depth%2;
	int u=0;
	for(int x:neigh[cur]){
		if(x == par) continue;
		u= (u|dfs(x, cur, depth+1));
	}
	return u;
}
int main(){
	int n, t;
	cin >> n >> t;

	for(int i =0;i<n-1;i++){
		int u, v;
		cin >> u >> v;
		neigh[--u].push_back(--v);
		neigh[v].push_back(u);
	}
	cin >> p;
	p--;
	cout << ((dfs(p,-1,0))?"Ron":"Hermione") << '\n';
	
}
