#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;

	cin >> s;
	int n = s.size();
	int ans = 13;
	for(int i = 0;i<n;i++){
		if(s[i] == '1') break;
		if(s[i] == '3') ans = 31;
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
