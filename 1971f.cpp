#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int r;
	cin >> r;

	int k = r*r;
	int p = (r+1)*(r+1);
	int upper = 0;
	int lower = 0;
	int ans = 0;
	for(int i =-r;i<=r;i++){
		int t = k - i*i;
		int c = p - i*i;
		int lower = max((int)0, t);
		int s1 = sqrt(lower);
		if(sqrt(lower) > s1) s1++;
		int s2 = sqrt(c);
		ans += (s2 -s1 + 1)*2;
		if(lower == 0) ans--;
		if(s2 == sqrt(c)) ans-=2;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
