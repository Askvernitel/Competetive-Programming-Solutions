#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n, c, d;

	cin >> n >> c >> d;

	int a[n];
	map<int,int> m;
	int k= 0;
	
	for(int i =0;i<n;i++){
		cin >> a[i];
		if(m[a[i]] != 0) k+=c;
		else m[a[i]]++;
	}
	int z = m.size();
	int prev = 0;

	int cur = 0;
	int t = 0;
	int ans = LLONG_MAX;


	if(m.find(1) == m.end()){
		ans = min(ans,d+((z-t)*c));
	}else{ 
		ans = min(ans,((z-t-1)*c));
	}

	for(auto &[p, q]:m){
		t++;
		cur+=p-prev-1;
		ans = min(ans,(cur*d+((z-t)*c)));
		prev = p;
	}
	cout << ans+k<< '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
