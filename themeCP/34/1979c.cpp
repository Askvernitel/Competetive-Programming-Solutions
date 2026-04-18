#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b){ 
	if(a==0) return b;
	return gcd(b%a, a);
}
int lcm(int a, int b){ 
	return a*b/gcd(a,b);	
}
void solve(){
	int n;
	cin >> n;
	int k[n];
	int m =1;
	for(int i =0;i<n;i++){
		cin >> k[i];	
	}
	int cur = 1;
	for(int i =0;i<n;i++){
		cur = lcm(cur, k[i]);
	}
	m=cur;
	int ans[n];
	int u = 0;
	int sum = 0;
	for(int i = 0;i<n;i++){
		ans[i] = m/k[i];
		sum+=m/k[i];
	}
	if(sum >= m){ 
		cout << -1 << '\n';
		return;
	}

	for(int i =0;i<n;i++){
		cout << ans[i] << " ";
	}

	cout << '\n';
}
signed main(){
	int tc;

	cin >> tc;

	while(tc--) solve();
}
