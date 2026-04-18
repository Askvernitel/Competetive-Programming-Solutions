#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[200001];
int pref[200000][31];
bool f(int l, int r, int k){
	if(r < l){
		return false;
	}
	if(r == n) r--;
	int ans = 0;

	for(int i=0;i<31;i++){
		int p = pref[r][i]-((l-1 < 0)?0:pref[l-1][i]);
		if(p == r-l+1){
			ans+=(1 << i);
		}
	}
	
	return k <= ans;
}
void solve(){
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<n;i++){
		for(int j=0;j<31;j++){
			pref[i][j]=0;
		}
	}
	for(int i =0;i<n;i++){
		int c = a[i];
		int x = 0;
		while(c != 0){
			if(c & 1){
				pref[i][x]=1;
			}
			x++;
			c >>= 1;
		}
	}
	for(int i =1;i<n;i++){
		for(int j =0;j<31;j++){
			pref[i][j]=pref[i-1][j]+pref[i][j];
		}
	}
	int q;
	cin >> q;

	while(q--){
		int l, k;
		cin >> l >> k;
		l--;
		int rl=l-1, rr=n;

		while(rr-rl > 1){
			int m = (rr + rl)/2;
			if(f(l,m, k)){
				rl = m;
			}else{
				rr = m;
			}
		}
		if(rl < l){ 
			cout << -1 << ' ';
		}else{
			cout << rl+1 << ' ';
		}
	}
	cout << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
