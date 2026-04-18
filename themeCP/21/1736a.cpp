#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0;i<n;i++) cin >> a[i];
	for(int i = 0;i<n;i++) cin >> b[i];
	int cnt1a=0, cnt1b=0;
	int f1 = 0, f0=0;
	for(int i =0; i<n;i++){
		if(a[i] == 1) cnt1a++;	
		if(b[i] == 1) cnt1b++;	
		if(a[i] == 1 && b[i] == 0) f1 = 1;
		if(a[i] == 0 && b[i] == 1) f0 = 1;
	}

	int ans = INT_MAX;
	ans = min(abs(cnt1b-cnt1a) +f1, ans);
	ans = min(abs((n-cnt1b)-(n-cnt1a)) +f0, ans);
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
