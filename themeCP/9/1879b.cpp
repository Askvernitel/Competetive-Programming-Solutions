#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	int mina=INT_MAX, minb=INT_MAX;
	for(int i =0;i<n;i++){
		cin >> a[i];
		mina= min(mina, a[i]);
	}
	for(int i =0;i<n;i++){
		cin >> b[i];
		minb= min(minb, b[i]);
	}
	int ans1 = mina*n, ans2= minb*n;
	for(int i =0;i<n;i++){
		ans1+=b[i];
		ans2+=a[i];
	}
	cout << min(ans1,ans2) << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
