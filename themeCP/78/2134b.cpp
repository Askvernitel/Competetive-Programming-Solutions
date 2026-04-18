#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;


	cin >> n >> k;

	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int ans[n];
	for(int i =0;i<n;i++){
		int m = a[i]%(k+1);

		ans[i] = a[i] + k*(m);
	}

	for(int i=0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
