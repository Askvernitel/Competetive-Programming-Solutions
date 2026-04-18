#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >>n;
	int a[n], b[n];
	for(int i =0;i<n;i++) cin >> a[i];
	for(int i =0;i<n;i++) cin >> b[i];
	int times = 2;

	string ans = "Bob";
	while(times--){ 
		ans = "Bob";
		for(int i =0;i<n;i++){
			if(a[i] != b[i]){
				ans="Alice";
				break;
			}
		}
		if(ans == "Bob") break;
		reverse(a, a+n);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
