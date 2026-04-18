#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.size();

	int idx =n-1;
	for(int i =n-1;i>=0;i--){
		if(s[i] != '0'){idx = i;  break;}
	}
	int ans = n-idx-1;

	for(int i =idx-1;i>=0;i--){
		if(s[i] != '0'){
			ans++;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
