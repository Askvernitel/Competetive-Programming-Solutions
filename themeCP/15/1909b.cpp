#include <bits/stdc++.h>
#include <climits>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	bool even =0,odd=0;
	int cnt =LLONG_MAX;
	for(int i =0;i<n;i++){
		if(a[i]%2) odd=1;
		else even = 1;
	}

	if(even && odd){
		cout << 2 << '\n';
		return;
	}
	for(int i =2;i<64;i++){
		int cur = pow(2, i);
		set<int> s;
		for(int j =0;j<n;j++){
			s.insert(a[j]%cur);
		}

		if(s.size() == 2){
			cout << cur << '\n'; 
			return;
		}
	}
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
