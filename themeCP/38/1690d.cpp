#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int pref[n+1];
	pref[0] = 0;
	for(int i =1;i<=n;i++){
		pref[i] = pref[i-1] + ((s[i-1] == 'B')?1:0);
	}
	int ans =INT_MAX;	
	for(int i =k;i<=n;i++){
		int diff = pref[i] - pref[i-k];
		ans = min(k-diff,ans);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
