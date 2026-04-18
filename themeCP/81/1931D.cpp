#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
	int n, x, y;

	cin >> n >> x >> y;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	map<int, int> s1, s2, s3;
	map<int,vector<int>> b;
	int ans =0;
	for(int i =0;i<n;i++){
		b[a[i]%y].push_back(i);
	}
	for(auto &[c,d]:b){
		map<int,int> s;
		int p = 0;
		for(int e : d){ 
			p += s[(x-(a[e]%x))%x];
			s[a[e]%x]++;
		}
		ans += p;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
