#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	map<string, pair<int, map<int,int>>> m;
	int ans = 0;
	for(int i=0;i<n-2;i++){
		int p1 = a[i], p2=a[i+1], p3=a[i+2];
		
		ans+=(m[to_string(p1)+"#"+to_string(p2)+"#$"].first-m[to_string(p1)+"#"+to_string(p2)+"#$"].second[p3]);
		ans+=(m[to_string(p1)+"#"+ "$#" +to_string(p3)].first-m[to_string(p1)+"#"+to_string(p2)+"#$"].second[p3]);
		ans+=(m["$#"+to_string(p2)+"#"+to_string(p3)].first-m[to_string(p1)+"#"+to_string(p2)+"#$"].second[p3]);

		m[to_string(p1)+"#"+to_string(p2)+"#$"].first++;
		m[to_string(p1)+"#"+to_string(p2)+"#$"].second[p3]++;
		m[to_string(p1)+"#"+ "$#" +to_string(p3)].first++;
		m[to_string(p1)+"#"+ "$#" +to_string(p3)].second[p2]++;
		m["$#"+to_string(p2)+"#"+to_string(p3)].first++;
		m["$#"+to_string(p2)+"#"+to_string(p3)].second[p1]++;
	}
	cout << ans << '\n';
}

signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
