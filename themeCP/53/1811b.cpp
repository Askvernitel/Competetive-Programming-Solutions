#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, x1,y1,x2,y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	int m = n/2;

	int p1 = min(min(x1,n-x1+1),min(n-y1+1,y1));
	int p2 = min(min(x2,n-x2+1),min(n-y2+1,y2));
	
	cout << abs(p1-p2) << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
