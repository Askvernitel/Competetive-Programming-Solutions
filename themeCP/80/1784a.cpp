#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	sort(a,a+n);

	int t = 1;
	int ans =0;
	for(int i=0;i<n;i++){
		if(a[i] < t){ 
			continue;
		}
		ans += a[i]-t;
		t++;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
