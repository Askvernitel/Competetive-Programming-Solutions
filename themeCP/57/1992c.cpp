#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int ans[n]{};
	
	
	int l = n;
	int f = m;
	int s = 0, e = n-1;
	while(l >= k){
		ans[s++] = l;
		l--;
	}

	while(f >= 1){
		ans[e--] = f;
		f--;
	}
	int cur = l;
	for(int i =n-l;i<n-m;i++){
		ans[i] =cur;
		cur--;
	}

	for(int i = 0;i<n;i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
