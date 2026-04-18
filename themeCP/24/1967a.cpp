#include <bits/stdc++.h>
#include <cstring>
#define int long long
using namespace std;
int f(int k, int u){
	return k >= u;	
}
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n], b[n];	
	for(int i =0;i<n;i++) cin >> a[i];
	memcpy(b, a, sizeof(a))	;
	sort(a, a+n);
	int cur = 1;
	int ck = k;
	int minv = a[0];
	int idx = 0;
	for(int i=0;i<n-1;i++){
		int v = a[i+1]-a[i];	
		int u = v*cur;
		if(f(ck, u)){
			minv = a[i+1];
			ck-=u;
			idx = i;
		}else{ 
			int l = a[i], r=a[i+1];
			
			while(r-l>1){
				int m = (l+r)/2;
				if(f(ck,(m-a[i])*cur)){
					l = m;
				}else{
					r = m;
				}
			}
			ck-=(l-a[i])*cur;
			minv=l;
			idx=i;
			break;
		}
		cur++;
	}
	if(minv == a[n-1]){
		minv+=(ck/n);
		ck = ck%n;
	}

	int ans = (n)*(minv)-n + 1;
	for(int i =0;i<n;i++){
		if(b[i] - minv > 0){
			ans++;
		}else if(ck > 0){
			ans++;
			ck--;
		}
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
