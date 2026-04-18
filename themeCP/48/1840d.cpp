#include <bits/stdc++.h>
using namespace std;
int a[200003];
int n;
bool f(int k, int t){
	return (a[t]-a[k+1]+1)/2 >= (a[n-1]-a[t+1] + 1)/2;
}

void solve(){
	cin >> n;
	a[n] = INT_MAX;
	a[n+1] = INT_MAX;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int ans=INT_MAX;
	for(int i = 0;i<n;i++){
		int p = (a[i]-a[0]+1)/2;
		int l = i-1, r = n;
		/*for(int j=l;j<r;j++){
			/ans = min(ans, max({p,(a[j]-a[i+1]+1)/2,(a[n-1]-a[j+1] + 1)/2}));
		}*/
		/*
		int m = (l+r)/2;
		int first = 0, second = 0;
		for(int j = m;j >= 0 && j < n;){
			ans = min(ans, max({p,(a[j]-a[i+1]+1)/2,(a[n-1]-a[j+1] + 1)/2}));
			if((a[j]-a[i+1]+1)/2 >= (a[n-1]-a[j+1]+1)/2){
				if(second) break;
				j--;
				first = 1;
			}else{
				if(first) break;
				j++;
				second = 1;
			}
		}*/
		while(r-l>1){
			int m = (l+r)/2;
			ans = min(ans, max({p,(a[m]-a[i+1]+1)/2,(a[n-1]-a[m+1] + 1)/2}));
			if(f(i, m)){
				r=m;
			}else{
				l=m;
			}
		}
		ans = min(ans, max({p,(a[l]-a[i+1]+1)/2,(a[n-1]-a[l+1] + 1)/2}));
		ans = min(ans, max({p,(a[r]-a[i+1]+1)/2,(a[n-1]-a[r+1] + 1)/2}));
//		ans = min(ans, max({p,(a[r+1]-a[i+1]+1)/2,(a[n-1]-a[r+2] + 1)/2}));
//		ans = min(ans, max({p,(a[l-1]-a[i+1]+1)/2,(a[n-1]-a[l] + 1)/2}));
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
