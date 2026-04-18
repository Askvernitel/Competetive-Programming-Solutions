#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, a;

	cin >> n >> a;
	int v[n];
	int sum = 0;
	int ans = 0;
	int t = 0;
	int idx_l=-1, idx_r=-1;
	for(int i =0;i<n;i++){
		cin >> v[i];
		if(a > v[i]){ 
			ans++;
			idx_l = i;
			idx_r = i;
		}
		if(a == v[i]){ 
			t++;
			idx_r = i;
		}
	}
	if(ans > n-ans-t){ 
		cout << a-1 << '\n' ;
	}else{
		cout << a+1 << '\n';
	}
//	cout << max(ans, n-ans) << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
