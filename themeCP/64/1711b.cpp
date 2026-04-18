#include <bits/stdc++.h>
#include <queue>
#define int long long
using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	int a[n];
	int deg[n];
	memset(deg, 0 ,sizeof(deg));
	map<int,vector<int>> b;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	for(int i =0;i<m;i++){
		int x, y;
		cin >> x >> y;
		b[--x].push_back(--y);
		b[y].push_back(x);
	}
	if(!(m%2)) {
		cout << 0 << '\n';
		return;
	}
	for(int i = 0;i<n;i++){
		deg[i]=b[i].size();
	}
	priority_queue<pair<int,pair<int,int>>> pq;

	set<int> vis;
	for(int i = 0;i<n;i++){
		pq.push({-a[i], {deg[i], i}});
	}
	//pq.push({-mino, {odd, v1}});
	//pq.push({-mine, {even, v2}});
	int ans = -1;	
	while(!pq.empty()){
		pair<int,pair<int,int>> p=pq.top();
		pq.pop();
		if(p.second.first%2 ){
			ans = -p.first ;
			break;
		}
		vis.insert(p.second.second);

		for(int x:b[p.second.second]){
			if(vis.find(x) != vis.end()) continue;
			vis.insert(x);
			deg[x]--;
			pq.push({p.first-a[x],{deg[x],x}});
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
