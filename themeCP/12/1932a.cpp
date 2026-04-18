#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >>n;
	int prev = 0;
	int ans = 0;
	int pos = 1;
	for(int i =0;i<n;i++){
		char cur;
		cin >> cur;
		if(cur == '*' && prev == 1){ 
			pos = 0;
		}
		else if(cur == '*'){
			prev = 1;
		}else if(pos){
			prev = 0;
			if(cur == '@')ans++;

		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
