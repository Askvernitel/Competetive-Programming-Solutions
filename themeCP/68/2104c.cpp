#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;

	cin >> n;
	string s;
	cin >> s;

	if(s[0] == 'A' && s[n-1] == 'A'){
		cout << "Alice" << '\n';
	}else if(s[0] =='B' && s[n-1] == 'B'){
		cout << "Bob" << '\n';
	}else if(s[0] == 'B' && s[n-1] == 'A'){
		if(n > 2 && s[n-2] == 'A'){
			cout << "Alice" << '\n';
		}else{
			cout << "Bob" << '\n';
		}
	}else{
		if(n > 2){
			bool p = 0;
			for(int i = 1;i<n-1;i++){
				if(s[i] == 'B') p =1;
			}
			if(p) cout << "Bob" << '\n';
			else cout << "Alice" << '\n';
		}else{
			cout << "Alice" << '\n';
		}
	}
	
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
