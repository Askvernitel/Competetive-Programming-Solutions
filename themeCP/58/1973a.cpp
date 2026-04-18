#include <bits/stdc++.h>

using namespace std;
void solve(){
	int p1,p2,p3;
	cin >> p1 >> p2 >> p3;

	if((p1+p2+p3)%2){ 
		cout << -1 << '\n';
		return;
	}

	if(p3%2) swap(p1,p3);
	if(p3%2) swap(p2,p3);
	if(p1 < p2) swap(p1,p2);
	if(p1 < p3) swap(p1,p3);
	if(p2 < p3) swap(p2,p3);
	

	int k = max(p3+p2-p1, 0);
	int p = min(p1, p2+p3);
	cout << p + k/2 << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
