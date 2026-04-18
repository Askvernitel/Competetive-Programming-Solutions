#include <bits/stdc++.h>

using namespace std;
int mark[1001][1001];
char a[1001][1001];
int n, m;
void dfs(int r, int c, set<pair<int,int>>& vis, char dir){
	if(r<0 || c<0 || r >= n || c >= m || vis.find({r,c}) != vis.end() || dir != a[r][c]){
		return;
	}
	mark[r][c] = 1;
	vis.insert({r,c});
	dfs(r+1,c, vis, 'U');
	dfs(r,c+1, vis, 'L');
	dfs(r-1,c, vis, 'D');
	dfs(r, c-1, vis, 'R');

}
void solve(){
	
	cin >> n >> m;
	for(int i = 0;i<n;i++)
		for(int j=0;j<m;j++) mark[i][j] = 0;
	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cin >> a[i][j];
		}
	}
	set<pair<int,int>> vis;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(i == 0){
				dfs(i,j,vis,'U');
			}
			if(j == 0){
				dfs(i,j,vis,'L');
			}
			if(j == m-1){
				dfs(i,j,vis,'R');
			}
			if(i == n-1){
				dfs(i,j,vis,'D');
			}
		}
	}


	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			if(mark[i][j] == 0 && (i+1 ==n || mark[i+1][j] == 1) && (i-1 <0 || mark[i-1][j] ==1) && (j-1 <0 || mark[i][j-1]==1) && (j+1 == m || mark[i][j+1]==1)){
				mark[i][j] = 1;
			}
		}
	}
	int ans =0;
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(mark[i][j] == 0) ans++;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;

	cin >> tc;

	while(tc--) solve();
}
