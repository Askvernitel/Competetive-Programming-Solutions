#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s, t;
	cin >> s >> t;
	int p = max((int)t.size(), (int)s.size());
	int n = min((int)t.size(), (int)s.size());

	int am = 0;
	int ans = p-n;
	for(int i =0;i<n;i++){
		if(s[i] != t[i]) break;
		am++;
	}
	cout << ((am==0)?0:am+1) + (n-am)*2 + ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
