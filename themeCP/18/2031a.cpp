#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n+1];
	memset(a,0,sizeof(a));
	for(int i =0;i<n;i++){
		int num;
		cin >> num;
		a[num]++;
	}
	int ans = 0;
	for(int i =1;i<=n;i++){
		ans = max(a[i], ans);	
	}

	cout << n-ans << '\n';
	
} 
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
