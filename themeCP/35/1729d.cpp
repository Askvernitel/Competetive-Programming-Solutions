#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<n;i++){
		cin >> b[i];
	}

	int c[n];
	for(int i = 0;i<n;i++){
		c[i] = b[i]-a[i];
	}

	sort(c, c+n);

	int l =0, r =n-1;
	int ans =0;
	while(l < r){ 
		if(c[r] + c[l] >= 0){ 
			l++; r--;
			ans++;
		}else if(c[r] + c[l] <0){
			l++;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
