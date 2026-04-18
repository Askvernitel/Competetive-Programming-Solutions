#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	int sum = 0;
	int maxv=a[0];
	sum = 0;
	int ans = 0;
	for(int i =0;i<n;i++){	
		maxv = max(maxv, a[i]);	
		sum+=a[i];
		if(sum-maxv==maxv){ 
			ans++;
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
