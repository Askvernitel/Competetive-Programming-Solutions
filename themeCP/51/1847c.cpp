#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	
	int pref[n+1];
	pref[0]=0;
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1]^a[i-1];
	}
	int ans = 0;
	int k[257];
	memset(k, 0, sizeof(k));
	for(int i =1;i<=n;i++){
		ans = max(pref[i], ans);
			
		for(int j =1;j<=256;j++){
			if(!k[j]) continue;
			ans = max(pref[i]^j, ans);
		}
		k[pref[i]]=1;
/*
		for(int j =1;j<=n;j++){
			ans = max(ans, pref[j]^pref[i]);
		}*/
	}
	
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
