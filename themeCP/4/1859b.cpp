#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a[n];
	int minv = INT_MAX;
	int sum =0;
	for(int i =0;i<n;i++){
		int m;
		cin >> m;
		for(int j = 0;j<m;j++){
			int num; cin >> num;
			a[i].push_back(num);
		}
		sort(a[i].begin(), a[i].end());
		minv = min(a[i][0], minv);
		sum+=a[i][1];
	}
	int ans = 0;
	for(int i =0;i<n;i++){
		ans=max(sum-a[i][1]+minv, ans);
	}
	cout << ans << '\n';

}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
