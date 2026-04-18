#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, m;

	cin >> n >> m;
	char grid[n][m];
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	

	char new_grid[n][m];	
	memset(new_grid, '.', sizeof(new_grid));
	for(int j=0;j<m;j++){
		int cnt = 0;
		for(int i =0;i<=n;i++){
			if(grid[i][j] == 'o' || i == n ){

				for(int v = i-cnt;v<i;v++){
					new_grid[v][j] = '*';
				}
				cnt=0;
			}
			if(grid[i][j] == '*'){
				cnt++;
			}
			if(grid[i][j] == 'o' || grid[i][j] == '.'){
				new_grid[i][j] = grid[i][j];
			}
		}

	}
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			cout << new_grid[i][j];
			
		}
		cout << '\n';
	}
}
int main(){	
	int tc;
	cin >> tc;
	while(tc--) solve();	
}
