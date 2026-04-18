#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	if(n == 1){ 
		cout << "NO\n";
		return;
	}
	int cnt = 0;
	for(int i =0;i<n;i++){
		if(a[i] == 1) cnt--;
		else cnt+=a[i]-1;
	}
	if(cnt < 0){ 
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
