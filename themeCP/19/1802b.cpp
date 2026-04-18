#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	int t = 0;
	int cage = 0;
	int ans = 0;
	int cnt[2];
	memset(cnt,0,sizeof(cnt));
	for(int i =0;i<n;i++){
		if(a[i] == 2){
			cage += cnt[0]/2;
			cnt[0]%=2;
			cage+=cnt[1]/2;
			cnt[1]%=2;
		}else {
			if(!(cnt[1]%2)) cnt[1]++;
			else cnt[0]++;
		}
		ans = max(ans, cage+cnt[0]+cnt[1]);
	}
	ans = max(ans, cage+cnt[0]+cnt[1]);
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
