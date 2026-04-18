#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];	
	}

	sort(a, a+n, greater<int>());
	int cnt = 0;
	for(int i =0;i<n;i++){ 
		if(cnt + a[i] > k) break;
		cnt += a[i];	
	}
	cout << k-cnt << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
