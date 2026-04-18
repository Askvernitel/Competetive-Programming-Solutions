#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	int m = n-2;	
	int b[m];
	for(int i =1;i<n-1;i++){
		b[i-1] = max((int)0, max(a[i-1],a[i+1]) - a[i] + 1);
	}
	int c[(m+1)/2], d[m/2];
	for(int i =0,j=0;i<m;i+=2){
		c[j]=b[i];
		j++;
	}
	for(int i =1,j=0;i<m;i+=2){	
		d[j]=b[i];
		j++;
	}
	int ans = LLONG_MAX;

	int pref[(m+1)/2 +1];
	pref[0] = 0;
	for(int i =1;i<(m+1)/2 + 1;i++){
		pref[i] = pref[i-1] + c[i-1];
	}
	int suf[(m)/2+2];
	suf[m/2] = 0;
	suf[m/2+1]=0;
	for(int i =(m)/2-1;i>=0;i--){
		suf[i] = suf[i+1] + d[i];
	}
/*	for(int i =0;i<(m+1)/2+1;i++){
		cout << pref[i] << " " ;
	}
	cout << '\n';
	for(int i =(m)/2;i>=0;i--){
		cout << suf[i] << " ";
	}*/

	if(n%2){
		cout << pref[(m+1)/2] << '\n';
		return;
	}
	for(int i =0;i<=(m+1)/2;i++){
		ans = min(pref[i]+suf[i], ans);
	}
	cout << ans << '\n';


}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
