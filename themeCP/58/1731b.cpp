#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef double dd;
int mod = 1e9+7;
void solve(){
	int n;

	cin >> n;
	int p = (n*(n-1));
	//int t =((337* n) * ((n+1) * (2*n+1))%mod)%mod;
	int p2 = 337*(n*(((n+1)*((2*n+1)%mod))%mod)%mod)%mod;
	n--;
	int p3 = 337*(n*(((n+1)*((2*n+1)%mod))%mod)%mod)%mod;
	//int t1 =((337* n) * ((n+1) * (2*n+1))%mod)%mod;
//	cout << (t1 + t + p%mod)%mod << '\n';
	cout << (p2%mod+p3%mod  + (1011*(p%mod))%mod)%mod << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
