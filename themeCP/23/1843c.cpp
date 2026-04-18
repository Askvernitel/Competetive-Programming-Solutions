#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;

	int sum = 0;
	while(n >= 1){
		sum+=n;
		n/=2;
	}
	cout << sum << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
