#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	if(n == 1){
		cout << 0 << '\n';
		return;
	}
	int k = sqrtl(n-1);
	cout << k << '\n';
}
signed main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;

	while(tc--) solve();
}
