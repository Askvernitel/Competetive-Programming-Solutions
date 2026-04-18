#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;

	cin >> s;
	int n = s.size();
	int sidx = 0;
	for(int i =0;i<n;i++){
		if(s[i] == '0'){ 
			sidx = i;
			break;
		}
	}
	int l1 = 1, r1 = n;
	int l2 = 1, r2 = 1;
	int m = n-sidx;
	string sn = s.substr(sidx, m);
	string maxs = string("0", m);
	for(int i =0;i<n-m;i++){
		string sp = "";
		string sc = s;
		for(int j =i;j<i+m;j++){
			sp+=s[j];	
		}
		for(int j=sidx;j<n;j++){
			if(sc[j]==sp[j-sidx]) sc[j] = '0';
			else sc[j] = '1';
		}
		if(sc > maxs){ 
			l2 = i+1;
			r2 = i+m;
			maxs = sc;
		}
	}

	cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
