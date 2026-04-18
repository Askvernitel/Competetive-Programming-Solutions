#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, x;
	cin >> n >> x;
	int u = x;
	int c = 0;
	int v = 0;
	bool pos =0;
	while(u%2 != 0){ 
		v+=(1<<c);
		c++;
		u/=2;
	}
	if(u == 0) pos = 1;
	int l = 0;
	int left = n;
	for(int i = 0;i<min(n-1, v+1);i++){
		cout << i << " ";
		l = i;
		left--;	
	}
	if(pos && l+1 >= (1<<(c-1)) && l+1 <= x) cout << l+1 << " ";
	else cout << x << " ";
	left--;

	for(int i = 0;i<left;i++){
		cout << 0 << " ";
	}
	cout << '\n';
}
int main(){
	int tc;

	cin >> tc;
	while(tc--) solve();
}
