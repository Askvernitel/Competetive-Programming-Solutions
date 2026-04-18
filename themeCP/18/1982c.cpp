#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	int a[n];	
	for(int i =0;i<n;i++) cin >> a[i];
	
	int pref[n+1];
	pref[0] = 0;
	for(int i =1;i<n+1;i++) pref[i] = pref[i-1] + a[i-1];
	
	int le=0;
	int ans =0;	
	for(int re = 0;re<n+1;re++){
		while(pref[re] - pref[le] > r){
			le++;
		}
		if(pref[re] - pref[le] >= l && pref[re]-pref[le] <=r){
			le = re;
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
