#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];	
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	int pref[n+1];
	pref[0] = 0;
	int cnt[n+1][2];
	cnt[0][0]=0;
	cnt[0][1]=0;
	for(int i =1;i<=n;i++){
		pref[i] = pref[i-1] + a[i-1];
		cnt[i][a[i-1]%2]=cnt[i-1][a[i-1]%2]+1;
		cnt[i][(a[i-1]+1)%2]=cnt[i-1][(a[i-1]+1)%2];
	}

	for(int i =1;i<=n;i++){
		int e=cnt[i][0];
		int o=cnt[i][1];
		int v = (o/3);
		if(o == 1 && e > 0){
			cout << pref[i] - 1 << ' ';
			continue;
		}
		if(o%3 == 1 && o > 1){ 
			cout << pref[i] - v - 1 << ' ';
			continue;
		}
		cout << pref[i]- v << ' ';
	}
	cout << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
