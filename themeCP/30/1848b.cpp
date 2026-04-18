#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];	
	map<int,vector<int>> m;
	for(int i =0;i<n;i++){
		cin >> a[i];
		if(m.find(a[i])==m.end()){
			m[a[i]].push_back(-1);
		}
		m[a[i]].push_back(i);
	}
	int ans = INT_MAX;
	for(auto &[x, y]:m){
		int dist = 0;
		int idx_max = 0;
		int sec_dist=0;
		for(int i = 0;i<y.size()-1;i++){
			if(y[i+1]-y[i]-1 >= dist){
				idx_max = i;
				dist=y[i+1]-y[i]-1;
			}
		}
		if(n-y.back()-1 >= dist){
			idx_max=n-1;
			dist=n-y.back()-1;
		}
		for(int i = 0;i<y.size()-1;i++){
			if(i == idx_max) continue;
			if(y[i+1]-y[i]-1 >= sec_dist){
				sec_dist=y[i+1]-y[i]-1;
			}
		}
		if(idx_max != n-1 && n-y.back()-1>=sec_dist){ 
			sec_dist=n-y.back()-1;
		}
		ans = min(ans,max(dist/2, sec_dist));
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
