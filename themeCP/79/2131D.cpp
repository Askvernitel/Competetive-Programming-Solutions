#include <bits/stdc++.h>

using namespace std;


int ls[200001];
void leaf(vector<vector<int>>& v, int cur, int& am){ 

	if(v[cur].size() <= 1){
		am++;
		for(int neigh:v[cur]){ 
			ls[neigh]++;
		}
	}
}

void solve(){
	int n;
	cin >> n;
	memset(ls,0,n*4);
	vector<vector<int>> t(n+1);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		t[--u].push_back(--v);
		t[v].push_back(u);
	}
	if(n-1 == 1){ 
		cout << 0 << '\n';
		return;
	}
	set<int> vis = {};
	int cnt = 0;
	for(int i =0;i<n;i++){
		leaf(t, i, cnt);	
	}
	int maxv = 0;
	for(int i=0;i<n;i++){
		maxv = max(ls[i], maxv);
	}
	cout << cnt - maxv << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
