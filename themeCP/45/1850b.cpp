#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int maxv = 0;
	int idx = 0;
	for(int i = 0;i<n;i++){
		int num, c;
		cin >> num >> c;
		if(maxv < c && num <= 10){
			maxv = c;
			idx = i+1;
		}
	}
	cout << idx << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
	
}
