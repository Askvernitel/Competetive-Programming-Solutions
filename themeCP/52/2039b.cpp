#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.size();	
	for(int i =0;i<n-2;i++){
		if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]){
			cout << s.substr(i, 3) << '\n';
			return;
		}
	}
	for(int i =0;i<n-1;i++){
		if(s[i] == s[i+1]){ 
			cout << s.substr(i, 2) << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
