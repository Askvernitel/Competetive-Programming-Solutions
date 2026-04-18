#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[10], b[10];

void solve(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<n;i++){
		cin >> b[i];
	}

	pair<int,int> w[n];
	for(int i=0;i<n;i++){
		w[i].first = a[i]+b[i]-1;
		w[i].second = i;
	}
	sort(w,w+n, greater<pair<int,int>>());
	int ans =0 ;
	for(int i =0;i<n;i++){
		if(!(i%2)){
			ans+=(a[w[i].second]-1);
		}else{
			ans-=(b[w[i].second]-1);
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
