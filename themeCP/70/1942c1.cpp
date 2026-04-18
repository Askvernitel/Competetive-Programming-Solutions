#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	int a[x];
	for(int i =0;i<x;i++){
		cin >> a[i];
	}

	sort(a, a+x);


	int ans = x-2;
	for(int i =0;i<x-1;i++){
		if(a[i+1]-a[i] == 2){
			ans++;
		}
	}
	if(((n-a[x-1])+a[0]) == 2){
		ans++;
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
