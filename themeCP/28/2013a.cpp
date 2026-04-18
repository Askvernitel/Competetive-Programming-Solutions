#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;

	cout << max(((n%x)?n/x+1:n/x),(n%y)?n/y+1:n/y) << '\n' ;
}
int main(){	
	int tc;

	cin >> tc;
	while(tc--) solve();
}
