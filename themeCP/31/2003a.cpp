#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;

	if(s[0] == s[n-1]){ 
		cout << "NO";
	}else{ 
		cout << "YES";
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
