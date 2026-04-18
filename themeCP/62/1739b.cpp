#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int d[n];
	for(int i =0;i<n;i++){
		cin >> d[i];
	}
	int a[n];
	a[0] = d[0];
	for(int i=1;i<n;i++){
		int p1 = d[i]+a[i-1];
		int p2 = -d[i]+a[i-1];
		if(p1 >= 0 && p2 >=0 && p1 != p2) {
			cout << -1 << '\n';
			return;
		}

		if(p2 < 0){ 
			a[i] = p1;
			continue;
		}
		a[i] = max(p2,p1);
	}
	for(int i =0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
