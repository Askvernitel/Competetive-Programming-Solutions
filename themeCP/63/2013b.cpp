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
	int sum = 0;
	for(int i =0;i<n-2;i++){
		sum -= a[i];
	}
	cout << a[n-1]-(a[n-2]+sum) << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
