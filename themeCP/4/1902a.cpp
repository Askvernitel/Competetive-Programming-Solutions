#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	char prev;
	cin >> prev;
	bool pos = 0;
	int cntz = 0, cnto=0;
	if(prev =='0') cntz++;
	else cnto++;
	for(int i =1;i<n;i++){
		char cur;
		cin >> cur;
		if(cur == '0') cntz++;
		if(cur == '1') cnto++;
		if(cur != prev){ 
			pos = 1;
		}
	}
	
	cout << ((pos || cntz > cnto)?"YES":"NO") << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
