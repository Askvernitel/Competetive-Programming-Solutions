#include <bits/stdc++.h>

using namespace std;


int d(int x){
	int maxv=INT_MIN, minv = INT_MAX;
	while(x != 0){
		maxv = max(x%10, maxv);
		minv = min(x%10, minv);
		x/=10;
	}
	return maxv - minv;
}

void solve(){
	int l, r;
	cin >> l >> r;
	int ans = l, maxd=d(l);
	for(int i =l;i<=r;i++){
		if(d(i) > maxd){
			ans=i;
			maxd = d(i);
		}
		if(d(i) == 9) break;
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
