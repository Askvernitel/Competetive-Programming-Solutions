#include <bits/stdc++.h>

using namespace std;
void solve(){
	int x,y,k;
	cin >> x >> y >> k;

	if(x > y){ 
		int p = (y+(k-1))/k;

		int u = x-p*k;
		int ans = 2*p;
		if(u > 0){ 
			int c =(u+(k-1))/k;
			ans += 2*c -1;
		}
		cout << ans << '\n';
	}else{
		int p = (x+(k-1))/k;

		int u = y-p*k;
		int ans = 2*p;
		if(u > 0){ 
			int c =(u+(k-1))/k;
			ans += 2*c;
		}
		cout << ans << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
