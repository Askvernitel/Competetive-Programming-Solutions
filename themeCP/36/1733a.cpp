#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	int ans=0;	
	for(int i =0;i<k;i++){
		int cur = 0;
		for(int j =i;j<n;j+=k){
			cur = max(a[j], cur);
		}
		ans += cur;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
