#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100001], b[100001];
int n,w,h;
int f(int d){ 
	for(int i =0;i<n;i++){
		if(a[i]+d-w > b[i]-h){ 
			return 1;
		}
		if(a[i]+d+w < b[i]+h){ 
			return 0;
		}
	}
	return 2;	
}
void solve(){
	cin >> n >> w >> h;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];

	int l = -(1e9+1), r = 1e9+1;
	string ans = "NO\n";
	while(r-l > 1){
		int d = (r+l)/2;
		if(f(d) == 1){
			r = d;
		}else if(f(d) == 0){
			l = d;
		}else{
			ans="YES\n";
			break;
		}
	
	}
	cout << ans;
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
