#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	int s[k];
	for(int i=0;i<k;i++){
		cin >> s[i];
	}
	int prev = INT_MIN;
	for(int i =0;i<k-1;i++){
		if(s[i+1] - s[i] < prev){ 
			cout << "NO\n";
			return;
		}
		prev = s[i+1] - s[i];
	}
	int p = s[1]-s[0];
	int u;
	if(s[0] < 0){ 
		u =s[0]/(n-k+1);
	}else{
		u =(s[0]%(n-k+1)? (s[0]/(n-k+1)+1):(s[0]/(n-k+1)));
	}
	if(u > p){ 
		cout << "NO\n";
	}else cout << "YES\n";
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
