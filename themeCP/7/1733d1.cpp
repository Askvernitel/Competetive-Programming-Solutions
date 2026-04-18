#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	
	string a, b;
	cin >> a >> b;
	a.push_back('0');
	b.push_back('0');
	int first = x;
	int second = min(2*y, x);
	int cnt =0;
	for(int i = 0;i<n;i++){
		if(a[i] != b[i]){ 
			cnt++;
		} 
	}
	if(cnt%2){ 
		cout << -1 << '\n';
		return;
	}

	if(cnt == 2){
		int ans = y;
		for(int i = 0;i<n-1;i++){
			if(a[i] != b[i] && a[i+1] != b[i+1]){
				ans = second;
				break;
			}
		}
		cout << ans <<'\n';
	}else{ 
		cout << (cnt/2)* y<<'\n';
	}

}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
