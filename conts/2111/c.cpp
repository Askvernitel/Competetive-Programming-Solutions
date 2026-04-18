#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n+1];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	
	a[n]=LLONG_MAX;
	vector<int> s;
	s.push_back(0);
	int cur = LLONG_MAX;
	int ans=LLONG_MAX;
	for(int i =0;i<=n;i++){
		if(s.back() != a[i]){ 
			cur+=(n-i)*s.back();
			ans=min(cur,ans);
			cur=(i)*a[i];
		}
		s.push_back(a[i]);
	}
	if(ans == LLONG_MAX){
		cout << 0 << '\n';
		return;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
