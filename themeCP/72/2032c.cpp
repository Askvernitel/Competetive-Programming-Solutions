#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	multiset<int> ms;
	for(int i =0;i<n;i++) {
		cin >> a[i];
		ms.insert(a[i]);
	}
	sort(a, a+n, greater<int>());
	int ans = INT_MAX;
	for(int i =0;i<n;i++){
	
		int l = -1, r =n;
		while(r - l > 1){
			int m = (r+l)/2;
			if(a[m] + a[m-1] > a[i]){
				l=m;
			}else{
				r=m;
			}
		}
		ans = min(ans, n-l -1+ i);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
