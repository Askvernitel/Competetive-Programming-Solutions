#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k,x;
	cin >> n >> k >> x;
	int a[2*n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<n;i++){
		a[i+n]=a[i];
	}

	int pref[n+1];
	pref[0]=0;
	for(int i=1;i<=n;i++){
		pref[i] = pref[i-1]+a[i-1];
	}

	int sum=pref[n];
	int o = sum*k;
	
	int l = -1, r=k+1;
	while(r-l>1){ 
		int mid = (r+l)/2;
		if(sum*mid >= x){
			r=mid;
		}else{
			l=mid;
		}
	}
	int ss = r*sum;
	int t = 0;
	while(ss >=x){ss-=a[t++];}

	int p=n-t;
	if(t != 0) r--;
	int c=max((int)0,r*n);
	int ans = n*k-c-p;
	cout << max((int)0,ans) << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
