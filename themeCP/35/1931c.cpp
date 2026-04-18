#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];

	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	int l =0, r = n-1;
	int ans = n;
	int u = 0, k = 0;
	int v = 0;
	for(int i = 0;i<n-1;i++){
		u = a[i];
		if(a[i] != a[i+1]) break;
		v++;
	}
	ans = min(ans,n-v-1);
	int z=0;
	for(int i = n-1;i>0;i--){
		k = a[i];
		if(a[i] != a[i-1]) break;	
		z++;
	}

	ans = min(ans,n-z-1);
	if(u == k){ 
		ans = min(ans, n-v-z-2);
	}
	cout << max(0,ans) << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
