#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	int a[n];
	pair<double,double> b[m];
	set<double> sa;
	for(int i =0;i<n;i++){
		cin >> a[i];
		sa.insert(a[i]);
	}

	for(int i =0;i<m;i++){
		int a, t, c;
		cin >> a >> t >>c;
		if(4*a*c < 0){
			b[i].F = LLONG_MAX;
			continue;
		}
		double p = (double)t - sqrt(4*a*c);
		double u = (double)t + sqrt(4*a*c);
		//if(p < 0 && p != (int)p) p--;
		//if(u > 0 && u != (int)u) u++;
		b[i].F=p;
		b[i].S=u;
	}
	bool pos = 1;
	int ans[m];
	memset(ans,-1,sizeof(ans));
	for(int i =0;i<m;i++){
		auto it = sa.upper_bound(b[i].F);
		if(it != sa.end() && *it < b[i].S){
			ans[i] = (int)*it;
		}
	}

	for(int i =0;i<m;i++){
		if(ans[i] == -1){ 
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		cout << ans[i] << '\n';
	}
	cout << '\n';

}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
