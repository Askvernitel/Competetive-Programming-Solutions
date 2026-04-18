#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[1000][1000];
int am = 0;
void dfs(int r, int c, int val, set<pair<int,int>>& vis){ 
	if(r < 0 || r >= n || c < 0 || c >= m || (vis.find({r,c}) != vis.end()) ||( a[r][c] != val)){ 
		return;
	}
	am++;
	vis.insert({r,c});
	dfs(r+1, c, val, vis);
	dfs(r, c+1, val, vis);
	dfs(r-1, c, val, vis);
	dfs(r, c-1, val, vis);
}

void solve(){
	cin >> n >> m;
	set<pair<int,int>> vis;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> a[i][j];
		}
	}

	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			dfs(i, j, a[i][j], vis);
			if(am != 0) mp[a[i][j]]=max(am, mp[a[i][j]]);
			am=0;
		}
	}
	int maxv =0;
	int ans = 0;
	for(auto &[p1,p2]:mp){
		int k = min(2, p2);
		maxv = max(maxv,k);
		ans+=k;	
	}
	cout << ans -maxv<<  '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();

}
