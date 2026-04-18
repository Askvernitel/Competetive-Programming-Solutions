#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,m;
	cin >> n>> m;
	map<int,int> p;
	map<int,vector<int>> s;
	for(int i =0;i<m;i++){
		int x, y;
		cin >> x >> y;
		p[max(x,y)]=max(min(x,y), p[max(x,y)]);
	}
	
	for(auto &[c,d]:p){
		s[d].push_back(c);
	}
	int ans= 0;
	int c = 0;
	for(int i =1;i<=n;i++){
		int l = -1, r=n+1;
		while(r-l>1){
			int mid = (r+l)/2;
			if(p.upper_bound(mid) == p.begin()){
				l=mid;
			}else{ 
				r=mid;
			}
		}
		int t = max((int)0,((c-i)*(c-i+1))/2);
		ans += ((r-i)*(r-i+1))/2-t;
		c=r;
		for(int x:s[i]){ 
			p.erase(x);
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
