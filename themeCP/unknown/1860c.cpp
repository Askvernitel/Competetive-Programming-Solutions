#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int p[n];
	set<int> s1, s2;
	for(int i =0;i<n;i++){
		cin >> p[i];
	}
	int ans = n;
	for(int i =0;i<n;i++){
		auto it = s2.lower_bound(p[i]);
		if(it != s2.begin() && s2.size() != 0){ 
			ans--;
			continue;
		}
		auto it1 = s1.lower_bound(p[i]);
		if(it1 != s1.begin() && s1.size() != 0){ 
			s2.insert(p[i]);
		}else{ans--;s1.insert(p[i]);}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
