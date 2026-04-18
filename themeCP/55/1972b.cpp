#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;
	int cnt = 0;
	for(int i =0;i<n;i++){
		if(s[i] == 'U') cnt++;
	}

	if(cnt%2){ 
		cout << "YES\n";
	}else cout << "NO\n";
}
int main(){
	int tc;
	cin >> tc;

	while (tc--) solve();
}
