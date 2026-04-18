#include <bits/stdc++.h>

using namespace std;

int a[200001], h[200001];
int n, k;
bool good(int x){
	return x <= k ;
}
void solve(){
	cin >> n >> k;
	

	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> h[i];
	}

	int l = 0;
	int prev = -1;
	int ans = 0;
	int cur = 0;
	for(int r= 0;r<n;r++){
		cur += a[r];
		if(prev == -1){ 
			prev = h[r];
		}else if(prev%h[r]){	
			cur = a[r];
			l=r;
			prev = h[r];
		}else{ 
			prev = h[r];
		}
		while(!good(cur)){ 
			cur-=a[l++];
		}
		ans = max(r-l+1, ans);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
