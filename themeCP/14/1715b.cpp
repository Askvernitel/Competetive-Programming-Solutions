#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n, k, b, s;
	cin >> n >>k >> b >> s;

	int u = k*b;


	int p = s-u;
	if(p<0){
		cout << -1 << '\n';
		return;
	}
	int c= n*(k-1);

	if(c < p){
		cout << -1 << '\n';
		return;
	}
	int ans[n];
	memset(ans, 0, sizeof(ans));
	ans[0]=u;
	for(int i =0;i<n;i++){
		if(k-1 >= p){ 
			ans[i]+=p;
			break;
		}
		ans[i]+=k-1;
		p-=k-1;
	}
	for(int i =0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
