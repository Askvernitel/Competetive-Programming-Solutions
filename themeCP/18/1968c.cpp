#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n+1];
	for(int i=0;i<n-1;i++) cin >> a[i];
	a[n-1] = a[n-2]+1;
	int cur = a[0]+1;
	cout << a[0] + 1 << " ";

	for(int i=0;i<n-1;i++){
		cout << cur*(a[i+1]/a[i]) + a[i] << " ";
		cur = cur*(a[i+1]/a[i]) + a[i];
	}
	
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
