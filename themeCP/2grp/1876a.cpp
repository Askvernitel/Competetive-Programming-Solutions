#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
void solve(){
	int n, p;
	cin >> n >> p;
		
	int a[n], b[n];
	for(int i =0;i<n;i++) cin >> a[i];
	for(int i =0;i<n;i++) cin >> b[i];
	pair<int,int> c[n];	
	for(int i =0;i<n;i++){
		c[i].F = b[i];
		c[i].S = a[i];
	}
	sort(c, c+n);
	int cnt=0, ans = p;	
	vector<int> cnts;
	for(int i =0;i<n;i++){
		if(c[i].F >= p) break;
		cnts.push_back(c[i].S);
	}
	//p=6
	//a1, a2, a3, a4, a5
	//1 2 3 4 5  
	int k = 1;
	for(int i =0;i<cnts.size();i++){
		if(k + cnts[i] >= n){
			ans+=c[i].F*(n-k);
			k=n;
			break;
		}
		k+=cnts[i];
		ans+=c[i].F*c[i].S;
	}
	ans+=p*(n-k);
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
