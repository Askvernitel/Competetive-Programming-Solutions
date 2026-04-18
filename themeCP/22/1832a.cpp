#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;

	int n = s.size();

	if(n%2){ 
		char prev = s[0];
		int am =0;
		for(int i =1;i<n/2;i++){
			if(i == n/2) continue;
			if(prev != s[i]){
				am=1;
				break;
			}
		}
		if(!am){
			cout << "NO";
		}else{
			cout << "YES";
		}
	}else{
		char prev =s[0];
		int am = 0;
		for(int i =1;i<=n/2;i++){
			if(prev != s[i]) am=1;
		}
		if(!am){
			cout << "NO";
		}else{
			cout << "YES";
		}
	}
	cout << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
