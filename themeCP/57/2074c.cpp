#include <bits/stdc++.h>

using namespace std;
void solve(){
	int x;
	cin >> x;
	int p = x;
	int cnt = 0;
	int c = 0;
	bool pos = 0;
	int ans = 0;
	while(p>0){
		if(p & 1){ 
			if(p >> 1 != 0) ans+=(1<<c);
			cnt++;
		}else{
			pos = 1;
			ans+=(1<<c);
		}
		c++;
		p=(p>>1);
	}
	if(cnt == 1 || !pos){
		cout << -1 << '\n';
		return;
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
