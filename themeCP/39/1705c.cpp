#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
void solve(){
	int n, c, q;
	cin >> n >> c >> q;
	string s;
	cin >> s;
	
	int am[c+1];
	memset(am,0,sizeof(am));
	pair<int,int> d[c+1];
	d[0].F = 0;
	d[0].S = n-1;
	am[0] = n;
	for(int i =1;i<c+1;i++){
		int l, r;
		cin >> l >> r;
		//l--; r--;
		d[i-1].F = l;
		d[i-1].S = r;
		am[i]+=am[i-1]+(r-l+1);
	}
	while(q--){
		int k;
		cin >> k;
		int cur = k;
		int idx =1;
		for(int i= 1;i<c+1;i++){
			if(am[i] >= cur){
				idx=i-1;
				break;
			}
		}
		while(cur > n){ 
			pair<int,int> p = d[idx];
			int z = cur - am[idx];
			cur = p.F + z-1;
			for(int i = idx;i>=0;i--){
				if(am[i] < cur){
					idx = i;
					break;
				}
			}
		}
		cout << s[cur-1] << '\n';
	}
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
