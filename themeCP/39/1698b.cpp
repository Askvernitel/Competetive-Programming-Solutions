#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];	
	for(int i =0;i<n;i++) cin >> a[i];
	int ans=0;	
	int p = 0;
	if(k == 1){ 
		cout << ((n-1)/2) << '\n';
		return;
	}
	for(int i =1;i<n-1;i++){
		if(a[i] > a[i-1]+a[i+1]){
			ans++;
		}
	}

	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
