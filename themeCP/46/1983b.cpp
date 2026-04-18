#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	int a[n][m], b[n][m];
	char grid1[n][m], grid2[n][m];
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> grid1[i][j];
			a[i][j] = grid1[i][j]-48;
		}
	}
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> grid2[i][j];
			b[i][j] = grid2[i][j]-48;
		}
	}
	
	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j] != b[i][j] && (j == m-1 || i == n-1)){
				cout << "NO\n";
				return;
			}
			if(a[i][j] != b[i][j]){
				int v = (3+b[i][j]-a[i][j])%3;
				int v1 = (v == 2)?1:2;
				if(v != 0){
					a[i][j] = (a[i][j] + v)%3;
					a[n-1][m-1] = (a[n-1][m-1]+v)%3;
					a[n-1][j]=(a[n-1][j]+v1)%3;
					a[i][m-1]=(a[i][m-1]+v1)%3;
				}
			}
		}
	}
	cout << "YES\n";

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
	
}
