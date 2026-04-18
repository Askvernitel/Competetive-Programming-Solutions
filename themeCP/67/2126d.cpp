#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
		

	pair<int,int> p[n];
	for(int i =0;i<n;i++){
		int l,r,real;
		cin >> l >> r >> real;

		p[i]={l,real};
	}
	sort(p, p+n);

	for(int i =0;i<n;i++){
		if(p[i].first <= k && k<p[i].second){
			k=p[i].second;
		}
	}
	cout << k << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
