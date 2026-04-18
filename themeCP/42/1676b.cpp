#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	int minv = INT_MAX;
	for(int i =0;i<n;i++) minv = min(minv, a[i]);
	int ans = 0;

	for(int i =0;i<n;i++) ans += a[i]-minv;

	cout << ans << '\n';

}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
