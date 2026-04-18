#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int dfs(int cur,int par, map<int, vector<int>>& g, int ind, int d, map<pair<int,int>, int>& ps){ 
	if(g[cur].size() == 1 ){
		return d;
	}
	int ans = 0;
	for(int child:g[cur]){ 
		if(child == par) continue;
		int k = ps[{cur,child}];
//		cout << k << '\n';
		int cof =0;
		if(k < ind){ 
			cof=1;
		}
		ans = max(dfs(child, cur, g, k, d+cof, ps),ans);
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	map<pair<int,int>, int> ps;
	map<int, vector<int>> g;	
	pair<int,int> a[n-1];
	for(int i=0;i<n-1;i++){
		cin >> a[i].F >> a[i].S;
		g[a[i].F].push_back(a[i].S);
		g[a[i].S].push_back(a[i].F);
		ps[a[i]]=i+1;
		ps[{a[i].S, a[i].F}]=i+1;
	}
	g[1].push_back(0);
	cout << dfs(1, 0, g, 0,1, ps) << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
