#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;


	if(n%2){ 
		cout << -1 << '\n';
		return;
	}
	cout << n/2 << " " << 0 << " " << n/2 << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
