#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	set<int> b;
	for(int i =0;i<n;i++){
		cin >> a[i];
		b.insert(a[i]);
	}	
	
	vector<int> b1, b2, b3;
	sort(a,a+n);
	b3.push_back(a[0]);
	b2.push_back(a[n-1]);
	for(int i =1;i<n-1;i++){
		b1.push_back(a[i]);
	}
	int ans = 0;
	while(!b1.empty()){
		ans = max(b2.back()-b3.back() + b2.back()-b1.back(), ans);

		b2.push_back(b1.back());
		b1.pop_back();
	}
	sort(a,a+n, greater<int>());
	b1 = {}; b2={}; b3 = {};
	b3.push_back(a[0]);
	b2.push_back(a[n-1]);
	for(int i =1;i<n-1;i++){
		b1.push_back(a[i]);
	}
	while(!b1.empty()){
		ans = max(abs(b2.back()-b3.back()) + abs(b2.back()-b1.back()), ans);

		b2.push_back(b1.back());
		b1.pop_back();
	}
	cout << ans << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
