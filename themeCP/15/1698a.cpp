#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	

	for(int i = 0;i<n;i++){
		int x = a[i];
		int xr = 0;
		for(int j = 0;j<n;j++){
			if(j == i) continue;
			xr ^= a[j];
		}
		if(x == xr){
			cout << x << '\n';
			break;
		}
	}

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
