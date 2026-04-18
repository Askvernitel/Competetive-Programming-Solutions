#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;

	int a[n], b[m];
	for(int i =0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	int u = 0;	
	for(int i =0;i<m;i++){
		u = u | b[i];
	}
	int k = 0;	
	for(int i =0;i<n;i++){
		k^=a[i];
	}

	if(n%2){
		int maxv = k|u;
		int minv = k;
		cout << minv << " " << maxv << '\n';
	}else{
		int maxv = k;
		int minv = (k^u) & k ;
		cout << minv << " " << maxv << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
