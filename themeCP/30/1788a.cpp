#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	int am = 0;
	for(int i =0;i<n;i++){
		cin >> a[i];
		if(a[i] == 2) am++;
	}
	int cur = 0;
	int ans =-2;
	for(int i =0;i<n;i++){
		if(a[i] == 2) cur++;
		if(am-cur == cur){ 
			ans = i;
			break;
		}

	}

	cout << ans+1 << '\n';

	
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
