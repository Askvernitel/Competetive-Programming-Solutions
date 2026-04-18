#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n], b[n];

	pair<int,int> c[n];
	for(int i =0;i<n;i++) cin >> a[i];
	for(int i =0;i<n;i++) cin >> b[i];
	

	for(int i = 0;i<n;i++) c[i] = {a[i] + b[i], i};
	sort(c, c+n, greater<pair<int,int>>());	
	int alice = 1;
	int ans = 0;
	for(int i =0;i<n;i++){
		if(alice){
			ans+=(a[c[i].second]-1);
		}else{
			ans-=(b[c[i].second]-1);
		}
		alice=!alice;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();

}
