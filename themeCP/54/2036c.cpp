#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;
	int q;
	cin >> q;
	set<pair<int,int>> t;
	for(int i = 0;i<s.size()-3;i++){
		if(s.substr(i,4) == "1100"){ 
			t.insert({i, i+3});
		}
	}
	while(q--){
		int idx, v;
		cin >> idx >> v;
		idx--;
		s[idx] = v+48;
		for(int i = max(0,idx-3);i<=idx;i++){
			if(t.find({i,i+3}) != t.end()){ 
				t.erase({i,i+3});
			}
		}	
		for(int i = max(0,idx-3);i<=idx;i++){
			if(s.substr(i,4) == "1100"){ 
				t.insert({i, i+3});
			}
		}
		if((int)t.size()){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}

	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
