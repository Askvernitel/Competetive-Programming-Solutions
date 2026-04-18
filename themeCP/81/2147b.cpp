#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;

	int x = n;

	int a[2*n];
	memset(a, 0, sizeof(a));
	for(int i =0;i<n;i++){
		if(a[i] != 0) continue;
		int k = (2*n-i)/x;
		if((2*n-i)%x == 0) k--;
//		cout << x << "K: " << k << '\n';

		while(a[i+k*x] != 0 || i+k*x >= 2*n){
			k--;
		}
		a[i] = x;
		a[i+k*x] = x;
		x--;
	}
	for(int i=0;i<2*n;i++){
		cout << a[i] << " ";
	}
	cout << '\n';
}
int main(){
	int tc;

	cin >> tc;

	while(tc--) solve();
}
