#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n, m;

	cin >> n >> m;
	int a[n], b[m];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<m;i++){
		cin >> b[i];
	}

	sort(a, a+n);
	sort(b, b+m);
	
	int l=0,r=m-1;
	int l1=0,r1=n-1;
	int ans =0;

	while(l1 <=r1){ 
		int maxv = max({abs(a[l1]-b[r]), abs(b[l]-a[r1])});

		if(maxv == abs(a[l1]-b[r])){
			ans+=abs(a[l1]-b[r]);
			r--;
			l1++;
		}else{
			ans+=abs(b[l]-a[r1]);
			l++;
			r1--;
			
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;


	while(tc--) solve();
}
