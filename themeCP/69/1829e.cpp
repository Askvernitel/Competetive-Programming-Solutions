#include <bits/stdc++.h>

using namespace std;


int n, m;
int a[1001][1001];
int sum =0;
void dfs(int r, int c, set<pair<int,int>>& vis){
	if(r < 0 || c < 0 || c == m || r == n || vis.find({r,c}) != vis.end() || a[r][c] == 0){ 
		return;
	}
	sum+=a[r][c];
	vis.insert({r,c});
	dfs(r+1,c,vis); 
	dfs(r,c+1,vis);
	dfs(r-1,c,vis);
	dfs(r,c-1,vis);
}
void solve(){
	cin >> n >> m;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cin >> a[i][j];
		}
	}
	set<pair<int,int>> vis;
	int ans = 0;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			dfs(i,j,vis);
			ans = max(ans,sum);
			sum=0;
		}
	}
	cout << ans << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
