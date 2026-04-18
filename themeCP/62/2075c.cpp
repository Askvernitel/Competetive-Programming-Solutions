#include <bits/stdc++.h>
#define int long long

using namespace std;
int a[200001];

int n, m;
int bs(int x){
	int l=-1, r=m;
	while(r-l>1){ 
		int mid =(r+l)/2;
		if(n-x<=a[mid]){
			r=mid;
		}else{
			l=mid;
		}
	}
	return r;
}
void solve(){
	cin >> n >> m;
	for(int i =0;i<m;i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0;i<m;i++){
		a[i] = min(n-1, a[i]);
	}
	sort(a, a+m);
	int suf[m+1];
	suf[m] = 0;
	for(int i = m-1;i>=0;i--){
		suf[i] = suf[i+1]+a[i];
	}
	
	for(int i=0;i<m;i++){
		int idx = max(bs(a[i]), i+1);
		int c = m-idx;
		//cout << idx << '\n';
		ans+=(c*a[i]+suf[idx]+c-c*n)*2;
	}


	cout << ans<< '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
