#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	char prev = '0';
	for(int i =0;i<n;i++){
		if(s[i] == '?') s[i] = prev;
		else prev = s[i];
	}
	cout << s << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
