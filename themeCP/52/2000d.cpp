#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	string s;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	cin >> s;
	int l = 0, r = n-1;

	int pref[n+1];
	pref[0] = 0;
	for(int i =1;i<=n;i++){
		pref[i]=pref[i-1]+a[i-1];
	}
	int ans =0;
	while(r > l){ 
		while(r>=0 && s[r] != 'R') r--;
		while(l<n && s[l] != 'L') l++;

		if(r > l){ 
			ans+=(pref[r+1]-pref[l]);
		}
		r--;
		l++;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
