#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	map<char,int> m;
	for(int i = 0;i<n;i++){
		m[s[i]]++;
	}
	int diff = abs('A'-'a');
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(m[s[i]+diff] > 0 && m[s[i]] > 0) {
			m[s[i]+diff]--;
			m[s[i]]--;
			ans++;
		}else if(m[s[i]-diff] > 0 && m[s[i]] > 0){
			m[s[i]-diff]--;
			m[s[i]]--;
			ans++;
		}
		else if(m[s[i]+diff] == 0 && s[i]-'a' <= 25 && m[s[i]] > 1 && k > 0){
			k--;
			m[s[i]]-=2;
			ans++;
		}else if(m[s[i]-diff] == 0 && s[i]-'A' <= 25 && m[s[i]] > 1 && k > 0){
			k--;
			m[s[i]]-=2;
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
