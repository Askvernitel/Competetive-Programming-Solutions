#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
void solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;
	int dp[n+2];
	memset(dp, 0, sizeof(dp));
	dp[0] =1;
	char prev = s[0];
	
	int ans = 0;
	for(int i = 1;i<n;i++){
		if(prev == s[i]){
			dp[i] = ((dp[i-1]%mod)*2)%mod;
		}else{
			dp[i] = 1;
			prev = s[i];
		}
	}
	for(int i =0;i<n;i++){
		ans = (ans%mod + dp[i]%mod)%mod;
	}

	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
