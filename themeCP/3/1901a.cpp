#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, x;
	cin >> n >> x;
	int a[n+2];
	for(int i =1;i<=n;i++){
		cin >> a[i];	
	}

	a[n+1]=x;
	a[0]=0;
	int ans =0;
	for(int i =0;i<=n;i++){
		if(i == n){ 
			ans = max(2*(a[i+1]-a[i]), ans);
			continue;
		}
		ans = max(a[i+1]-a[i],ans);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();	
}
