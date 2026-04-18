#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	string a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	map<string, int> id;
	map<pair<char, int>, int> m;
	int ans = 0;
	for(int i =0;i<n;i++){
		ans += m[{a[i][0], 0}];
		ans += m[{a[i][1], 1}];
		ans -= 2*id[a[i]];
		id[a[i]]++;
		m[{a[i][0], 0}]++;
		m[{a[i][1], 1}]++;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
