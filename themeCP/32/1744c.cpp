#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	char col;
	cin >> n >> col;
	string s;
	cin >> s;
	set<int>  green;
	for(int i =0;i<n;i++){
		if(s[i] == 'g'){green.insert(i); green.insert(n+i);}
	}
	int ans = 0;
	for(int i =0;i<n;i++){
		if(s[i] == col){ 
			ans = max(ans,(*green.lower_bound(i)-i));
		}
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
