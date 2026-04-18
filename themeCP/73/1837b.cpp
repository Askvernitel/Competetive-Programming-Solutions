#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	char s[n+1];
	for(int i =0;i<n;i++){
		cin >> s[i];
	}
	s[n] = '#';
	int ans = 0;
	int prev = -1;
	for(int i =0;i<n;i++){
		if(s[i] == s[i+1]){

		}else{
			ans = max(ans, i-prev+1);
			prev = i;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
