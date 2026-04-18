#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int cnt = 1;
	int ans = 1;
	while(n/4 != 0){ 
		ans+=cnt;
		n/=4;
		cnt *=2;
	}
	cout << cnt << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
