#include <bits/stdc++.h>
#define int long long
using namespace std;
int k, x, a;
bool f(int sum, int u){ 
	return (sum + u < k*u);
}
void solve(){
	cin >> k >> x >> a;
	int j = 0;
	int sum = 0;
	while(j<=x){ 
		int l = 0, r=1e9;
		while(r-l>1){
			int m = (l+r)/2;
			if(f(sum,m)){ 
				r=m;
			}else{ 
				l=m;
			}
		}
		
		sum+=r;
		j++;
	}
	if(a <sum){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
