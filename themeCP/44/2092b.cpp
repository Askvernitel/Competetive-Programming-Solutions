#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	string a,b;
	cin >> a >> b;

	int e=0, o=0;

	for(int i =0;i<n;i++){
		if(i%2 && a[i] == '1') o++;
		else if(a[i] == '1') e++;
	}

	for(int i =0;i<n;i++){
		if(i%2 && b[i] == '0') e--;
		else if(b[i] == '0') o--;
	}
	if(o <= 0 && e <= 0) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
