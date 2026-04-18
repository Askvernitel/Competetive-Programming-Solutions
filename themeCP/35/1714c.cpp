#include <bits/stdc++.h>

using namespace std;
void solve(){
	int s;
	cin >> s;
	int cur = 9;
	string p = "";
	while(s > 0){ 
		if(s - cur >= 0){
			s-=cur;
			p.push_back(cur+48);
			
		}
		cur--;	
	}
	reverse(p.begin(),p.end());
	cout << p << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
