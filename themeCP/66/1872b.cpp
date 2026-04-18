#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n ;
	cin >> n;
	int d[n], s[n];
	for(int i =0;i<n;i++){
		cin >> d[i] >> s[i];
	}
	int ans = 0;
	for(int k=0;k<500;k++){
		bool f=1;
		for(int j=0;j<n;j++){
			if(k >= d[j]){
				int t=2*(k-d[j]);
				if(t >= s[j]){
					f=0;
				}
			}
		}
		if(!f){
			break;
		}
		ans = k;
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
