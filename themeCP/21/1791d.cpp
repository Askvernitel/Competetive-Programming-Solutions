#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;
	map<char,int> cnt1, cnt2;
	int ans =cnt2.size();	
	for(int i= 0;i<n;i++){
		cnt2[s[i]]++;
	}
	
	for(int i = 0;i<n;i++){
		cnt1[s[i]]++;
		cnt2[s[i]]--;
		if(cnt2[s[i]] == 0) cnt2.erase(s[i]);
		ans = max((int)(cnt2.size()+cnt1.size()), ans);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
