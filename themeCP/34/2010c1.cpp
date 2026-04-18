#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;

	int n=s.size();
	bool pos = 0;
	string ans = "";
	for(int i=0;i<n;i++){
		string pref=s.substr(0, i);
		for(int j =0;j<i;j++){
			if(s.substr(j,n-j) == pref){ 
				ans = pref;
				pos = 1;
				break;
			}
		}
		if(pos) break;
	}
	if(!pos){ cout << "NO\n"; return 0; }
	cout << "YES\n";
	cout << ans << '\n';
}
