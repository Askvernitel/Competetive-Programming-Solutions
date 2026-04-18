#include <bits/stdc++.h>

using namespace std;


int dfs(set<int>& vis,map<int,int>& m, int s, int d){
	if(vis.find(s) != vis.end()){
		return d;
	}
	vis.insert(s);

	return dfs(vis, m,m[s],d+1);
}
void solve(){
	int n;
	cin >>n;
	map<int,int> m;
	int p[n], d[n];
	for(int i=0;i<n;i++){
		cin >> p[i];
		m[p[i]]=i+1;
	}
	for(int i=0;i<n;i++) cin >> d[i];

	int t[n];
	set<int> vis;
	memset(t, 0,sizeof(t));
	int prev = 0;	
	for(int i =0;i<n;i++){
		int u = prev + dfs(vis,m,d[i], 0);
		cout << u << " ";
		prev = u;
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
