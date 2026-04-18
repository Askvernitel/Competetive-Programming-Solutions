#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << '\n';
		return;
	}
	if(n%2){ 
		cout << -1 << '\n';
		return;
	}
	int mv = 0;	
	for(int i =n;i>=0;i--){
		
		if(!(mv%2)){ 
			if(i == 0) continue;
			cout << i << " ";
		}else{ 
			if(n-i == 0) continue;
			cout << n-i << " ";
		}
		mv++;
	}
	cout << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
