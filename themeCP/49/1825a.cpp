#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;

	int n = s.size();
	set<int> p;
	for(int i = 0;i<n;i++){
		p.insert(s[i]);
	}
	if(p.size() == 1){
		cout << -1 << '\n';
	}else{
		cout << n-1 << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
