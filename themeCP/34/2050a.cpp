#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	string s[n];
	for(int i = 0;i<n;i++){
		cin >> s[i];
	}
	int x =0;	
	for(int i = 0;i<n;i++){
		if(m-(int)s[i].size() < 0){
			break;
		}else{
			x++;
			m-=(int)s[i].size();
		}
	}
	cout << x << '\n';

}
int main(){
	int tc;

	cin >> tc;

	while(tc--) solve();
}
