#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	int l[n];
	for(int i =0;i<n;i++) cin >> l[i];
	sort(l, l+n, greater<int>());
	
	int ans = -1;
	for(int i =0;i<n;i++){
		if(i < l[i]) continue;
		bool pos = 1;
		for(int j = 0;j<i;j++){
			if(l[j] <= i){ 
				pos = 0;
				break;
			}
		}

		if(pos){
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
