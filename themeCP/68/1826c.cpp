#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,m;
	cin >> n >>m;
	if(n > 1 && n <= m){
		cout << "NO\n";
		return;
	}
	for(int i =2;i*i<=n;i++){
		if(!(n%i)){
			if(i <=m){
				cout << "NO\n";
				return;
			}
			if(n/i != i && n/i <=m){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
