#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int s[n];
	for(int i =0;i<n;i++){
		cin >> s[i];
	}
	if(n == 1){ 
		cout << -1 << '\n';
		return;
	}
	int ans[n];
	for(int i=0;i<n;i++){
		ans[i] = i+1;
	}
	bool pos = 1;
	for(int i = 0;i<n;i++){
		int j=i+1;
		int cnt = 0;
		while(j<n && s[i] == s[j]){
			cnt++;
			swap(ans[i],ans[j]);
			j++;
		}
		if(cnt == 0){ 
			pos =0;
			break;
		}
		i=j-1;
	}
	if(!pos){
		cout << -1 << '\n';
		return;
	}
	for(int i =0;i<n;i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
