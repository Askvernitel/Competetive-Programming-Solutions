#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;

	cin >> n >> k;
	int a[n];
	for(int i = 0;i<n;i++){
		char ch;
		cin >> ch;
		if(ch == '0'){ 
			a[i] = -1;
		}else{ 
			a[i] = 1;
		}
	}
	
	int pref[n+1];
	pref[0] = 0;
	for(int i = 1;i<n+1;i++){
		pref[i] = pref[i-1]+a[i-1];
	}
	int suf[n+1];
	suf[n] = 0;
	for(int i = n-1;i>=0;i--){
		suf[i] = suf[i+1] + a[i];
	}
	int ans = INT_MAX;
	for(int i = 1;i<=n;i++){
		int prev = 0, cof =0, am = 0;
		for(int j=i;j<n+1;j+=i){
			am += (pref[j]-prev)*cof;
			prev = pref[j];
			cof++;
			int v = am;
			if(j + i > n+1 && j != n){
				am += cof*(pref[n]-prev);	
			}
			if(v + suf[j]*cof >= k){ 
				ans = min(cof+1,ans);
			}
			
		}
		if(am >= k){
			ans = min(cof+1,ans);
		}
		am = 0; prev =0; int prev_sum = 0; cof = 0;
		for(int j=n-i;j>=0;j-=i){
			am+=(suf[j]-prev)+prev_sum;
			prev=suf[j];
			cof++;
			prev_sum=am;
			if(j - i < 0 && j != 0){ 
				am += (suf[0]-prev)+prev_sum;
			}
			if(am >= k){ 
				ans = min(cof+1,ans);
			}
		}
		if(am >= k){ 
			ans = min(cof+1,ans);
		}
		
	}
	if(ans == INT_MAX){ 
		ans = -1;
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
