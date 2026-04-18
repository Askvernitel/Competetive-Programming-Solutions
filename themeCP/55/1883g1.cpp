#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,m;
	cin >>n >> m;

	int a[n], b[n];
	a[0] =1;
	for(int i=1;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	multiset<int> b1;
	for(int i=0;i<n;i++){
		b1.insert(b[i]);	
	}
	sort(a, a+n);
	int p = n;
	for(int i =0;i<n;i++){
		auto it =b1.upper_bound(a[i]);
		if(it == b1.end()){
			p =i;
			break;
		}
		b1.erase(it);
	}
	cout << n - p << '\n';
}

int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
