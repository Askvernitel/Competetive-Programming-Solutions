#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int x){ 
	return x-(int)sqrt(x);
}
void solve(){
	int k;
	cin >> k;
	
	int l = 0, r = 2e18;

	while(r - l >1) {
		int m = (r+l)/2;

		if(f(m) >= k){
			r =m;
		}else{
			l =m;
		}
	}
	cout << r << '\n';

}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
