#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,m;
	cin >>n  >> m;
	int grid[n+2][m+2];
	memset(grid, 0, sizeof(grid));
	for(int i=0;i<=n;i+=4){
		for(int j=1;j<=m;j+=4){
			if(i-1 >= 0){
				grid[i-1][j]=1;
				grid[i-1][j+1]=1;
			}
			grid[i][j] = 1;
			grid[i][j+1]=1;
		}
	}
	for(int j=0;j<=m;j+=4){
		for(int i=1;i<=n;i+=4){
			if(j-1 > 0){
				grid[i][j-1]=1;
				grid[i+1][j-1]=1;
			}
			grid[i][j] = 1;
			grid[i+1][j]=1;
		}
	}
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
