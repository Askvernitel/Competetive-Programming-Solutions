#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
	int n;
	cin >> n;
	int b[n-1];
	for(int i=0;i<n-1;i++){
		cin >> b[i];
	}

	int a = ((1 << 30) - 1);
	int out[n];
	if(n <= 2){ 
		cout << b[0] << " " << b[0] << '\n';
		return;
	}
	for(int i =1;i<n-1;i++){
		int bunion = b[i]|b[i-1];
		out[i] = bunion;
	}
	out[0] = b[0];
	out[n-1] =b[n-2];

	for(int i =0;i<n-1;i++){
		if((out[i] & out[i+1]) != b[i]){ 
			cout << -1 << '\n';
			return;
		}
	}
	for(int i =0;i<n;i++){
		cout << out[i] << ' ';
	}
	cout << '\n';
}

signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
