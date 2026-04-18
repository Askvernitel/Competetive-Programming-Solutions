#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int h[n];

	for(int i =0;i<n;i++){
		cin >> h[i];
	}
	int ans = n;
	int cnt = 0;
	for(int i =0;i<n;i++){
		if(h[i] == 1) cnt++;
	}
	cout << ans-(cnt/2)<< '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
