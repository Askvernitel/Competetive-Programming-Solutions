#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	int cur = a[0];	
	int ans =0;
	for(int i =0;i<n;i++){
		cur &= a[i];	
		if(cur == 0){
			ans++; 
			if(i+1<n) cur = a[i+1];
		}
	}
	cout << max(1,ans) << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
