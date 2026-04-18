#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	multiset<int> ml;
	for(int i =0;i<n;i++){
		cin >> a[i];
		ml.insert(a[i]);
	}
	int ans = 0;
	for(int i = 0;i<=n;i++){
		multiset<int> mt = ml;
		int cur = i;
		int p =1;
		for(int j =0;j<i;j++){
			auto it1 = mt.upper_bound(cur);
			if(it1 == mt.begin()){
				p=0;
				break;
			}
			mt.erase(prev(it1));
			if(mt.size() != 0) mt.erase(mt.begin());
			cur--;
		}
		if(p) ans = i;
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
