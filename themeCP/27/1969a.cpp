#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int ans = 3;
	for(int i =1;i<=n;i++){
		int f = a[i-1];
		if(a[a[i-1]-1] == i){
			ans = 2;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
