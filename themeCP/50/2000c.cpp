#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	map<int,set<int>> mp;

	for(int i =0;i<n;i++){
		mp[a[i]].insert(i);
	}
	int m;
	cin >> m;
	while(m--){ 
		string s;
		cin >> s;
		
		if(mp.size() > 26 || s.size() != n){
			cout << "NO\n";
			continue;
		}
		map<char, int> cnt;
		for(char ch:s) cnt[ch]++;
		
		string ans = "YES";
		int p = s.size();
		int v[p];
		memset(v, 0, sizeof(v));
		for(int i = 0;i<p;i++){
			if(v[i]) continue;
			for(auto &[c,d]:mp){
				if(d.find(i) != d.end()){
					if(cnt[s[i]] != (int)d.size()){
						ans = "NO";
						break;
					}
					for(int x:d){
						v[x] = 1;
						if(s[i] != s[x]){
							ans="NO";
						}
					}
					break;
				}
			}
			if(ans == "NO") break;
		}
		cout << ans << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();

}
