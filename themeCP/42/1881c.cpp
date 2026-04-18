#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	char a[n][n];
	for(int i =0;i<n;i++){
		for(int j = 0;j<n;j++){
			cin >> a[i][j];
		}
	}
	int ans= 0;
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++){
			char maxv=max({a[i][j], a[n-i-1][n-j-1], a[j][n-i-1], a[n-j-1][i]});
			ans+=(maxv-a[i][j]);
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
