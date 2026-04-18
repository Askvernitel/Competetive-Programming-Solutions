#include <bits/stdc++.h>

#define int long long
using namespace std;
void solve(){
	int n, m;
	cin >> n >>m ;
	int a[n], b[m];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<m;i++){
		cin >> b[i];
	}

	for(int i =0;i<m;i++){
		int minv = a[0], idx = 0;
		for(int j = 1;j<n;j++){
			if(minv > a[j]){
				minv = a[j];
				idx = j;
			}
		}
		a[idx] = b[i];
	}
	int ans = 0;
	for(int i =0;i<n;i++){
		ans+=a[i];
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
