#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	int fib[n+1];
	fib[0]=1;
	fib[1]=1;
	for(int i =2;i<=n;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	while(m--){ 
		int w,l,h;
		cin >> w >> l >> h;

		int wk = w-fib[n];
		int lk = l-fib[n];
		int hk = h-fib[n];
		
		if(min({wk,lk,hk}) < 0){ 
			cout << 0;
			continue;
		}

		int lft = max({hk*fib[n-1]*fib[n-1], wk*l*h, w*lk*h});
		if(hk >= fib[n-1] || wk >= fib[n-1] || lk >= fib[n-1]){ 
			cout << 1;
			continue;
		}
		cout << 0;
	}
	cout << '\n';


}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
