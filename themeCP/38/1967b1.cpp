#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	int ans = 0;	
	for(int b = 1;b<=m;b++){
		for(int a = b;a<=n;a+=b){
			if((a+b)%(b*b) == 0){
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
