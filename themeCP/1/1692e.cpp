#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, s;
	cin >> n >> s;
	int a[n];	
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int t = 0;
	int l =0;
	int ans = n;
	int exists = 0;
	for(int r=0;r<n;r++){
		t +=a[r];
		while(t>s) t-=a[l++];
		
		if(t == s){ 
			exists = 1;
			ans = min(ans, n-r-1+l);
		}
	}
	if(ans == n && !exists) ans = -1;
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
