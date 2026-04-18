#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n ;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	int sum =LLONG_MIN;	
	for(int i =0;i<n;i++){
		int cur1 =0, cur2 =0;
		for(int j =i;j<n;j++){
			cur1+=a[j];
			if(i != 0) cur2-=a[j];
		}
		
		sum = max(cur1,sum);
		if(i != 0) sum = max(cur2, sum);
		int tmp=a[i];
		for(int j = i;j<n-1;j++){
			int u = a[j+1];
			a[j+1] = a[j+1]-tmp;
			tmp = u;
		}

	}

	cout << sum << '\n';
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--) solve();
}
