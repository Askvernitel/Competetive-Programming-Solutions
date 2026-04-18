#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	
	multiset<int> s;
	pair<int,int> a[n];
	for(int i =0;i<n;i++){
		int l, r;
		cin >> l >> r;
		a[i] = {l,r};
		if(l == r){ 
			s.insert(l);
		}
	}

	for(int i = 0;i<n;i++){
		int l = a[i].first, r = a[i].second;
		if(l == r && s.count(l) > 1){ 
			cout << 0;
			continue;
		}
		if(l == r && s.count(l) <= 1){ 
			cout << 1;
			continue;
		}

		auto it1 = s.lower_bound(l);
		auto it2 = s.upper_bound(r);

		if(s.size() !=0 && it1 == s.begin() && it2 == s.end() && s.size() >= r-l+1){ 
			cout << 0;
			continue;
		}

		cout << 1;
	}
	cout << '\n';

}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
