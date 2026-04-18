#include <bits/stdc++.h>

using namespace std;
int n, m;
char grid[51][51];
int fnd[51][51];
void dfs(int i, int j, int dir){
	if(grid[i][j] == '0' || i >= n || j >= m || j < 0 || i < 0 ){
		return;
	}
	fnd[i][j] = 1;
	if(dir){
		dfs(i+1,j,dir);
	}else{
		dfs(i, j+1,dir);
	}
}

void solve(){
	cin >> n >> m;

	memset(fnd, 0, sizeof(fnd));	
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	for(int i=0;i<n;i++){
		dfs(i,0,0);
	}
	for(int i=0;i<m;i++){
		dfs(0,i,1);
	}
	int p = 0;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(fnd[i][j] == 0 && grid[i][j] == '1'){
				p=1;
			}
		}
	}
	if(p ==0){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
