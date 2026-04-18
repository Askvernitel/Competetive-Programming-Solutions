#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	char a[n+2];
	a[0] = '1';
	a[n+1] = '1';
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}
	int cur =0, t=0; 
	int ans =0;
	for(int i=0;i<=n+1;i++){
		if(a[i] == '0' && t ==0) cur++;
		else cur = 0;
		if(cur == m){ 
			t=k;
			ans++;
			cur=0;
		}
		t=max(0, t-1);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
