#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for(int i =0;i<n;i++) cin >> a[i];
	for(int i =0;i<n;i++) cin >> b[i];
	for(int i =0;i<n;i++) cin >> c[i];
	
	vector<pair<int,int>> a1(n),b1(n),c1(n);
	for(int i =0;i<n;i++){
		a1[i] = {a[i],i};	
		b1[i] = {b[i],i};	
		c1[i] = {c[i],i};	
	}

	sort(a1.begin(), a1.end(),greater<pair<int,int>>());
	sort(b1.begin(), b1.end(),greater<pair<int,int>>());
	sort(c1.begin(), c1.end(),greater<pair<int,int>>());

	int ans = 0;
	for(int i =0;i<3;i++){
		for(int j = 0;j<3;j++){
			for(int k = 0;k<3;k++){
				if(a1[i].S == c1[k].S || a1[i].S == b1[j].S || b1[j].S == c1[k].S) continue;
				ans = max(a1[i].F + b1[j].F + c1[k].F, ans);
			}
		}
	}
	cout << ans << '\n';

}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
