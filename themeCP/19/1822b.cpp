#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
	int n ;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	sort(a, a+n);

	cout << max(a[n-1] * a[n-2], a[0]*a[1]) << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
