#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	int cnt[n];
	int maxv = 0;
	int idx =0;
	for(int i =0;i<n;i++){
		cin >> cnt[i];
		if(cnt[i] > maxv){ 
			maxv=cnt[i];
			idx = i;
		}
	}
	cout << idx+1 << '\n';


}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
