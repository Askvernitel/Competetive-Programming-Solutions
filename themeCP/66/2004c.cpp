#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;
	cin>> n >> k;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	sort(a, a+n,greater<int>());
	int tot=0;
	if(n%2){
		tot+=a[n-1];
	}
	for(int i =0;i<n-1;i+=2){
		if(a[i]-a[i+1] <=k){
			k-=a[i]-a[i+1];
		}else{
			tot+=((a[i]-a[i+1])-k);
			k=0;
		}
	}
	cout << tot << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
