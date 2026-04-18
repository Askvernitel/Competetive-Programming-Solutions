#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	char grid[n][m];
	for(int i=0;i<n;i++){
		for(int j =0;j<m;j++){
			cin >> grid[i][j];
		}
	}
	int col[m], row[n];
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
	char ans[n][m];
	memset(ans, '.', sizeof(ans));
	char prev = 'B';
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j] != '.'){
				if(grid[i][j] == 'U'){ans[i][j]=prev; prev = (prev=='B')?'W':'B'; ans[i+1][j] = prev;}
				
				row[i]++;
				col[j]++;
			}
		}
	}
	for(int i =0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[j][i] != '.'){
				if(grid[j][i] == 'R'){ans[j][i]=prev; prev = (prev=='B')?'W':'B'; ans[j][i-1] = prev;}
			}
		}
	}
	bool pos=1;
	for(int i =0;i<n;i++){
		if(row[i]%2){ pos=0;break;}
	}
	for(int i =0;i<m;i++){
		if(col[i]%2){pos=0;break;}
	}

	if(!pos){ 
		cout << -1 << '\n';
		return;
	}
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
