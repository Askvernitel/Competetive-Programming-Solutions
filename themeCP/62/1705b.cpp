#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int sum =0;
	int cnt =0;
	for(int i =0;i<n-1;i++){
		sum+=a[i];
		if(sum != 0 && a[i] == 0) cnt++;
	}
	cout << sum + cnt << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
