#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;

	cout << 1 << " " << 1 << " ";
	for(int i =2;i<n-1;i++){
		cout << i << " ";
	}
	cout << 1  << " ";
	cout << '\n';
}

int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
