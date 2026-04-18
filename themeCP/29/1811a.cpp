#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, d;
	cin >> n  >> d;

	string s;
	cin >> s;

	bool found=0;
	for(int i =0;i<=n;i++){
		if((s[i]-48 < d || i==n) && !found){ 
			cout << d;
			found = 1;
		}
		if(i != n)
		cout << s[i];
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
