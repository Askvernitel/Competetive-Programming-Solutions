#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	int minv = INT_MAX;
	for(int i =0;i<n;i++){
		cin >> a[i];
		minv = min(minv, a[i]);
	}
	
	int k = 2*minv -1;
	int ans = 0;	
	for(int i =0;i<n;i++){
		ans += max(0,(a[i])/k);
		if(!(a[i]%k)) ans--;
	}

	cout << ans << '\n';
	
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
