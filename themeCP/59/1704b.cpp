#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, x;
	cin >> n >> x;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int pl=a[0]-x, pr=a[0]+x;
	int ans = 0;
	for(int i =1;i<n;i++){
		int nl = max(a[i]-x, pl);
		int nr = min(a[i]+x, pr);
		
		if(nr - nl < 0){ 
			ans++;
			pl = a[i]-x;
			pr=a[i]+x;
		}else{
			pl=nl;
			pr=nr;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
