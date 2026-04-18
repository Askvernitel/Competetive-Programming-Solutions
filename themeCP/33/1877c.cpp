#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;

	if(k == 1){ 
		cout << 1 << '\n';
	}else if(k == 2){ 
		cout << min(n + max((int)0,(m/n)-1),m)<< '\n';
	}else if(k ==3){ 
		cout << max((int)0,m-n) - max((int)0, (m/n)-1)<< '\n';
	}else{ 
		cout << 0 << '\n';
	}
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
