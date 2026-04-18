#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	string s;
	cin >> s;
	char cur = '-';
	for(int i =1;i<n;i++){
		cout << cur;
		if(s[i] == '1'){ 
			if(cur == '+') cur = '-';
			else cur ='+';
		}
	}

	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
