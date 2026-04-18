#include <bits/stdc++.h>

using namespace std;
void solve(){
	int a,b;

	cin >> a >> b;

	int xk, yk, xq, yq;
	
	cin >> xk >> yk >> xq >> yq;

	set<pair<int,int>> k, q;	
	

	for(int i = -1;i<=1;i++){
		if(i == 0) continue;
		for(int j = -1;j<=1;j++){
			if(j == 0) continue;

			k.insert({xk + i*a, yk + j*b});
			k.insert({xk + i*b, yk + j*a });
			q.insert({xq + i*a, yq + j*b});
			q.insert({xq + i*b, yq + j*a });
		}
	}
	int ans = 0;
	for(pair<int,int> c:q){ 
		if(k.find(c) != k.end()){
			ans++;
		}
	}
	cout << ans << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
