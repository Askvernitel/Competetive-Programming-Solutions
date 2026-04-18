#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, q;
bool good(int x){ 
	return x <= q;
}
void solve(){
	cin >> n >> k >> q;

	int a[n+1];
	for(int i =0;i<n;i++) cin >> a[i];
	a[n] = INT_MAX;
	int l = 0;	
	int ans = 0;
	for(int r =0;r<=n;r++){
		if(!good(a[r])){ 
			int p = r-l;
			if(p >= k) ans+=max((int)0,((p-k+1)*((p-k+1)+1))/2);
			l = r+1;
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
