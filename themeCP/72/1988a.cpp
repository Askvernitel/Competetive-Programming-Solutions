#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int cof = 1;
	multiset<int> s = {n};
	int ans = 0;

	int p =n/(k-1);
	ans += p;
	int c = n%(k-1);
	if(k-1 == 1){ 
		ans--;
	}
	else if(c>1) ans++;
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
