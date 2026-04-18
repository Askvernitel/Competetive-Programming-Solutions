#include <bits/stdc++.h>

using namespace std;
void solve(){
	int x, y;
	cin >> x >>  y;
	int mod1 = 0, mod2 = 0;
	int cur = 1;
	int j = 0;
	int ans = 0;
	while(mod1 == mod2 && (x > 0|| y > 0)){
		mod1 = x%2;
		mod2 = y%2;
		if(mod1 == mod2){
			cur *= 2;
		}
		x /= 2;
		y /= 2;
		j++;
	}
	cout << max(ans,cur) << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
