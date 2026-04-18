#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int m;
	cin >> m;

	string l, r;
	cin >> l >> r;

	map<char, set<int>> mp;
	for(int i =0;i<n;i++){
		mp[s[i]-48].insert(i);
	}
	set<int> prev={};
	for(int i =0;i<m;i++){
		int left = l[i]-48, right = r[i]-48;
		set<int> cur = {};
		if(prev.size() == 0){
			for(int j=left;j<=right;j++){
				if(mp[j].size() == 0){cout << "YES\n"; return;};
				prev.insert(*mp[j].begin());
				mp[j].erase(mp[j].begin());
			}
			continue;
		}
		for(int j=left;j<=right;j++){
			if(mp[j].size() == 0){
				cout << "YES\n";
				return;
			}
			int itl=*mp[j].begin()	;
			for(int x:prev){ 
				auto it = mp[j].upper_bound(x);
				int val = *it;
				if(it == mp[j].end()){
					cout << "YES\n";
					return;
				}
				if(val > itl) itl = val;
			}
			cur.insert(itl);
			mp[j].erase(itl);
		}
		prev = cur;
	}
	cout << "NO\n";
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
