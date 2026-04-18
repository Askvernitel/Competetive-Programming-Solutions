#include <bits/stdc++.h>
#define int long long

using namespace std;


void solve(){
	int n, x;
	cin >> n >> x;
	
	int a,b,c;
	int l = 0, r=x+1;
	int ans=0;	
	for(int i =1;i<n;i++){
		for(int j =1;j<=n/i;j++){
			int c = min((n - i*j)/(i+j), x-i-j);
			if(c < 0) continue;
			ans += c;
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
