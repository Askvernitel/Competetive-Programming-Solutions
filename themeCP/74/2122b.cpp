#include <bits/stdc++.h>
#define int long long

using namespace std;
int a,b,c,d;
void solve(){
	int n;
	cin >> n;
	int ans =0;		
	for(int i=0;i<n;i++){
		cin >> a >> b >> c >> d;

		int u = b-d;
		if(u > 0){ 
			ans += min(a,c);
		}
		ans += max((int)0,c-a);
		ans += max((int)0,d-b);
	}
	cout << ans << '\n';
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;

	while(tc--) solve();
}
