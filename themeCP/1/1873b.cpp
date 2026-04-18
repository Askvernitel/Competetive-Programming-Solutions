#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	int minv = 10;
	for(int i =0;i<n;i++){
		cin >> a[i];
		minv = min(minv, a[i]);
	}
	int ans = 1;
	int added = 0;
	for(int i =0;i<n;i++){
		if(a[i] == minv && !added){
			a[i]++;
			added=1;
		}
		ans*=a[i];
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
