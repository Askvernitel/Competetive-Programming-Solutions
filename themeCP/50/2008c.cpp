#include <bits/stdc++.h>

using namespace std;
void solve(){
	int l, r;
	cin >> l >> r;
	int f = 1;
	int ans = 1;
	for(int i = l;i<r;i+=f){

		ans++;
		f++;
	}

	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
