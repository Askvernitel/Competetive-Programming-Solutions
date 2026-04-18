#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int ans = INT_MAX;
	if(k == 4){ 
		int cnt1=0, cnt2=0;
		for(int i =0;i<n;i++){
			if(!(a[i]%2)) {
				int v = a[i];
				while(v > 0 && !(v%2)){ 
					v/=2;
					cnt2++;
				}
			}
		}
		if(cnt2 == 0){ 
			ans = 2;
		}else if(cnt2==1){ 
			ans = 1;
		}else{
			ans = 0;
		}
	}

	for(int i =0;i<n;i++){
		ans = min((k-(a[i]%k))%k, ans);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
