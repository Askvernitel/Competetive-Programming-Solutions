#include <bits/stdc++.h>

using namespace std;

void solve(){
	int x, k;
	cin >> x >> k;
	if(x == 1 && k == 1){
		cout << "NO\n";
		return;
	}
	if(x == 1 && k == 2) {
		cout << "YES\n";
		return;
	}
	int found = 0;	
	for(int i=2;i*i<=x;i++){
		if(x%i == 0 && x != 2){
			found = 1;
			break;
		}
	}

	if(found){ 
		cout << "NO\n";
		return;
	}
	if(k > 1){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
