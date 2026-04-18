#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];

	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	int cnt0=0, cnt1=0;
	bool p = 0;
	for(int i=0;i<n;i++){
		if(a[i] == 0) cnt0++;
		else if(a[i] == 1) cnt1++;
		else{
			p=1;
		}
	}
	int ans = 0;
	int u = cnt0 > (n+1)/2;
	if(u){
		ans++;
	}
	if(u && !p && cnt1 > 0){
		ans++;
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
