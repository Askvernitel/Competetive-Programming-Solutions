#include <bits/stdc++.h>


using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	int pref[n+1];
	pref[0] = 0;
	for(int i =1;i<=n;i++){
		pref[i] = gcd(a[i-1], pref[i-1]);
	}
	int suf[n+1];
     	suf[n] = 0;
	for(int i =n-1;i>=0;i--){
		suf[i] = gcd(a[i], suf[i+1]);
	}
	if(pref[n] == 1){
		cout << 0 << '\n';
		return;
	}
	int ans = min(n, 3);
	for(int i =n-1;i>=0;i--){
		int u = gcd(pref[i], suf[i+1]);
		if(gcd(u, gcd(a[i],i+1)) == 1){
			ans = min(ans,n-i);
			break;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
