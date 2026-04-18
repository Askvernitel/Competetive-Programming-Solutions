#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n, m, k, w;
	cin >> n >> m >> k;
	cin >> w;
	int a[w];
	int grid[n][m];
	memset(grid,0,sizeof(grid));
	for(int i =0;i<w;i++){
		cin >> a[i];
	}

	int p1=min(n-k+1, k);
	int p2=min(m-k+1, k);
	vector<int> v;
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			v.push_back(min({(i+1),n-i,p1})*min({(j+1),m-j, p2}));
		}
	}
	sort(a,a+w, greater<int>());
	sort(v.begin(), v.end());
	int ans =0;	

	for(int i =0;i<w;i++){
		int p=v.back();
		ans+=min(p1*p2,p)*a[i];
		v.pop_back();
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
