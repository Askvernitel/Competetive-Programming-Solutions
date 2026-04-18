#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n+1];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	a[n]=0;
		

	int ans = a[0]+a[1];
	int tmp = 0;	

	for(int i =0;i<n;i++){
		tmp+=a[0];
		if(a[i] <= a[i+1]){ 
			ans = min(ans, tmp+a[0]);
		}else{
			ans = min(tmp+a[i+1],ans);
			break;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
