#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	int b[m];
	for(int i = 0;i<m;i++) cin >> b[i];
	int pref[m+1];
	set<int> s = {0, n+1};
	for(int i = 1;i<=m;i++){
		s.insert(b[i-1]);
	}

	while(q--){
		int a;
		cin >> a;

		auto it = s.lower_bound(a);
		auto it1 =prev(it);
		if(*it1 == 0 || *it == n+1){ 
			int t = (*it1 == 0)?1:0;
			cout << *it-*it1-1 << "\n";
		}else{
			
			cout << (*it-*it1)/2 << '\n';
		}
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
