#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	int a[n][m];	
	for(int i =0;i<n;i++) 
		for(int j=0;j<m;j++) cin >> a[i][j];
	int ans = 0;	
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			int sum = 0;
			for(int k = -max(n,m); k<=max(n,m);k++){
				if(j-k >= 0 && j-k < m && i+k <n && i+k>=0){
					sum+=a[i+k][j-k];	
				}
				if(j+k >= m || j+k < 0 || i+k >=n || i+k<0) continue;
				sum+=a[i+k][j+k];
			}
			sum-=a[i][j];
			ans = max(sum, ans);
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
