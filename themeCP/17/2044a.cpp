#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int ans = 0;
	for(int a=1;a<n;a++){
		for(int b=1;b<n;b++){
			if(a+b == n) ans++;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
