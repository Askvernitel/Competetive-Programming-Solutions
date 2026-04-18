#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	int k[n];
	set<int> ks;
	for(int i=0;i<n;i++){
		cin >> k[i];
		ks.insert(k[i]);
	}
	
	for(int i =0;i<m;i++){
		int a, b, c;
		cin >> a >> b >> c;

		int p = 4*a*c;
		if(p < 0){ 
			cout << "NO\n";
			continue;
		}

		bool pos = 0; int ans = -1;
		auto it = ks.lower_bound(b);
		auto it1 =prev(it);
		if(it != ks.end()){ 
			int u = (b-*it)*(b-*it);
			if(u < p){ 
				pos=1;
				ans=*it;
			}
		}
		if(it1 != ks.end()){
			int u = (b-*it1)*(b-*it1);
			if(u < p){ 
				pos=1;
				ans=*it1;
			}
		}
		if(pos){ 
			cout << "YES\n";
			cout << ans << '\n';
		}else{
			cout << "NO\n";
		}
	}
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
