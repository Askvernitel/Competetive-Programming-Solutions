#include <bits/stdc++.h>
#define int long long
using namespace std;
int dfs(int cur, int par, map<int, vector<int>>& children, map<int, int>& pos){
	if(children[cur].size() == 0 || (children[cur].size() <= 1 && children[cur][0] == par)){
		pos[cur] = 1;
		return 1;
	}
	int ans = 0;	
	for(int child:children[cur]){ 
		if(child == par) continue;
		ans+=dfs(child, cur, children, pos);
	}
	pos[cur] = ans;

	return ans;
}
void solve(){
	int n;
	cin >> n;
	map<int, vector<int>> children;
	map<int, int> pos;
	for(int i =0;i<n-1;i++){
		int u,v;
		cin >>u >>v;
		children[u].push_back(v);
		children[v].push_back(u);
	}
	dfs(1, -1, children, pos);
	int q;
	cin >> q;
	while(q--){ 
		int x, y;
		cin >> x >> y;

		cout << pos[x]*pos[y] << '\n';
	}
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
