#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;

	int a[n+1];

	for(int i =0;i<n;i++) cin >> a[i];
	a[n] = -1;

	int l =0;
	int r =0;
	int ans =0;
	int prev_r = -1;
	for(int r =0;r<=n;r++){
		if(r-l+1 > a[r]){
			int u = (((r-l+1)*(r-l))/2);	
			int p = (((prev_r-l+1)*(prev_r-l))/2);
			ans+=(prev_r == -1)?u:u-p;
			prev_r = r;
		}
		while(r-l+1 > a[r]){
			l++;
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	
	while(tc--) solve();
}
