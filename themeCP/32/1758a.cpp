#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin >> s;

	int n = s.size();
	int m = 2*n;
	char arr[m];
	for(int i =0;i<n;i++){
		arr[i] = s[i];
		arr[m-i-1] = s[i];
	}
	for(int i =0;i<m;i++){
		cout << arr[i];
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
