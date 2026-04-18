#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	pair<int,int> a[n];
	for(int i =0;i<n;i++){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a+n);
	int d[n-1];
	for(int i =0;i<n-1;i++){
		d[i] = a[i+1].first-a[i].first;
	}
	int suf[n];
	suf[n-1] = 0;
	int t = 1;
	for(int i=n-2;i>=0;i--){
		suf[i] = suf[i+1]+t*d[i];
		t++;
	}
	int pref[n];
	t = 0;
	int ans[n];
	pref[0] = 0;
	for(int i =1;i<n;i++){
		pref[i]=pref[i-1]+i*d[i-1];
	}
	
	for(int i =0;i<n;i++){
		ans[a[i].second]= suf[i]+pref[i]+n;
	}
	for(int i =0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
