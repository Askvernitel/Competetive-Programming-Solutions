#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;

	if(k > n+2){ 
		cout << 0 << '\n';
		return;
	}
	
	int f1=0, f2=1;
	for(int i = 2;i<k;i++){
		int tmp = f1;
		f1 = f2;
		f2 = f2+tmp;
	}
int ans =0;
	for(int i = 0;i<n;i++){
		if(i*f1 > n) break;
		if((n-(i*f1))%f2 == 0 && (n-(i*f1))/f2 >= i){ 
			ans++;
		}	
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
