#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	string a[2*n-2];
	for(int i =0;i<2*n-2;i++) cin >> a[i];
	set<string> s;	
	for(int i =0;i<2*n-2;i++){
		sort(a[i].begin(), a[i].end());
		if(s.find(a[i]) != s.end()){
			s.erase(a[i]);
			continue;
		}

		s.insert(a[i]);
	}
	if(s.size() == 0) cout<< "YES";	
	else cout << "NO";

	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
