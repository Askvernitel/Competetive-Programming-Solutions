#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	string rs = "codeforces";
	cin >> s;
	int ans =0;
	for(int i =0;i<s.size();i++) if(s[i] != rs[i]) ans++;
	
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
