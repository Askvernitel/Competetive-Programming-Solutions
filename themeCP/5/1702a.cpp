#include <bits/stdc++.h>
#include <string>

using namespace std;
void solve(){
	string m;
	cin >> m;
	int n = m.size();

	int ans = stoi(m)-(int)pow(10, n-1);
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
