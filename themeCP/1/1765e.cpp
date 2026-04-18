#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, a, b;
	cin >> n >> a >> b;

	if(a > b){
		cout << 1 << '\n';
		return;
	}
	
	cout << ((n%a)?(n/a)+1:n/a) << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
