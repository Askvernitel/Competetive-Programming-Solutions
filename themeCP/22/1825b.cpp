#include <bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	int k = n*m;	
	int a[k];	
	for(int i =0;i<k;i++) cin >> a[i];
	sort(a, a+k);

	int p1=a[0];
	int p2=a[1];
	int p3=a[k-1];
	int p4=a[k-2];
	int ans = max({(p3-p1)*(n)*(m-1)+(p3-p2)*(n-1), (p3-p1)*(n-1)*m+(p3-p2)*(m-1),
		(p3-p1)*(n)*(m-1)+(p4-p1)*(n-1), (p3-p1)*(n-1)*m+(p4-p1)*(m-1)

	});
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
