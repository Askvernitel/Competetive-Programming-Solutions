#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,m,sx,sy, d;

	cin >> n >> m >> sx >> sy >> d;


	bool left = 0, right = 0, up = 0, down = 0;

	if(sx-d > 1){ 
		left = 1;
	}
	if(sx+d < n){ 
		right = 1;	
	}
	if(sy+d < m){ 
		down = 1;
	}
	if(sy-d > 1) {
		up =1;
	}
	if((left && down) || (up && right)){ 
		cout << n+m-2;
	}else{ 
		cout << -1;
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
