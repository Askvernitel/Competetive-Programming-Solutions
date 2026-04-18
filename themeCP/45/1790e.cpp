#include <bits/stdc++.h>


using namespace std;
void solve(){
	int x;
	cin >> x;

	int nd = (x >> 1);

	if((nd + x != (nd | x)) || x%2){ 
		cout << -1 << '\n';
		return;
	}

	cout << nd << " "  << nd + x << '\n';
}


int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
