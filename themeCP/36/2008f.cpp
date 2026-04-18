#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];

	int suf[n+1];
	suf[n] = 0;
	for(int i =n-1;i>=0;i--){
		suf[i] = suf[i+1] + a[i];
	}
	int m = ((n)%mod*(n-1)%mod)%mod;
	int sum = 0;
	for(int i =1;i<n;i++){
		sum+=(a[i-1]*suf[i]);
	}

}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
