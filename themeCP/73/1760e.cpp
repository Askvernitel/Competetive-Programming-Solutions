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
	int suf[n+1];
	suf[n] = 0;
	int t = 0;
	int o = 0;
	for(int i =n-1;i>=0;i--){
		suf[i] = suf[i+1];
		if(a[i] == 0) suf[i]++;
		else {
			t+=suf[i];
			o++;
		}
	}
	int ans = t;
	int u = 0;
	for(int i =0;i<n;i++){
		if(a[i] == 0){
			ans = max(ans, t+suf[i]-u-1);
			break;
		}else u++;
	}
	int c = 0;
	for(int i =n-1;i>=0;i--){
		if(a[i] == 1){
			ans = max(ans, t-c+(o-1));
			break;
		}else c++;
	}
	cout << ans << '\n';

}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
