#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int step = 6;
	if(n == 1){ 
		cout << 1 << '\n';
		return;
	}
	if(n <= 4){ 
		cout << 2 << '\n';
		return;
	}
	int ans = 2;
	int i = 5;
	int cur = 1;
	for(i = 4;i<n;){
		ans++;
//		cout << i << "\n";
		i+=(step);
		step*=2;
	}
//`	if(i > n) ans++;
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
